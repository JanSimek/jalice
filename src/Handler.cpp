/**
 * Handler - Solution for no dynamic loading
 *
 * @author    Jonathan Roewen
 */
#include "Handler.h"

#include "Match.h"
#include "Responder.h"

#include "processor/BotProcessor.h"
#include "processor/BrProcessor.h"
#include "processor/ConditionProcessor.h"
#include "processor/FormalProcessor.h"
#include "processor/GetProcessor.h"
#include "processor/IdProcessor.h"
#include "processor/InputProcessor.h"
#include "processor/LearnProcessor.h"
#include "processor/LowercaseProcessor.h"
#include "processor/NameProcessor.h"
#include "processor/NormalizeProcessor.h"
#include "processor/PersonProcessor.h"  //    + Person2 and Gender
#include "processor/RandomProcessor.h"
#include "processor/SecureProcessor.h"  //    Contains AuthenticateProcessor too
#include "processor/SentenceProcessor.h"
#include "processor/SetProcessor.h"
#include "processor/SrProcessor.h"
#include "processor/SraiProcessor.h"
#include "processor/StarProcessor.h"
#include "processor/TemplateProcessor.h"
#include "processor/ThatProcessor.h"
#include "processor/ThatstarProcessor.h"
#include "processor/ThinkProcessor.h"
#include "processor/TopicstarProcessor.h"
#include "processor/UppercaseProcessor.h"

map<string, AimlProcessor *> Handler::processors;

void Handler::init()
{
  processors["br"] = new BrProcessor();
  processors["id"] = new IdProcessor();
  processors["sr"] = new SrProcessor();
  processors["bot"] = new BotProcessor();
  processors["get"] = new GetProcessor();
  processors["set"] = new SetProcessor();
  processors["name"] = new NameProcessor();
  processors["srai"] = new SraiProcessor();
  processors["star"] = new StarProcessor();
  processors["that"] = new ThatProcessor();
  processors["input"] = new InputProcessor();
  processors["learn"] = new LearnProcessor();
  processors["think"] = new ThinkProcessor();
  processors["formal"] = new FormalProcessor();
  processors["person"] = new PersonProcessor();
  processors["random"] = new RandomProcessor();
  processors["sentence"] = new SentenceProcessor();
  processors["thatstar"] = new ThatstarProcessor();
  processors["condition"] = new ConditionProcessor();
  processors["lowercase"] = new LowercaseProcessor();
  processors["normalize"] = new NormalizeProcessor();
  processors["topicstar"] = new TopicstarProcessor();
  processors["uppercase"] = new UppercaseProcessor();
  processors["template"] = new TemplateProcessor();
  processors["secure"] = new SecureProcessor();
  processors["authenticate"] = new AuthenticateProcessor();

  processors["person2"] = new Person2Processor();
  processors["gender"] = new GenderProcessor();
}

bool Handler::hasProcessor(const string &name) { return processors.find(name) != processors.end(); }
