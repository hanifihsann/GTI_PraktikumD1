#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double rotAngle = 10;
double rotAngle1 = 10;

// ===============================
// FUNGSI INIT
// ===============================
void init()
{
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60, 1, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        0.0, 0.0, 5.0,   // posisi kamera
        0.0, 0.0, 0.0,   // titik yang dilihat kamera
        0.0, 1.0, 0.0    // arah atas kamera
    );
}

// ===============================
// FUNGSI DISPLAY
// ===============================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    // Rotasi objek
    glRotated(rotAngle, 0, 1, 0);    // rotasi terhadap sumbu Y
    glRotated(rotAngle1, 1, 0, 0);   // rotasi terhadap sumbu X

    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 0.1, 0.1);

    // Menggambar objek teapot
    glutSolidTeapot(1);

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

// ===============================
// FUNGSI KEYBOARD
// ===============================
void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
        case 'a':
            rotAngle += 5;
            break;

        case 'l':
            rotAngle -= 5;
            break;

        case 'y':
            rotAngle1 += 5;
            break;

        case 'b':
            rotAngle1 -= 5;
            break;

        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// ===============================
// MAIN PROGRAM
// ===============================
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_DEPTH |
        GLUT_RGB
    );

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Menggerakkan Kamera dalam OpenGL");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;
}
