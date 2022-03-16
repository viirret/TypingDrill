cmake_minimum_required(VERSION 3.21)
project(ProTyper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug) # debug mode
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
add_executable(ProTyper
	FontLoader.cc
	main.cc
	Renderer.cc
	TextMaker.cc
	Texture.cc
	Window.cc
	)

target_link_libraries(ProTyper ${SDL2_LIBRARIES} -lSDL2_image -lSDL2_ttf)
