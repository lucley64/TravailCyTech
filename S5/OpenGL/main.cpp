#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <vector>
#include <string>
#include <sstream>

constexpr const char *TITLE = "Hello OpenGL!";
constexpr int SCREEN_X = 1024;
constexpr int SCREEN_Y = 768;
std::vector<std::vector<GLdouble>> pos{
        {-0.5, 0.0},
        {0.5, 0.0},
        {0.0, 0.8},
};
volatile int nbFrame = 0;
volatile int timeframe = 0;
volatile int timebase = 0;

void init();

void displayFunc();
void triangleFunc();
void cleanup();

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow(TITLE);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    init();
    glutKeyboardFunc([](unsigned char key, [[maybe_unused]] int _x, [[maybe_unused]] int _y){
        switch (key) {
            case 'q':
            case '\033':
                glutLeaveMainLoop();
                break;
            default:
                break;
        }
    });
    glutMouseFunc([](int button, int state, int x, int y) {
        double dx = (x - SCREEN_X / 2.0) / (SCREEN_X / 2.0);
        double dy = (-y + SCREEN_Y / 2.0) / (SCREEN_Y / 2.0);
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            pos[0][0] = dx;
            pos[0][1] = dy;
        } else if (button == GLUT_RIGHT_BUTTON && state== GLUT_DOWN){
            pos[1][0] = dx;
            pos[1][1] = dy;
        } else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
            pos[2][0] = dx;
            pos[2][1] = dy;
        }
        glutPostRedisplay();
    });
    glutIdleFunc([]{
        nbFrame += 1;
        timeframe = glutGet(GLUT_ELAPSED_TIME);
        std::stringstream ss;
        if (timeframe - timebase > 1000){
            ss << TITLE << "  " << nbFrame * 1000.0 / (timeframe - timebase) << " FPS";
            timebase = timeframe;
            nbFrame = 0;
            glutSetWindowTitle(ss.str().c_str());
        }

        glutPostRedisplay();
    });
    glutDisplayFunc(displayFunc);
    glutMainLoop();
    cleanup();
    return EXIT_SUCCESS;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
    glViewport(0, 0, SCREEN_X, SCREEN_Y);
}

void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    triangleFunc();

    glutSwapBuffers();
}

void triangleFunc(){
    glBegin(GL_TRIANGLES);
    {
        glColor3d(1.0, 0.0, 0.0);
        glVertex2dv(pos[0].data());
        glColor3d(0.0, 1.0, 0.0);
        glVertex2dv(pos[1].data());
        glColor3d(0.0, 0.0, 1.0);
        glVertex2dv(pos[2].data());
    }
    glEnd();
}

void cleanup() {
    // free allocated memory
}
