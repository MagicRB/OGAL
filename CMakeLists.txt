cmake_minimum_required(VERSION 2.8.9)
project(OGAL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

link_directories(link)

if(WIN32)
	include_directories(include_win32)
	link_directories(link_win32)
endif(WIN32)

file(GLOB SOURCES "src/*.cpp" "include/*.h" "include/*.hpp" "src/shapes/*.cpp" "include/shapes/*.hpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../run)

add_executable(OGLAL ${SOURCES})

if(WIN32)
	target_link_libraries(OGLAL )
elseif(UNIX)
	target_link_libraries(OGLAL glfw GL GLEW)
endif(WIN32)
