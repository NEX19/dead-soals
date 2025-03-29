cmake_minimum_required(VERSION 3.10)

project(Dead-Soals)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
