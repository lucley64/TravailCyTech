#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <vector>
#include <string>
#include <sstream>

constexpr const char *TITLE = "Hello OpenGL!";
int SCREEN_X = 1024;
int SCREEN_Y = 768;
int nbFrame = 0;
int timeframe = 0;
int timebase = 0;

std::vector<std::vector<GLdouble>> pos{
        {-0.5, 0.0},
        {0.5,  0.0},
        {0.0,  0.8},
};
float angle = 0.0f;
float angle2 = 0.0f;
float axeY = 0.0f;
float axeX = 0.0f;
GLuint drawListCube;
bool orthographic = true;
bool wireframe = false;
bool fog = false;
bool alphaBlending = false;

void init();

void displayTriangleFunc();

void displayCubeFunc();
void displayCube2Func();
void displayCube3Func();

void cleanup();

void initCube();
void initCube2();
void initCube3();

void initTriangle();

void drawCube();

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow(TITLE);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    init();
    glutReshapeFunc([](int width, int height){
        SCREEN_X = width;
        SCREEN_Y = height;
        init();
    });
    glutKeyboardFunc([](unsigned char key, [[maybe_unused]] int _x, [[maybe_unused]] int _y) {
        switch (key) {
            case 'q':
            case '\033':
                glutLeaveMainLoop();
                break;
            case '1':
                initTriangle();
                break;
            case '2':
                initCube();
                break;
            case '3':
                initCube2();
                break;
            case '4':
                initCube3();
                break;
            case 'p':
                orthographic = !orthographic;
                init();
                break;
            case 'w':
                wireframe = !wireframe;
                if (wireframe){
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                } else{
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                }
                break;
            case 'f':
                fog = !fog;
                if (fog){
                    glEnable(GL_FOG);
                    GLfloat fogColor[] = {0.0f, 0.0f, 0.0f, 1};
                    glFogfv(GL_FOG_COLOR, fogColor);
                    glFogi(GL_FOG_MODE, GL_LINEAR);
                    glFogf(GL_FOG_START, 1.5f);
                    glFogf(GL_FOG_END, 2.0f);
                } else{
                    glDisable(GL_FOG);
                }
                break;
            case 'b':
                alphaBlending = !alphaBlending;
                if (alphaBlending){
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA,
                                GL_ONE_MINUS_SRC_ALPHA);
                } else{
                    glDisable(GL_BLEND);
                }
                break;
            default:
                break;
        }
    });
    glutIdleFunc([] {
        nbFrame += 1;
        timeframe = glutGet(GLUT_ELAPSED_TIME);
        std::stringstream ss;
        if (timeframe - timebase > 1000) {
            ss << TITLE << "  " << nbFrame * 1000.0 / (timeframe - timebase)
               << " FPS";
            timebase = timeframe;
            nbFrame = 0;
            glutSetWindowTitle(ss.str().c_str());
        }
        angle2 ++;
        glutPostRedisplay();
    });
    glutDisplayFunc(displayCubeFunc);
    glutMainLoop();
    cleanup();
    return EXIT_SUCCESS;
}

void initCube() {
    init();
    glutDisplayFunc(displayCubeFunc);
    glutDisplayFunc(displayCubeFunc);
    glutMotionFunc([](int x, int y) {
        float angleY = abs((y - SCREEN_Y / 2.0f) / (SCREEN_Y / 2.0f));
        float angleX = abs((x - SCREEN_X / 2.0f) / (SCREEN_X / 2.0f));
        angle = angleX * 90 + angleY * 90;
        axeX = ((y - SCREEN_Y / 2.0f) / (SCREEN_Y / 2.0f));
        axeY = ((x - SCREEN_X / 2.0f) / (SCREEN_X / 2.0f));
    });
}
void initCube2(){
    init();
    drawListCube = glGenLists(1);
    glNewList(drawListCube, GL_COMPILE);
    drawCube();
    glEndList();
    glutDisplayFunc(displayCube2Func);
    glutMotionFunc([](int x, int y) {
        float angleY = abs((y - SCREEN_Y / 2.0f) / (SCREEN_Y / 2.0f));
        float angleX = abs((x - SCREEN_X / 2.0f) / (SCREEN_X / 2.0f));
        angle = angleX * 90 + angleY * 90;
        axeX = ((y - SCREEN_Y / 2.0f) / (SCREEN_Y / 2.0f));
        axeY = ((x - SCREEN_X / 2.0f) / (SCREEN_X / 2.0f));
    });
}

void initCube3(){
    initCube2();
    glutDisplayFunc(displayCube3Func);
}

void initTriangle() {
    init();
    glutMouseFunc([](int button, int state, int x, int y) {
        double dx = (x - SCREEN_X / 2.0) / (SCREEN_X / 2.0);
        double dy = (-y + SCREEN_Y / 2.0) / (SCREEN_Y / 2.0);
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            pos[0][0] = dx;
            pos[0][1] = dy;
        } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            pos[1][0] = dx;
            pos[1][1] = dy;
        } else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
            pos[2][0] = dx;
            pos[2][1] = dy;
        }
        glutPostRedisplay();
    });
    glutDisplayFunc(displayTriangleFunc);


}

void init() {
    glClearColor(.0, .0, .0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    if (orthographic){
        glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
    } else{
        gluPerspective(50, static_cast<double>(SCREEN_X) / SCREEN_Y, 1.0, 100.0);
    }
    glViewport(0, 0, SCREEN_X, SCREEN_Y);
}

void displayFunc(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void displayTriangleFunc() {
    displayFunc();
    glBegin(GL_TRIANGLES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2dv(pos[0].data());
    glColor3d(0.0, 1.0, 0.0);
    glVertex2dv(pos[1].data());
    glColor3d(0.0, 0.0, 1.0);
    glVertex2dv(pos[2].data());
    glEnd();

    glutSwapBuffers();
}

void displayCubeFunc() {
    displayFunc();

    glRotatef(angle, axeX, axeY, 0.0f);

    drawCube();

    glutSwapBuffers();
}

void displayCube2Func() {
    displayFunc();

    glRotatef(angle, axeX, axeY, 0.0f);
    glCallList(drawListCube);

    glutSwapBuffers();
}
void displayCube3Func() {
    displayFunc();

    glRotatef(angle, axeX, axeY, 0.0f);
    glCallList(drawListCube);
    glPushMatrix();
    glScalef(0.5f, 0.5f, 0.5f);
    glTranslatef(0.7f, 0.7f, 0.7f);
    glRotatef(angle2, 0.0f, 1.0f, 0.0f);
    glCallList(drawListCube);
    glPopMatrix();
    glColor3f(0.5f, 0.5f, 0.1f);
    glScalef(0.5f, 0.5f, 0.5f);
    glTranslatef(1.0f, 1.0f, -1.0f);
    glutSolidSphere(0.5f, 50, 50);

    glutSwapBuffers();
}

void drawCube() {
    glBegin(GL_QUADS);

    // Top face (y = 0.5)
    glColor4f(0.0f, 1.0f, 0.0f, 0.5f);     // Green
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

// Bottom face (y = -0.5)
    glColor4f(1.0f, 0.5f, 0.0f, 0.5f);     // Orange
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

// Left face (x = -0.5)
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);     // Blue
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

// Right face (x = 0.5)
    glColor4f(1.0f, 0.0f, 1.0f, 0.5f);     // Magenta
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

// Back face (z = -0.5)
    glColor4f(1.0f, 1.0f, 0.0f, 0.5f);     // Yellow
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

// Front face (z = 0.5)
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f);     // Red
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glEnd();


}

void cleanup() {
    glDeleteLists(drawListCube, 1);
}
