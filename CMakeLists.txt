cmake_minimum_required(VERSION 3.10)

project(Dead-Soals)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(SOURCE_FILES 
src/main.cpp
src/utils.cpp
src/models/Player.cpp
src/controllers/Game.cpp
src/visuals/Renderer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
