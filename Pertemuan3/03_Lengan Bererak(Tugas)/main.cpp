#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, wrist = 0;
static int finger[5][3] = {
    {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
};

void init(void)
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int a1, int a2, int a3)
{
    // RUAS 1 
    glPushMatrix();

    glRotatef(a1,0,0,1);     
    glTranslatef(0.3,0,0);   

    glPushMatrix();
    glScalef(0.6,0.2,0.2);
    glutWireCube(1);
    glPopMatrix();

    // RUAS 2 
    glTranslatef(0.3,0,0);   
    glRotatef(a2,0,0,1);

    glTranslatef(0.25,0,0);  
    glPushMatrix();
    glScalef(0.5,0.15,0.15);
    glutWireCube(1);
    glPopMatrix();

    // RUAS 3 
    glTranslatef(0.25,0,0);  
    glRotatef(a3,0,0,1);

    glTranslatef(0.2,0,0);  
    glPushMatrix();
    glScalef(0.4,0.12,0.12);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
}

// DISPLAY
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // SHOULDER 
    glTranslatef(-1,0,0);
    glRotatef(shoulder,0,0,1);
    glTranslatef(1,0,0);

    glPushMatrix();
    glScalef(2,0.4,1);
    glutWireCube(1);
    glPopMatrix();

    // ELBOW 
    glTranslatef(1,0,0);
    glRotatef(elbow,0,0,1);
    glTranslatef(1,0,0);

    glPushMatrix();
    glScalef(2,0.4,1);
    glutWireCube(1);
    glPopMatrix();

    // WRIST 
    glTranslatef(1,0,0);
    glRotatef(wrist,0,0,1);

    // TELAPAK 
    glPushMatrix();
    glScalef(1.0,0.6,0.3);
    glutWireCube(1);
    glPopMatrix();

    // 4 JARI 
    float pos[4] = {-0.25,-0.08,0.08,0.25};

    for(int i=0;i<4;i++)
    {
        glPushMatrix();
        glTranslatef(0.6,pos[i],0);
        glRotatef(-10,0,0,1);
        drawFinger(finger[i][0], finger[i][1], finger[i][2]);
        glPopMatrix();
    }

    // IBU JARI 
    glPushMatrix();
    glTranslatef(0.2,-0.4,0);
    glRotatef(-40,0,0,1);
    drawFinger(finger[4][0], finger[4][1], finger[4][2]);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

// RESHAPE 
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,(float)w/h,1,20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-6);
}

// KEYBOARD 
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        // LENGAN 
        case 's': shoulder+=5; break;
        case 'S': shoulder-=5; break;

        case 'e': elbow+=5; break;
        case 'E': elbow-=5; break;

        case 'w': wrist+=5; break;
        case 'W': wrist-=5; break;

        // RUAS 1 
        case '1': finger[0][0]+=5; break;
        case '2': finger[1][0]+=5; break;
        case '3': finger[2][0]+=5; break;
        case '4': finger[3][0]+=5; break;
        case '5': finger[4][0]+=5; break;

        // RUAS 2 
        case 'q': finger[0][1]+=5; break;
        case 'r': finger[1][1]+=5; break;
        case 't': finger[2][1]+=5; break;
        case 'y': finger[3][1]+=5; break;
        case 'u': finger[4][1]+=5; break;

        // RUAS 3 
        case 'a': finger[0][2]+=5; break;
        case 'f': finger[1][2]+=5; break;
        case 'g': finger[2][2]+=5; break;
        case 'h': finger[3][2]+=5; break;
        case 'j': finger[4][2]+=5; break;

        // BALIK 
        case '!': finger[0][0]-=5; break;
        case '@': finger[1][0]-=5; break;
        case '#': finger[2][0]-=5; break;
        case '$': finger[3][0]-=5; break;
        case '%': finger[4][0]-=5; break;

        case 'Q': finger[0][1]-=5; break;
        case 'R': finger[1][1]-=5; break;
        case 'T': finger[2][1]-=5; break;
        case 'Y': finger[3][1]-=5; break;
        case 'U': finger[4][1]-=5; break;

        case 'A': finger[0][2]-=5; break;
        case 'F': finger[1][2]-=5; break;
        case 'G': finger[2][2]-=5; break;
        case 'H': finger[3][2]-=5; break;
        case 'J': finger[4][2]-=5; break;

        case 27: exit(0);
    }

    glutPostRedisplay();
}

// MAIN 
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(700,600);
    glutCreateWindow("Lengan Bergerak");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
