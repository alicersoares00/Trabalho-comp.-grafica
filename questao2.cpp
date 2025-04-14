#include <GL/glut.h>
#include <cmath>  


void desenharCirculo(float raio, int segmentos) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= segmentos; i++) {
        float angulo = (2.0f * 3.1415 * i) / segmentos;
        float x = raio * cos(angulo);
        float y = raio * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    int segmentos = 200; 


    glColor3f(0.0f, 0.0f, 0.2f);
    desenharCirculo(0.8f, segmentos);

    glColor3f(0.0f, 0.0f, 0.6f);
    desenharCirculo(0.6f, segmentos);

    glColor3f(0.0f, 0.0f, 0.2f);
    desenharCirculo(0.4f, segmentos);

    glColor3f(1.0f, 1.0f, 1.0f);
    desenharCirculo(0.2f, segmentos);

    glFlush();
}

void iniciarJanela() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("circulos");
    iniciarJanela();
    glutDisplayFunc(desenhar);
    glutMainLoop();
    return 0;
}
