cmake_minimum_required(VERSION 3.0.0)
project(simple_notepad VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(simple_notepad simple_notepad.cpp journal.cpp persistance_manager.cpp memento.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
