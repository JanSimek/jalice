/**
 * UppercaseProcessor - Transforms output to uppercase
 *
 * @author    Jonathan Roewen
 */
#ifndef UPPERCASE_PROCESSOR_H
#define UPPERCASE_PROCESSOR_H

#include "AimlProcessor.h"

#include "../Utils.h"

class UppercaseProcessor : public AimlProcessor
{
 public:
  ~UppercaseProcessor() {}
  string getName() const { return "uppercase"; }
  string getVersion() const { return "1.0"; }
  string process(Match *m, PElement e, Responder *r, const string &id)
  {
    string result = Kernel::process(m, e, r, id);
    return toUpper(result);
  }
};

#endif
