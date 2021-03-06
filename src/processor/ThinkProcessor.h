/**
 * ThinkProcessor - Processes AIML without displaying results
 *
 * @author    Jonathan Roewen
 */
#ifndef THINK_PROCESSOR_H
#define THINK_PROCESSOR_H

#include "AimlProcessor.h"

class ThinkProcessor : public AimlProcessor
{
 public:
  ~ThinkProcessor() {}
  string getName() const { return "think"; }
  string getVersion() const { return "1.0"; }
  string process(Match *m, PElement e, Responder *r, const string &id)
  {
    Kernel::process(m, e, r, id);
    return "";
  }
};

#endif
