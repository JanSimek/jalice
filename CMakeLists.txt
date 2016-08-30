cmake_minimum_required(VERSION 2.8)

project(jalice)

set(JALICE_SOURCES
    src/AimlWriter.cpp
    src/AimlWriter.h
    src/Database.cpp
    src/Database.h
    src/Element.cpp
    src/Element.h
    src/Handler.cpp
    src/Handler.h
    src/Kernel.cpp
    src/Kernel.h
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

    src/processor/TemplateProcessor.cpp
    src/processor/TemplateProcessor.h
    src/processor/AimlProcessor.h
    src/processor/BotProcessor.h
    src/processor/BrProcessor.h
    src/processor/ConditionProcessor.h
    src/processor/FormalProcessor.h
    src/processor/GetProcessor.h
    src/processor/IdProcessor.h
    src/processor/InputProcessor.h
    src/processor/LearnProcessor.h
    src/processor/LowercaseProcessor.h
    src/processor/NameProcessor.h
    src/processor/NormalizeProcessor.h
    src/processor/PersonProcessor.h
    src/processor/RandomProcessor.h
    src/processor/SentenceProcessor.h
    src/processor/SetProcessor.h
    src/processor/SrProcessor.h
    src/processor/SraiProcessor.h
    src/processor/StarProcessor.h
    src/processor/ThatProcessor.h
    src/processor/ThatstarProcessor.h
    src/processor/ThinkProcessor.h
    src/processor/TopicstarProcessor.h
    src/processor/UppercaseProcessor.h
)

add_library(${PROJECT_NAME} ${JALICE_SOURCES})

add_executable(${PROJECT_NAME}_console clients/console/main.cpp)
target_link_libraries(${PROJECT_NAME}_console ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_xmpp clients/xmpp/main.cpp)
target_link_libraries(${PROJECT_NAME}_xmpp ${PROJECT_NAME})

execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/startup.aiml ${CMAKE_BINARY_DIR}/startup.aiml)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/src/aiml ${CMAKE_BINARY_DIR}/aiml)
