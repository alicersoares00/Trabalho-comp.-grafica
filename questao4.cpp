#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

float xPosition = -0.8f;
float speed = 0.01f;

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.5f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(-0.25f, 0.25f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xPosition, 0.0f, 0.0f);
    drawSquare();
    glutSwapBuffers();
}

void update(int value) {
    xPosition += speed;
    if (xPosition > 0.8f || xPosition < -0.8f) {
        speed = -speed;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("animacao");

    glewInit();
    initOpenGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}
