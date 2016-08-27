/**
 * SentenceProcessor - Capitalises first character
 *
 * @author    Jonathan Roewen
 */
#ifndef SENTENCE_PROCESSOR_H
#define SENTENCE_PROCESSOR_H

#include "AimlProcessor.h"

#include <cctype>

class SentenceProcessor : public AimlProcessor
{
 public:
  ~SentenceProcessor() {}
  string getName() const { return "sentence"; }
  string getVersion() const { return "1.0"; }
  string process(Match *m, PElement e, Responder *r, const string &id)
  {
    string result = Kernel::process(m, e, r, id);
    result[0] = toupper(result[0]);
    return result;
  }
};

#endif
