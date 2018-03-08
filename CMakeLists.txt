cmake_minimum_required (VERSION 3.0)
project (OGAL)

file (GLOB LIB_SRC "lib/src/*.cpp" "lib/src/*/*.cpp" "lib/include/OGAL/*.hpp" "lib/include/OGAL/*/*.hpp" "lib/include/OGAL/*.h")

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

add_executable (OGAL_DEMO "test/src/main.cpp")
target_link_libraries (OGAL_DEMO OGAL)

if (WIN32)
	target_link_libraries (OGAL glfw3)
	target_link_libraries (OGAL_DEMO glfw3)
else ()
	target_link_libraries (OGAL glfw)
	target_link_libraries (OGAL_DEMO glfw)
endif (WIN32)

install (TARGETS OGAL DESTINATION "lib/")
install (DIRECTORY lib/include/ DESTINATION "include/")