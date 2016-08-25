/**
 * Handler - Solution for no dynamic loading
 *
 * @author    Jonathan Roewen
 */
#include "Handler.h"

#include "Match.h"
#include "Responder.h"
#include "TemplateProcessor.h"
#include "BrProcessor.h"
#include "IdProcessor.h"
#include "SrProcessor.h"
#include "BotProcessor.h"
#include "GetProcessor.h"
#include "SetProcessor.h"
#include "NameProcessor.h"
#include "SraiProcessor.h"
#include "StarProcessor.h"
#include "ThatProcessor.h"
#include "InputProcessor.h"
#include "LearnProcessor.h"
#include "ThinkProcessor.h"
#include "FormalProcessor.h"
#include "PersonProcessor.h"    //    + Person2 and Gender
#include "RandomProcessor.h"
#include "SentenceProcessor.h"
#include "ThatstarProcessor.h"
#include "ConditionProcessor.h"
#include "LowercaseProcessor.h"
#include "NormalizeProcessor.h"
#include "TopicstarProcessor.h"
#include "UppercaseProcessor.h"
#include "SecureProcessor.h"    //    Contains AuthenticateProcessor too

map<string, AimlProcessor *> Handler::processors;

void Handler::init() {
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

bool Handler::hasProcessor(const string &name) {
    return processors.find(name) != processors.end();
}
