cmake_minimum_required(VERSION 3.23)

project(SDLPlay)

add_executable (SDLPlay src/main.c)

find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(SDLPlay PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
