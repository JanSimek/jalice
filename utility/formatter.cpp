

#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <tinyxml2.h>

using namespace tinyxml2;

class AIMLPrinter
{
 public:
  AIMLPrinter(const char *inputFile, std::string outputFile = "", char indenter = ' ', int indentBy = 4)
      : outputFile(outputFile), indenter(indenter), indentBy(indentBy)
  {
    this->inputFile.LoadFile(inputFile);
    this->Show();
  }

  std::string getElementName(XMLElement *element) { return std::string(element->Name()); }
  void Show()
  {
    XMLNode *node = inputFile.FirstChild();
    XMLElement *root;

    std::cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

    while (node != nullptr)
    {
      if (node->ToComment())
      {
        // std::cout << node->ToComment()->Value() << std::endl;
        insertComment(node->ToComment()->Value());
      }
      else if (node->ToElement())
      {
        if (getElementName(node->ToElement()) == "aiml")
        {
          root = node->ToElement();
          break;
        }
        else
        {
          std::cerr << "ERROR: Unrecognized element: " << node->ToElement()->Name() << std::endl;
          return;
        }
      }
      node = node->NextSibling();
    }

    std::cout << std::endl;
    openElement("aiml");

    XMLNode *n = root->FirstChild();

    while (n != nullptr)
    {
      currentIndentation = indentBy;

      if (n->ToElement())
      {
        XMLElement *e = n->ToElement();
        if (getElementName(e) == "category")
        {
          openElement("category", currentIndentation);

          currentIndentation = indentBy * 2;

          // FIXME: check for comments
          printChildElements(e->FirstChildElement("pattern"));
          // printChildElements(e->FirstChildElement("that"));
          printChildElements(e->FirstChildElement("template"));

          closeElement(true);  // category
        }
      }
      else if (n->ToComment())
      {
        insertComment(n->ToComment()->Value());
        // std::cout << std::endl << "<!-- " << n->ToComment()->Value() << " -->" << std::endl;
      }

      n = n->NextSibling();
    }

    std::cout << std::endl;  // FIXME: ?
    closeElement();          // aiml
  }

  std::string quote(std::string text) { return "\"" + text + "\""; }
  std::string trimspace(std::string str)
  {
    bool prev = false;

    auto iter = std::remove_if(str.begin(), str.end(), [&](char c) -> bool {
      if (c == '\n' || c == '\t')
      {
        // prev = true;
        return true;
      }
      if (isspace(c) && prev)
      {
        return true;
      }
      prev = isspace(c);
      return false;
    });
    str.erase(iter, str.end());
    return str;
  }

  void indent(int i) { std::cout << std::string(i, indenter); }
  void closeElementIfOpen()
  {
    if (elementJustInserted)
    {
      std::cout << ">";
      elementJustInserted = false;
    }
  }

  void openElement(std::string name, int indentBy = 0)
  {
    closeElementIfOpen();
    elementJustInserted = true;
    if (indentBy > 0)
    {
      std::cout << std::endl;
    }
    indent(indentBy);
    std::cout << "<" << name;

    elementstack.push(std::make_pair(name, indentBy));
  }

  void insertText(std::string text)
  {
    closeElementIfOpen();
    std::cout << text;
  }

  void insertComment(std::string text)
  {
    closeElementIfOpen();
    std::cout << std::endl;

    // FIXME: this is wrong
    if (!elementstack.empty() && (elementstack.top().first == "template" || elementstack.top().first == "category"))
    {
      indent(elementstack.top().second + indentBy);
    }
    else
    {
      indent(itemIndentation);
    }
    std::cout << "<!-- " << text << " -->";
  }

  void closeElement(bool newline = false)
  {
    if (elementJustInserted)
    {
      std::cout << " />";
      elementJustInserted = false;
    }
    else
    {
      if (newline)
      {
        std::cout << std::endl;
        indent(elementstack.top().second);
      }
      std::cout << "</" << elementstack.top().first << ">";
    }
    elementstack.pop();

    if (elementstack.empty()) std::cout << std::endl;
  }

  void printChildElements(XMLNode *node)
  {
    bool onnewline = false;
    std::string name = node->ToElement()->Name();

    if (name == "random" || name == "condition")
    {
      onnewline = true;
      itemIndentation = currentIndentation + indentBy;
    }
    else if (name == "li")
    {
      itemIndentation = currentIndentation + indentBy * 2;
    }
    else if (name == "pattern" || name == "template")
    {
      itemIndentation = currentIndentation;

      // check if there are any elements that break lines
      XMLNode *child = node->FirstChild();
      while (child != nullptr)
      {
        if (child->ToElement())
        {
          std::string childname = child->ToElement()->Name();
          if (childname == "random" || childname == "condition")
          {
            onnewline = true;
            break;
          }
        }
        child = child->NextSibling();
      }
    }
    else
    {
      itemIndentation = 0;
    }

    openElement(name, itemIndentation);

    std::vector<std::string> validAttributes;
    validAttributes.push_back("index");
    validAttributes.push_back("value");
    validAttributes.push_back("name");

    for (auto attribute : validAttributes)
    {
      if (node->ToElement()->Attribute(attribute.c_str()))
      {
        std::cout << " " << attribute << "=\"" << node->ToElement()->Attribute(attribute.c_str()) << "\"";
      }
    }

    XMLNode *e = node->FirstChild();
    while (e != nullptr)
    {
      if (e->ToText())
      {
        insertText(trimspace(e->ToText()->Value()));
      }
      else if (e->ToElement())
      {
        printChildElements(e->ToElement());
      }
      else if (e->ToComment())
      {
        insertComment(e->ToComment()->Value());
      }

      e = e->NextSibling();
    }

    closeElement(onnewline);
  }

 private:
  tinyxml2::XMLDocument inputFile;
  std::string outputFile;

  std::stack<std::pair<std::string, int> > elementstack;

  char indenter;
  int indentBy;
  int currentIndentation;
  int itemIndentation = 0;
  bool elementJustInserted = false;
};

int main(int argc, char *argv[])
{
  AIMLPrinter printer("test.xml");

  return 0;
}
