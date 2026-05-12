#include <GL/glut.h>
#include <math.h>

void drawCircle(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawTriangle(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y);
        glVertex2f(x + size/2, y + size);
        glVertex2f(x + size, y);
    glEnd();
}

void drawCloud(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    drawCircle(0, 0, 30, 1, 1, 1);
    drawCircle(25, 15, 30, 1, 1, 1);
    drawCircle(50, 0, 30, 1, 1, 1);
    drawCircle(25, -5, 25, 1, 1, 1);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. LANGIT
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.7f, 1.0f); 
    glVertex2i(0, 300); glVertex2i(800, 300);
    glVertex2i(800, 600); glVertex2i(0, 600);
    glEnd();

    // 2. RUMPUT
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.8f, 0.2f); 
    glVertex2i(0, 0); glVertex2i(800, 0);
    glVertex2i(800, 300); glVertex2i(0, 300);
    glEnd();

    // 3. MATAHARI 
    glPushMatrix();
    glTranslatef(650, 500, 0);
    drawCircle(0, 0, 60, 1.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3);
    for (int i = 0; i < 360; i += 30) {
        glPushMatrix();
        glRotatef(i, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(75, 0); glVertex2f(115, 0);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    // 4. AWAN
    drawCloud(150, 520);
    drawCloud(400, 550);
    drawCloud(700, 480);

    // 5. REL 
    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(1);
    for (int i = 0; i <= 800; i += 40) {
        glBegin(GL_POLYGON);
        glVertex2f(i, 230); glVertex2f(i + 12, 230);
        glVertex2f(i + 12, 280); glVertex2f(i, 280);
        glEnd();
    }
    glBegin(GL_LINES); 
    glVertex2i(0, 255); glVertex2i(800, 255);
    glEnd();

    // 6. KERETA API 
    glPushMatrix();
    glTranslatef(40, 240, 0);
    
    // Roda Kereta 
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(10, -5); glVertex2i(35, -5); glVertex2i(35, 10); glVertex2i(10, 10);
    glVertex2i(65, -5); glVertex2i(90, -5); glVertex2i(90, 10); glVertex2i(65, 10);
    glVertex2i(125, -5); glVertex2i(150, -5); glVertex2i(150, 10); glVertex2i(125, 10);
    glVertex2i(175, -5); glVertex2i(200, -5); glVertex2i(200, 10); glVertex2i(175, 10);
    glEnd();

    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 10); glVertex2i(100, 10); glVertex2i(100, 80); glVertex2i(0, 80);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(15, 80); glVertex2i(45, 80); glVertex2i(45, 110); glVertex2i(15, 110);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); glVertex2i(100, 30); glVertex2i(120, 30); glEnd();

    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(120, 10); glVertex2i(220, 10); glVertex2i(220, 70); glVertex2i(120, 70);
    glEnd();
    glPopMatrix();

    // 7. JALAN RAYA 
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2i(0, 80); glVertex2i(800, 80);
    glVertex2i(800, 180); glVertex2i(0, 180);
    glEnd();

    // 8. MOBIL MERAH 
    glPushMatrix();
    glTranslatef(280, 120, 0);
    
    glColor3f(0.85f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0); glVertex2i(320, 0); glVertex2i(320, 90); glVertex2i(0, 90);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2i(40, 90); glVertex2i(100, 170); glVertex2i(240, 170); glVertex2i(290, 90);
    glEnd();
    glBegin(GL_LINES); 
    glVertex2i(160, 90); glVertex2i(160, 170);
    glEnd();

    glPushMatrix();
    glTranslatef(70, 0, 0); drawCircle(0, 0, 42, 0.5f, 0.5f, 0.5f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(250, 0, 0); drawCircle(0, 0, 42, 0.5f, 0.5f, 0.5f);
    glPopMatrix();
    glPopMatrix();

    // 9. SEMAK 
    glPushMatrix();
    glTranslatef(60, 180, 0);
    drawTriangle(0, 0, 50, 0, 0.4f, 0);
    drawTriangle(30, 0, 50, 0, 0.4f, 0);
    drawTriangle(60, 0, 50, 0, 0.4f, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650, 60, 0);
    drawTriangle(0, 0, 60, 0, 0.4f, 0);
    drawTriangle(40, 0, 60, 0, 0.4f, 0);
    drawTriangle(80, 0, 60, 0, 0.4f, 0);
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 650);
    glutCreateWindow("Mobil 2D");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
