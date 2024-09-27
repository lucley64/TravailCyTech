// Physics-engine.cpp?: d?finit le point d'entr?e pour l'application console.
//

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <ctime>
#include <string>

#include "Quantum/Quantum.h"
#include "GxWorld.h"
#include "GxParticle.h"
#include "GxUpdater.h"
#include "Quantum/QmDrag.h"
#include "Quantum/QmGravity.h"
#include "Quantum/QmMagnetism.h"
#include "Quantum/QmFixedMagnetism.h"

using namespace std;
using namespace Quantum;


GxWorld gxWorld;
QmWorld pxWorld;

glm::vec3 *mousePointer;
int mouseCharge = -1;

int scene = 0;

// ********************** GLUT 
// Variables globales

int SCREEN_X = 800;
int SCREEN_Y = 800;
int VIEWPORT_X = 5;
int VIEWPORT_Y = 5;
int VIEWPORT_Z = 200;

GLuint DrawListSphere;

int buttons = 0;
float camRotate = 90.f;
float camDist = 30.f;
float camHeight = 0.f;
float mx = 0.f;
float my = 0.f;

// Variables du calcul de framerate 
int timeold = 0;
int frame = 0;
float accTime = 0.0;
bool paused = false;

GLfloat light_pos[] = {0.0, 6.0, 1.0, 1.0};

bool gravity = true;
bool drag = true;
bool magnetism = false;
bool fixedMagnetism = false;
std::vector<QmParticle *> other{};

// ********************************************


glm::vec3 randomVector(float min, float max) {
    float x = min + (max - min) * ((rand() % 100) / 100.f);
    float y = min + (max - min) * ((rand() % 100) / 100.f);
    float z = min + (max - min) * ((rand() % 100) / 100.f);
    return glm::vec3(x, y, z);

}

glm::vec3 randomUpVector(float min, float max) {
    float x = min + (max - min) * ((rand() % 100) / 100.f) - (max - min) / 2;
    float y = min + (max - min) * ((rand() % 100) / 100.f);
    float z = min + (max - min) * ((rand() % 100) / 100.f) - (max - min) / 2;
    return glm::vec3(x, y, z);

}

QmParticle *
createParticle(glm::vec3 color, glm::vec3 pos, glm::vec3 initSpeed, int charge, std::vector<QmParticle *> &others) {
    auto rad = 0.1f + 0.2f * ((rand() % 100) / 100.f);
    GxParticle *g = new GxParticle(color, rad, pos);
    QmParticle *p = new QmParticle(pos, initSpeed, randomVector(0, 0), rad, charge);
    p->setUpdater(new GxUpdater(g));
    gxWorld.addParticle(g);
    pxWorld.addBody(p);
    if (drag) { pxWorld.addForceRegistry(QmForceRegistry(p, new QmDrag(rad, rad))); }
    if (gravity) { pxWorld.addForceRegistry(QmForceRegistry(p, new QmGravity())); }
    if (magnetism) {
        if (fixedMagnetism && mousePointer) {
            pxWorld.addForceRegistry(QmForceRegistry(p, new QmFixedMagnetism(mousePointer, &mouseCharge, 10000, 10)));
        }
        else { pxWorld.addForceRegistry(QmForceRegistry(p, new QmMagnetism(others, 10000, 10))); }
    }
    return p;
}

void initScene1() {
    printf("Scene 1: Random particles.\n");
    printf("Type space to pause.\n");
    gravity = true;
    magnetism = false;
    other.clear();
    mousePointer = new glm::vec3(0, 4.5, 0);
}

void initScene2() {
    printf("Scene 2.\n");
    printf("Empty.\n");
    gravity = false;
    magnetism = true;
    other.clear();
    for (int i = 0; i < 50; i++) {
        int charge = rand() % 2 * 2 - 1;
        glm::vec3 color{charge == -1 ? 255 : 0, 0.0, charge == 1 ? 255 : 0};
        other.push_back(createParticle(color, randomVector(-10, 10), glm::vec3(0), charge, other));
    }
}

// ***************************** GLUT methods

void resetView() {
    camRotate = 90.f;
    camDist = 30.f;
    camHeight = 0.f;
    mx = 0.f;
    my = 0.f;
    if (mousePointer) {
        delete mousePointer;
        mousePointer = nullptr;
    }
}

void createDisplayListSphere() {
    DrawListSphere = glGenLists(1);
    glNewList(DrawListSphere, GL_COMPILE);
    GLUquadricObj *sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 1, 12, 8);
    glEndList();
}

void initLight() {
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);

    GLfloat ambient_light[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat diffuse_light[] = {0.6f, 0.6f, 0.6f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHTING);
}

void calculateFPS(float dt) {
    accTime += dt;

    if (accTime > 0.5) {
        char t[200];
        sprintf(t, "Quantum Physics Engine: Scene %d, %.2f FPS", scene, frame / accTime);
        glutSetWindowTitle(t);
        accTime = 0.0;
        frame = 0;
    }
}

void idleFunc() {
    int timer = glutGet(GLUT_ELAPSED_TIME);
    float dt = (float) (timer - timeold) / 1000.f;
    timeold = timer;

    calculateFPS(dt);
    if (!paused) pxWorld.simulate(dt);

    if (mousePointer != nullptr && !magnetism) {
        for (int i = 0; i < 1; i++) {
            createParticle(randomVector(1, 0), *mousePointer, randomUpVector(2, 10), rand() % 2 * 2 - 1, other);
        }
    }

    glutPostRedisplay();
}

void drawFunc() {
    frame++;
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camDist * cos(camRotate), camHeight, camDist * sin(camRotate), 0, camHeight, 0, 0, 1, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    for (GxParticle *p: gxWorld.getParticles()) {
        glPushMatrix();
        glm::vec3 color = p->getColor();
        glColor3f(color.x, color.y, color.z);
        glTranslatef(p->getPos().x, p->getPos().y, p->getPos().z);
        glScaled(p->getRadius(), p->getRadius(), p->getRadius());
        glCallList(DrawListSphere);
        glPopMatrix();
    }
    if (mousePointer) {
        glPushMatrix();
        glColor3f(1.f, 1.f, 1.f);
        glTranslatef(mousePointer->x, mousePointer->y, mousePointer->z);
        glScaled(0.1f, 0.1f, 0.1f);
        glCallList(DrawListSphere);
        glPopMatrix();
    }
    glutSwapBuffers();
}


void mouseFunc(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) buttons = 1;
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) buttons = 2;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) buttons = 3;
    if (button == 3) camDist /= 1.07f;
    if (button == 4) camDist *= 1.07f;
    if (state == GLUT_UP) buttons = 0;

    mx = (float) x;
    my = (float) y;
}


void motionFunc(int x, int y) {
    if (buttons == 1) {
        camRotate += (x - mx) / 100.f;
        camHeight += (y - my) * camDist / 1000.f;
    }
    if (buttons == 3) {
        if (mousePointer)
            *mousePointer += glm::vec3(x - mx, my - y, 0.f) / 15.f;
    }

    mx = (float) x;
    my = (float) y;
}

void clearWorld() {
    gxWorld.clear();
    pxWorld.clear();

}

void toggleScene(int s) {
    clearWorld();
    scene = s;
    resetView();

    switch (scene) {
        case 1:
            initScene1();
            break;
        case 2:
            fixedMagnetism = false;
            initScene2();
            break;
        default:
            break;
    }
}

void keyFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
        case 27:
            clearWorld();
            glDeleteLists(DrawListSphere, 1);
            exit(0);
        case '1':
            toggleScene(1);
            break;
        case '2':
            toggleScene(2);
            break;
        case 'g':
            gravity = !gravity;
            break;
        case 'd':
            drag = !drag;
            break;
        case 'f':
            fixedMagnetism = !fixedMagnetism;
            clearWorld();
            mousePointer = new glm::vec3(0, 4.5, 0);
            initScene2();
            break;
        case 'c':
            mouseCharge *= -1;
            break;
        case ' ':
            paused = !paused;
            break;
        default:
            break;
    }
}

void initGraphics(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow("Quantum Demo");

    glutIdleFunc(idleFunc);
    glutDisplayFunc(drawFunc);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(motionFunc);
    glutKeyboardFunc(keyFunc);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    float aspect = SCREEN_X / (float) SCREEN_Y;
    gluPerspective(45.0, aspect, 1.0, VIEWPORT_Z);
    glViewport(0, 0, SCREEN_X, SCREEN_Y);
    createDisplayListSphere();
    initLight();
}

// ************************** end GLUT methods

int main(int argc, char **argv) {
    srand((unsigned int) time(NULL));
    initGraphics(argc, argv);

    toggleScene(1);

    glutMainLoop();
    return 0;
}




