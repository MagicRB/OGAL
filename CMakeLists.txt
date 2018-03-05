cmake_minimum_required (VERSION 3.0)
project (OGAL)

file (GLOB LIB_SRC "lib/src/*.cpp" "lib/src/*/*.cpp")

add_library (OGAL SHARED ${LIB_SRC})

target_include_directories (OGAL PUBLIC "lib/include")

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
	target_include_directories (OGAL PRIVATE ${GLEW_INCLUDE_DIRS})
	target_link_libraries (OGAL ${GLEW_LIBRARIES})
endif(GLEW_FOUND)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	target_include_directories (OGAL PRIVATE ${OPENGL_INCLUDE_DIRS})
	target_link_libraries (OGAL ${OPENGL_LIBRARIES})
endif(OPENGL_FOUND)

if (BUILD_TEST)
	add_executable (OGAL_DEMO "test/src/main.cpp")
	target_link_libraries (OGAL_DEMO OGAL)
endif (BUILD_TEST)

find_package(glfw3 REQUIRED)

if (glfw3_FOUND)
	target_link_libraries (OGAL glfw)
	if (BUILD_TEST)
		target_link_libraries (OGAL_DEMO glfw)
	endif (BUILD_TEST)
endif(glfw3_FOUND)

install (TARGETS OGAL DESTINATION "lib/")
install (DIRECTORY lib/include/ DESTINATION "include/")