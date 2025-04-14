#include <GL/glew.h>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.98f, 0.93f, 0.83f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f - 0.2f, -0.2f);
    glVertex2f(0.4f - 0.2f, -0.2f);
    glVertex2f(0.3f - 0.2f, -0.4f);
    glVertex2f(-0.3f - 0.2f, -0.4f);
    glEnd();

    glColor3f(0.75f, 0.75f, 0.75f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.00f - 0.25f, 0.35f);
    glVertex2f(-0.15f - 0.25f, -0.08f);
    glVertex2f(0.25f - 0.25f, -0.08f);
    glEnd();

    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.07f - 0.2f, -0.2f);
    glVertex2f(-0.03f - 0.2f, -0.2f);
    glVertex2f(-0.03f - 0.2f, 0.3f);
    glVertex2f(-0.07f - 0.2f, 0.3f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f - 0.25f, 0.3f);
    glVertex2f(0.09f - 0.25f, 0.3f);
    glVertex2f(0.09f - 0.25f, 0.35f);
    glVertex2f(-0.02f - 0.25f, 0.35f);
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("barco");
    glewInit();
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
