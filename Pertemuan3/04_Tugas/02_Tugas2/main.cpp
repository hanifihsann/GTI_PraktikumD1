#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int finger[5][3] = {
    {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
};

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int a1, int a2, int a3)
{
    glPushMatrix();

    // ===== RUAS 1 =====
    glRotatef(a1, 0, 0, 1);
    glPushMatrix();
        glTranslatef(0.1, 0, 0);          
        glScalef(0.2, 0.1, 0.1);
        glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.2, 0, 0);

    //RUAS 2
    glRotatef(a2, 0, 1, 0);
    glPushMatrix();
        glTranslatef(0.09, 0, 0);
        glScalef(0.18, 0.09, 0.09);
        glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.18, 0, 0);

    //RUAS 3
    glRotatef(a3, 0, 1, 0);

    glPushMatrix();
        glTranslatef(0.075, 0, 0);
        glScalef(0.15, 0.08, 0.08);
        glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

// Display
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //SHOULDER
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    //ELBOW
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

	//PERGELANGAN
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
	glPushMatrix();
	    glScalef(0.25, 0.25, 0.25);
	    glutWireCube(1.0);
	glPopMatrix();

	//TELAPAK
	glTranslatef(0.25, 0.0, 0.0);   
	
	glPushMatrix();
	    glScalef(0.5, 0.5, 0.3);   
	    glutWireCube(1.0);
	glPopMatrix();

    //4 JARI
    float posisi[4] = {-0.2, -0.07, 0.07, 0.2};
    for(int i = 0; i < 4; i++)
    {
        glPushMatrix();
            glTranslatef(0.28, posisi[i], 0.0);
            glRotatef(-10, 0, 0, 1);
            drawFinger(finger[i][0], finger[i][1], finger[i][2]);
        glPopMatrix();
    }

    // IBU JARI
    glPushMatrix();
        glTranslatef(0.15, -0.3, 0.0);
        glRotatef(-40, 0, 0, 1);
        drawFinger(finger[4][0], finger[4][1], finger[4][2]);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

// Reshape
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

// Kontrol
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;

        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        case 'w': wrist += 5; break;
        case 'W': wrist -= 5; break;

		case '1': finger[0][0] += 5; break;
		case '6': finger[0][1] += 5; break;
		case 'y': finger[0][2] += 5; break;
		
		case '2': finger[1][0] += 5; break;
		case '7': finger[1][1] += 5; break;
		case 'u': finger[1][2] += 5; break;
		
		case '3': finger[2][0] += 5; break;
		case '8': finger[2][1] += 5; break;
		case 'i': finger[2][2] += 5; break;
		
		case '4': finger[3][0] += 5; break;
		case '9': finger[3][1] += 5; break;
		case 'o': finger[3][2] += 5; break;
		
		case '5': finger[4][0] += 5; break;
		case '0': finger[4][1] += 5; break;
		case 'p': finger[4][2] += 5; break;
		
		case '!': finger[0][0] -= 5; break;   
		case '^': finger[0][1] -= 5; break;  
		case 'Y': finger[0][2] -= 5; break;
		
		case '@': finger[1][0] -= 5; break;   
		case '&': finger[1][1] -= 5; break;   
		case 'U': finger[1][2] -= 5; break;
		
		case '#': finger[2][0] -= 5; break;  
		case '*': finger[2][1] -= 5; break;
		case 'I': finger[2][2] -= 5; break;
		
		case '$': finger[3][0] -= 5; break;
		case '(': finger[3][1] -= 5; break;
		case 'O': finger[3][2] -= 5; break;
		
		case '%': finger[4][0] -= 5; break;
		case ')': finger[4][1] -= 5; break; 
		case 'P': finger[4][2] -= 5; break;
    }

    glutPostRedisplay();
}

// Main
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tangan");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
