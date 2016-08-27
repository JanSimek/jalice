/**
 * ConditionProcessor - Conditional selection of choices
 *
 * @author    Jonathan Roewen
 */
#ifndef CONDITION_PROCESSOR_H
#define CONDITION_PROCESSOR_H

#include "AimlProcessor.h"

#include "../Memory.h"

class ConditionProcessor : public AimlProcessor
{
 public:
  ~ConditionProcessor() {}
  string getName() const { return "condition"; }
  string getVersion() const { return "1.0"; }
  string process(Match *m, PElement e, Responder *r, const string &id)
  {
    string cond = e->getAttribute("name", m, id);
    if (cond.empty())
    {
      cond = e->getAttribute("data", m, id);
    }
    if (cond.empty())
    {
      return "";
    }
    string value = e->getAttribute("value", m, id);

    velement li, random;
    e->getChildren("li", &li);
    for (velement_it ix = li.begin(); ix != li.end(); ++ix)
    {
      string c = (*ix)->getAttribute("name", m, id);
      if (c.empty())
      {
        c = (*ix)->getAttribute("data", m, id);
      }
      if (c.empty())
      {
        c = cond;
      }
      string v = (*ix)->getAttribute("value", m, id);
      string ct = (*ix)->getAttribute("contains", m, id);
      string bw = (*ix)->getAttribute("beginswith", m, id);
      string ew = (*ix)->getAttribute("endswith", m, id);
      string mem = Memory::getValue(c, id);
      if (!v.empty())
      {
        if (v == mem)
        {
          return Kernel::process(m, *ix, r, id);
        }
      }
      if (!ct.empty())
      {
        if (mem.find(ct) != string::npos)
        {
          return Kernel::process(m, *ix, r, id);
        }
      }
      if (!bw.empty())
      {
        if (mem.find(bw) == 0)
        {
          return Kernel::process(m, *ix, r, id);
        }
      }
      if (!ew.empty())
      {
        if (mem.length() >= ew.length() && mem.rfind(ew) == mem.length() - ew.length())
        {
          return Kernel::process(m, *ix, r, id);
        }
      }
      // if there are one or more <li> without condition, choose a random one
      if (ct.empty() && v.empty() && bw.empty() && ew.empty())
      {
        // return Kernel::process(m, *ix, r, id);
        random.push_back(*ix);
      }
    }

    /*
     * <condition name="age">
     *     <li value="27">Most people die at 27, we just bury them at 72. Mark Twain said that.</li>
     *     <li>Only <star/>? You are quite mature.</li>
     *     <li>You are too old for me.</li>
     *     <li>Can you explain how it feels to be <star/> years old?</li>
     * </condition>
     */
    if (!random.empty())
    {
      // TODO: use RandomProcessor()
      int chosen = rand() % random.size();

      velement_it ix;
      int i = 0;
      for (ix = random.begin(); i < chosen; i++) ix++;
      PElement ele = *ix;

      return Kernel::process(m, ele, r, id);
    }

    if (!cond.empty() && !value.empty())
    {
      string mem = Memory::getValue(cond, id);
      if (value == mem)
      {
        return Kernel::process(m, e, r, id);
      }
    }
    return "";
  }
};

#endif
