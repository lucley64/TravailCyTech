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

namespace gl2 {

    class app {
    private:
        const char *TITLE = "Hello OpenGL!";
        int width = 1024;
        int height = 768;
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
        std::unique_ptr<gl2::vbo> vboCube = nullptr;
        static std::unique_ptr<gl2::shader_class> passthrough;


        static std::vector<glm::vec4> vPositions;
        std::vector<glm::vec4> vColors;

        static void displayFunc();

        static void keyboard(unsigned char key, int x, int y);


        void colorCube();

    public:
        void init(int argc, char **argv);

        void start();

        ~app();

    };

} // gl2

#endif //GL2_APP_H
