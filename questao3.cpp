#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

float yPosition = 0.0f;

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(-0.25f, 0.25f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, yPosition, 0.0f);
    drawSquare();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        yPosition += 0.1f;
        glutPostRedisplay();
    }
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
    glutCreateWindow("quadrado vermelho");

    glewInit();
    initOpenGL();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
