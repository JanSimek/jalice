cmake_minimum_required(VERSION 2.8)

project(jalice)

#file(GLOB_RECURSE SOURCES "src/*.cpp")
#file(GLOB_RECURSE HEADERS "src/*.h")

set(SOURCES
    src/AimlWriter.cpp
    src/Database.cpp
    src/Element.cpp
    src/FlashResponder.cpp
    src/HTTPProcessor.cpp
    src/Handler.cpp
    src/IrcResponder.cpp
    src/Kernel.cpp
    src/Logger.cpp
    src/Main.cpp
    src/Match.cpp
    src/Memory.cpp
    src/Nodemaster.cpp
    src/Parser.cpp
    src/PreParser.cpp
    src/ServerSocket.cpp
    src/Socket.cpp
    src/SocketHandler.cpp
    src/StringTokenizer.cpp
    src/Substituter.cpp
    src/Template.cpp
    src/TemplateProcessor.cpp
    src/TokenProxyListener.cpp
    src/Utils.cpp
    src/XmlSocketResponder.cpp
)

set(HEADERS
    src/AimlProcessor.h
    src/AimlWriter.h
    src/BotProcessor.h
    src/BrProcessor.h
    src/Compat.h
    src/ConditionProcessor.h
    src/Database.h
    src/Element.h
    src/FlashResponder.h
    src/FormalProcessor.h
    src/GetProcessor.h
    src/HTTPProcessor.h
    src/Handler.h
    src/IdProcessor.h
    src/InputProcessor.h
    src/IrcProcessor.h
    src/IrcResponder.h
    src/JavaScriptProcessor.h
    src/Kernel.h
    src/LearnProcessor.h
    src/Logger.h
    src/LowercaseProcessor.h
    src/Match.h
    src/Memory.h
    src/NameProcessor.h
    src/Nodemapper.h
    src/Nodemaster.h
    src/NormalizeProcessor.h
    src/Parser.h
    src/PersonProcessor.h
    src/Pointer.h
    src/PreParser.h
    src/RandomProcessor.h
    src/Responder.h
    src/SecureProcessor.h
    src/SentenceProcessor.h
    src/ServerSocket.h
    src/SetProcessor.h
    src/Socket.h
    src/SocketHandler.h
    src/SrProcessor.h
    src/SraiProcessor.h
    src/StarProcessor.h
    src/StringTokenizer.h
    src/Substituter.h
    src/Template.h
    src/TemplateProcessor.h
    src/ThatProcessor.h
    src/ThatstarProcessor.h
    src/ThinkProcessor.h
    src/TokenProxyListener.h
    src/TopicstarProcessor.h
    src/UppercaseProcessor.h
    src/Utils.h
    src/XmlSocketResponder.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
