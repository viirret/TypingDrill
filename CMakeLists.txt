cmake_minimum_required(VERSION 3.21)
project(TypingDrill)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
add_executable(TypingDrill src/FontLoader.cc src/main.cc src/Renderer.cc src/Texture.cc src/Window.cc src/Game.cc src/ScreenSize.cc src/Word.cc)

target_link_libraries(TypingDrill ${SDL2_LIBRARIES} -lSDL2_ttf)
