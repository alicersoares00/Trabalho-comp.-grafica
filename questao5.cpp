
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>

float angle = 0.0f;

void drawCircle() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 360; i++) {
        float theta = 2 * 3.14159265358979323846 * float(i) / 360;
        float x = cos(theta) * 0.5f;
        float y = sin(theta) * 0.5f;
        glColor3f(fabs(sin(theta)), fabs(cos(theta)), 1.0f - fabs(sin(theta)));
        glVertex2f(x, y);
    }
    glEnd();
}

void update(int value) {
    angle += 2.0f;
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);
    drawCircle();
    glutSwapBuffers();
}

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("circulo multicolorido");

    glewInit();
    initOpenGL();

    glutDisplayFunc(renderScene);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}


