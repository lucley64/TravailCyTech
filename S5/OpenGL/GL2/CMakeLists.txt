cmake_minimum_required(VERSION 3.30)
project(GL2)

set(CMAKE_CXX_STANDARD 26)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
if (NOT GLUT_FOUND)
    message(ERROR "Glut not found")
endif ()

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR "OPENGL not found!")
endif(NOT OPENGL_FOUND)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIR})
if(NOT GLEW_FOUND)
    message(ERROR "GLEW not found!")
endif (NOT GLEW_FOUND)

include_directories(libraries/include)

add_executable(GL2 main.cpp
        shader_class.cpp
        shader_class.h
        vao.cpp
        vao.h
        vbo.cpp
        vbo.h
        ebo.cpp
        ebo.h
        camera.cpp
        camera.h
        app.cpp
        app.h
)

target_link_libraries(GL2 ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})