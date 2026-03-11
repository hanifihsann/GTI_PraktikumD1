#include <gl/glut.h>

void Kubus(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.6f, 0.1f);

    glVertex3f(-0.10, -0.60, 0.0);
    glVertex3f(0.10, -0.60, 0.0);
    glVertex3f(0.10, -0.40, 0.0);
    glVertex3f(-0.10, -0.40, 0.0);

    glVertex3f(-0.22, -0.39, 0.0);
    glVertex3f(-0.02, -0.39, 0.0);
    glVertex3f(-0.02, -0.19, 0.0);
    glVertex3f(-0.22, -0.19, 0.0);

    glVertex3f(0.02, -0.39, 0.0);
    glVertex3f(0.22, -0.39, 0.0);
    glVertex3f(0.22, -0.19, 0.0);
    glVertex3f(0.02, -0.19, 0.0);

    glVertex3f(-0.34, -0.18, 0.0);
    glVertex3f(-0.14, -0.18, 0.0);
    glVertex3f(-0.14, 0.02, 0.0);
    glVertex3f(-0.34, 0.02, 0.0);

    glVertex3f(-0.10, -0.18, 0.0);
    glVertex3f(0.10, -0.18, 0.0);
    glVertex3f(0.10, 0.02, 0.0);
    glVertex3f(-0.10, 0.02, 0.0);

    glVertex3f(0.14, -0.18, 0.0);
    glVertex3f(0.34, -0.18, 0.0);
    glVertex3f(0.34, 0.02, 0.0);
    glVertex3f(0.14, 0.02, 0.0);

    glEnd();

    glFlush();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kubus Bertingkat");
    glutDisplayFunc(Kubus);

    glClearColor(1.0f,1.0f,1.0f,1.0f);

    glutMainLoop();
    return 0;
}
