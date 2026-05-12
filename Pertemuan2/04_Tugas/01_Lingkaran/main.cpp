#include <gl/glut.h>
#include <math.h>

void lingkaran()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0); // warna merah

    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++)
    {
        float sudut = 2 * 3.1416 * i / 100;
        glVertex2f(cos(sudut)*0.5, sin(sudut)*0.5);
    }
    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lingkaran");

    glClearColor(1,1,1,1);

    glutDisplayFunc(lingkaran);
    glutMainLoop();

    return 0;
}

