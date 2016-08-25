cmake_minimum_required(VERSION 2.8)

project(jalice)

#file(GLOB_RECURSE SOURCES "src/*.cpp")
#file(GLOB_RECURSE HEADERS "src/*.h")

set(SOURCES
    src/Main.cpp

    src/AimlWriter.cpp
    src/AimlWriter.h
    src/Database.cpp
    src/Database.h
    src/Compat.h
    src/Element.cpp
    src/Element.h
    src/Handler.cpp
    src/Handler.h
    src/Kernel.cpp
    src/Kernel.h
    src/Logger.cpp
    src/Logger.h
    src/Match.cpp
    src/Match.h
    src/Memory.cpp
    src/Memory.h
    src/Nodemaster.cpp
    src/Nodemaster.h
    src/Nodemapper.h
    src/Parser.cpp
    src/Parser.h
    src/Pointer.h
    src/PreParser.cpp
    src/PreParser.h
    src/Responder.h
    src/StringTokenizer.cpp
    src/StringTokenizer.h
    src/Substituter.cpp
    src/Substituter.h
    src/Template.cpp
    src/Template.h
    src/Utils.cpp
    src/Utils.h

    src/TemplateProcessor.cpp
    src/TemplateProcessor.h
    src/AimlProcessor.h
    src/BotProcessor.h
    src/BrProcessor.h
    src/ConditionProcessor.h
    src/FormalProcessor.h
    src/GetProcessor.h
    src/IdProcessor.h
    src/InputProcessor.h
    src/LearnProcessor.h
    src/LowercaseProcessor.h
    src/NameProcessor.h
    src/NormalizeProcessor.h
    src/PersonProcessor.h
    src/RandomProcessor.h
    src/SecureProcessor.h
    src/SentenceProcessor.h
    src/SetProcessor.h
    src/SrProcessor.h
    src/SraiProcessor.h
    src/StarProcessor.h
    src/ThatProcessor.h
    src/ThatstarProcessor.h
    src/ThinkProcessor.h
    src/TopicstarProcessor.h
    src/UppercaseProcessor.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
