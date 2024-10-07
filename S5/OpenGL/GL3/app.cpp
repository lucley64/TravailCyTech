//
// Created by cytech on 24/09/24.
//

#include "app.h"
#include "shader_class.h"
#include "glm/mat4x4.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

namespace gl2 {
    std::unique_ptr<gl2::vao> app::vaoCube;
    std::unique_ptr<gl2::vao> app::vaoInterlacedCube;
    std::unique_ptr<gl2::vao> app::vaoOctahedron;
    std::vector<glm::vec4> app::vPositionsColorCube;
    std::vector<glm::vec4 > app::vPositionsInterlacedCube;
    std::vector<glm::vec4 > app::vPositionsOctahedron;
    std::unique_ptr<gl2::shader_class> app::passthrough;
    int app::width = 1024;
    int app::height = 768;
    glm::vec4 app::rotation{1.0f, 0.0f, 0.0f, 0.0f};

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
        interlacedCube();
        octahedron();

        vaoCube = std::make_unique<gl2::vao>();
        vaoCube->bind();

        vboCube = std::make_unique<gl2::vbo>(vPositionsColorCube, vColorsColorCube);

        passthrough = std::make_unique<gl2::shader_class>("../shaders/vertex/default.vert",
                                                          "../shaders/fragments/default.frag");

        vaoCube->linkAttrib(*vboCube, 0, 4, GL_FLOAT, 0, nullptr);
        vaoCube->linkAttrib(*vboCube, 1, 4, GL_FLOAT, 0,
                            reinterpret_cast<void *>(vPositionsColorCube.size() * sizeof(glm::vec4)));

        vaoCube->unbind();

        vaoInterlacedCube = std::make_unique<gl2::vao>();
        vaoInterlacedCube->bind();
        vboInterlacedCube = std::make_unique<gl2::vbo>(vPositionsInterlacedCube);

        vaoInterlacedCube->linkAttrib(*vboInterlacedCube, 0, 4, GL_FLOAT, 8 * sizeof(float ), nullptr);
        vaoInterlacedCube->linkAttrib(*vboInterlacedCube, 1, 4, GL_FLOAT, 8 * sizeof(float ), reinterpret_cast<void *>(4 * sizeof(float )));

        vaoInterlacedCube->unbind();

        vaoOctahedron = std::make_unique<gl2::vao>();
        vaoOctahedron->bind();
        vboOctahedronPositions = std::make_unique<gl2::vbo>(vPositionsOctahedron);
        vboOctahedronColors = std::make_unique<gl2::vbo>(vColorsOctahedron);

        vaoOctahedron->linkAttrib(*vboOctahedronPositions, 0, 4, GL_FLOAT, 0, nullptr);
        vaoOctahedron->linkAttrib(*vboOctahedronColors, 1, 4, GL_FLOAT, 0, nullptr);

        vaoOctahedron->unbind();


        glutDisplayFunc(displayFunc);
        glutReshapeFunc(reshapeFunc);
        glutMotionFunc(motionFunc);


        glutKeyboardFunc(keyboard);
    }

    void app::motionFunc(int x, int y) {
        float angleY = abs((y - height / 2.0f) / (height / 2.0f));
        float angleX = abs((x - width / 2.0f) / (width / 2.0f));
        rotation.w = -(angleX + angleY);
        rotation.x = ((y - height / 2.0f) / (height / 2.0f));
        rotation.y = ((x - width / 2.0f) / (width / 2.0f));
        glutPostRedisplay();
    }

    void app::reshapeFunc(int newWidth, int newHeight) {
        app::width = newWidth;
        app::height = newHeight;
        glutPostRedisplay();
    }

    void app::displayFunc() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        passthrough->activate();
        vaoCube->bind();
        updateMVP({0.0f, 0.0f, 0.0f});
        glDrawArrays(GL_TRIANGLES, 0, vPositionsColorCube.size());
        vaoCube->unbind();
        vaoInterlacedCube->bind();
        updateMVP({2.0f, 0.0f, 0.0f});
        glDrawArrays(GL_TRIANGLES, 0, vPositionsInterlacedCube.size());
        vaoInterlacedCube->unbind();
        vaoOctahedron->bind();
        updateMVP({-2.0f, 0.0f, 0.0f});
        glDrawArrays(GL_TRIANGLES, 0, vPositionsOctahedron.size());
        vaoOctahedron->unbind();
        glutSwapBuffers();
    }

    void app::keyboard(unsigned char key, int, int) {
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
        vPositionsColorCube = {
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
        vColorsColorCube = {
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

    void app::interlacedCube() {
        vPositionsInterlacedCube = {
                vertices[3], colors[0], vertices[1], colors[0], vertices[0], colors[0],
                vertices[2], colors[0], vertices[1], colors[0], vertices[3], colors[0],
                vertices[2], colors[1], vertices[5], colors[1], vertices[1], colors[1],
                vertices[6], colors[1], vertices[5], colors[1], vertices[2], colors[1],
                vertices[6], colors[2], vertices[4], colors[2], vertices[5], colors[2],
                vertices[7], colors[2], vertices[4], colors[2], vertices[6], colors[2],
                vertices[7], colors[3], vertices[0], colors[3], vertices[4], colors[3],
                vertices[3], colors[3], vertices[0], colors[3], vertices[7], colors[3],
                vertices[7], colors[4], vertices[2], colors[4], vertices[3], colors[4],
                vertices[6], colors[4], vertices[2], colors[4], vertices[7], colors[4],
                vertices[0], colors[5], vertices[5], colors[5], vertices[4], colors[5],
                vertices[1], colors[5], vertices[5], colors[5], vertices[0], colors[5],
        };
    }

    void app::octahedron(){
        vPositionsOctahedron = {
                {-0.5f, 0.0f, -0.5f, 1.0f}, {0.5f, 0.0f, -0.5f, 1.0f}, {0.0f, 0.5f, 0.0f, 1.0f},
                {-0.5f, 0.0f, -0.5f, 1.0f}, {0.5f, 0.0f, -0.5f, 1.0f}, {0.0f, -0.5f, 0.0f, 1.0f},
                {-0.5f, 0.0f, -0.5f, 1.0f}, {-0.5f, 0.0f, 0.5f, 1.0f}, {0.0f, 0.5f, 0.0f, 1.0f},
                {-0.5f, 0.0f, -0.5f, 1.0f}, {-0.5f, 0.0f, 0.5f, 1.0f}, {0.0f, -0.5f, 0.0f, 1.0f},
                {0.5f, 0.0f, 0.5f, 1.0f}, {-0.5f, 0.0f, 0.5f, 1.0f}, {0.0f, 0.5f, 0.0f, 1.0f},
                {0.5f, 0.0f, 0.5f, 1.0f}, {-0.5f, 0.0f, 0.5f, 1.0f}, {0.0f, -0.5f, 0.0f, 1.0f},
                {0.5f, 0.0f, 0.5f, 1.0f}, {0.5f, 0.0f, -0.5f, 1.0f}, {0.0f, 0.5f, 0.0f, 1.0f},
                {0.5f, 0.0f, 0.5f, 1.0f}, {0.5f, 0.0f, -0.5f, 1.0f}, {0.0f, -0.5f, 0.0f, 1.0f},

        };
        vColorsOctahedron = {
                colors[6], colors[6], colors[6],
                colors[7], colors[7], colors[7],
                colors[7], colors[7], colors[7],
                colors[6], colors[6], colors[6],
                colors[6], colors[6], colors[6],
                colors[7], colors[7], colors[7],
                colors[7], colors[7], colors[7],
                colors[6], colors[6], colors[6],
        };
    }

    void app::start() {
        glutMainLoop();
    }

    void app::updateMVP(glm::vec3 translation) {
        glm::mat4 projection = glm::perspective(50.0f, static_cast<float>(width) / height, 1.0f, 100.0f);
        glm::mat4 view = glm::lookAt(glm::vec3{0.0f, 0.0f, 20.0f}, glm::vec3{0.0f, 0.0f, 0.0f},
                                     glm::vec3{0.0f, 1.0f, 0.0f});
        glm::mat4 model{1.0};
        model = glm::translate(model, translation);
        model = glm::rotate(model, rotation.w, glm::vec3(rotation.x, rotation.y, rotation.z));
        glm::mat4 mvp = projection * view * model;
        glUniformMatrix4fv(2, 1, GL_FALSE, &mvp[0][0]);
    }

} // gl2