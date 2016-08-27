/**
 * LowercaseProcessor - Transforms output to lowercase
 *
 * @author    Jonathan Roewen
 */
#ifndef LOWERCASE_PROCESSOR_H
#define LOWERCASE_PROCESSOR_H

#include "AimlProcessor.h"

class LowercaseProcessor : public AimlProcessor
{
 public:
  ~LowercaseProcessor() {}
  string getName() const { return "lowercase"; }
  string getVersion() const { return "1.0"; }
  string process(Match *m, PElement e, Responder *r, const string &id)
  {
    string result = Kernel::process(m, e, r, id);
    return toLower(result);
  }
};

#endif
