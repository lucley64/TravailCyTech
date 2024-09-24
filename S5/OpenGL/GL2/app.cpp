//
// Created by cytech on 24/09/24.
//

#include "app.h"
#include "shader_class.h"

namespace gl2 {
    std::unique_ptr<gl2::vao> app::vaoCube;
    std::vector<glm::vec4> app::vPositions;
    std::unique_ptr<gl2::shader_class> app::passthrough;

    void app::init(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        glutInitWindowSize(width, height);
        glutCreateWindow(TITLE);
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
        glClearColor(.0, .0, .0, 1.0);
        glViewport(0, 0, width, height);
        if (GLenum err = glewInit(); err != GLEW_OK) {
            std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "Using GLEW: " << glewGetString(GLEW_VERSION) << std::endl;

        glEnable(GL_DEPTH_TEST);

        colorCube();

        vaoCube = std::make_unique<gl2::vao>();
        vaoCube->bind();

        vboCube = std::make_unique<gl2::vbo>(vPositions, vColors);

        passthrough = std::make_unique<gl2::shader_class>("../shaders/vertex/passthrough.vert", "../shaders/fragments/passthrough.frag");

        vaoCube->linkAttrib(*vboCube, 0, 4, GL_FLOAT, 0, nullptr);
        vaoCube->linkAttrib(*vboCube, 1, 4, GL_FLOAT, 0, reinterpret_cast<void *>(vPositions.size() * sizeof(glm::vec4)));
        glutDisplayFunc(displayFunc);
        glutKeyboardFunc(keyboard);
    }

    void app::displayFunc() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        passthrough->activate();
        vaoCube->bind();
        glDrawArrays(GL_TRIANGLES, 0, vPositions.size());
        glutSwapBuffers();
    }

    void app::keyboard(unsigned char key, int , int ) {
        switch (key) {
            case '\033':
            case 'q':
            case 'Q':
                glutExit();
                break;
            default:
                break;
        }
    }

    app::~app() {
        vaoCube.reset();
        passthrough.reset();
    }

    void app::colorCube() {
        vPositions = {
                vertices[3], vertices[1], vertices[0],
                vertices[2], vertices[1], vertices[3],
                vertices[2], vertices[5], vertices[1],
                vertices[6], vertices[5], vertices[2],
                vertices[6], vertices[4], vertices[5],
                vertices[7], vertices[4], vertices[6],
                vertices[7], vertices[0], vertices[4],
                vertices[3], vertices[0], vertices[7],
                vertices[7], vertices[2], vertices[3],
                vertices[6], vertices[2], vertices[7],
                vertices[0], vertices[5], vertices[4],
                vertices[1], vertices[5], vertices[0],
        };
        vColors = {
                colors[3], colors[1], colors[0],
                colors[2], colors[1], colors[3],
                colors[2], colors[5], colors[1],
                colors[6], colors[5], colors[2],
                colors[6], colors[4], colors[5],
                colors[7], colors[4], colors[6],
                colors[7], colors[0], colors[4],
                colors[3], colors[0], colors[7],
                colors[7], colors[2], colors[3],
                colors[6], colors[2], colors[7],
                colors[0], colors[5], colors[4],
                colors[1], colors[5], colors[0],
        };
    }

    void app::start() {
        glutMainLoop();
    }

} // gl2