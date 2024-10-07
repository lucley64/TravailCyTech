//
// Created by cytech on 24/09/24.
//

#ifndef GL2_APP_H
#define GL2_APP_H

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <vector>
#include "shader_class.h"
#include "vao.h"
#include "ebo.h"
#include "glm/vec4.hpp"
#include <array>
#include <memory>
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"

namespace gl2 {

    class app {
    private:
        const char *TITLE = "Hello OpenGL!";
        static int width;
        static int height;
        static glm::vec4 rotation;
        const std::array<glm::vec4, 8> vertices{{
                                                        {-0.5f, -0.5f, 0.5f, 1.0f},
                                                        {-0.5f, 0.5f, 0.5f, 1.0f},
                                                        {0.5f, 0.5f, 0.5f, 1.0f},
                                                        {0.5f, -0.5f, 0.5f, 1.0f},
                                                        {-0.5f, -0.5f, -0.5f, 1.0f},
                                                        {-0.5f, 0.5f, -0.5f, 1.0f},
                                                        {0.5f, 0.5f, -0.5f, 1.0f},
                                                        {0.5f, -0.5f, -0.5f, 1.0f},
                                                }};
        const std::array<glm::vec4, 8> colors{{
                                                      {1.0f, 0.0f, 0.0f, 1.0f},
                                                      {1.0f, 1.0f, 0.0f, 1.0f},
                                                      {0.0f, 1.0f, 0.0f, 1.0f},
                                                      {0.0f, 0.0f, 1.0f, 1.0f},
                                                      {1.0f, 0.0f, 1.0f, 1.0f},
                                                      {0.0f, 1.0f, 1.0f, 1.0f},
                                                      {0.0f, 0.0f, 0.0f, 1.0f},
                                                      {1.0f, 1.0f, 1.0f, 1.0f},
                                              }};

        static std::unique_ptr<gl2::vao> vaoCube;
        std::unique_ptr<gl2::vbo> vboCube;
        std::unique_ptr<gl2::vbo> vboInterlacedCube;
        std::unique_ptr<gl2::vbo> vboOctahedronPositions;
        std::unique_ptr<gl2::vbo> vboOctahedronColors;
        static std::unique_ptr<gl2::shader_class> passthrough;


        static std::vector<glm::vec4> vPositionsColorCube;
        std::vector<glm::vec4> vColorsColorCube;
        static std::vector<glm::vec4> vPositionsInterlacedCube;

        static void displayFunc();

        static void keyboard(unsigned char key, int x, int y);


        void colorCube();

        static void updateMVP(glm::vec3 translation);

        static void reshapeFunc(int newWidth, int newHeight);

    public:
        void init(int argc, char **argv);

        void start();

        ~app();

        static void motionFunc(int x, int y);

        void interlacedCube();

        static std::unique_ptr<gl2::vao> vaoInterlacedCube;
        static std::unique_ptr<gl2::vao> vaoOctahedron;

        void octahedron();

        static std::vector<glm::vec4> vPositionsOctahedron;
        std::vector<glm::vec4> vColorsOctahedron;
    };

} // gl2

#endif //GL2_APP_H
