/**
 * TemplateProcessor - The big dude on campus
 *
 * @author    Jonathan Roewen
 */
#ifndef TEMPLATE_PROCESSOR_H
#define TEMPLATE_PROCESSOR_H

#include "AimlProcessor.h"

#include "../Responder.h"

#include <map>

class TemplateProcessor : public AimlProcessor
{
public:
    ~TemplateProcessor();
    
    string getName() const;
    string getVersion() const;
    string process(Match *, PElement, Responder *, const string &);
    static void addProcessor(AimlProcessor *);
    static AimlProcessor *getProcessor(const string &name);
    static string processTemplate(Match *, PElement, Responder *, const string &id);
private:
    static map<string, AimlProcessor *> processors;
    static AimlProcessor *hook;
};

#endif
