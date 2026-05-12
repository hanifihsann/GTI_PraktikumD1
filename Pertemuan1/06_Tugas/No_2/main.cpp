#include <gl/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-0.9f, 0.6f);
        glVertex2f(-0.7f, 0.6f);
    glEnd();

    // 2. GL_LINE_LOOP
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4f, 0.8f);
        glVertex2f(-0.5f, 0.6f);
        glVertex2f(-0.3f, 0.6f);
    glEnd();

    // 3. GL_TRIANGLE_FAN
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.9f, 0.3f);
        glVertex2f(-0.9f, -0.3f);

        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.3f, -0.3f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.9f, 0.3f);
        glVertex2f(-0.9f, -0.3f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.3f, -0.3f);
    glEnd();

    // 4. GL_TRIANGLE_STRIP 
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.6f, -0.3f);
        glVertex2f(-0.4f, -0.3f);
        glVertex2f(-0.65f, -0.6f);
        glVertex2f(-0.45f, -0.6f);
    glEnd();

    // 5. GL_QUADS 
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.3f);
    glEnd();

    // 6. GL_QUAD_STRIP 
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.55f, -0.1f);
        glVertex2f(0.55f, -0.4f);
        glVertex2f(0.65f, -0.1f);
        glVertex2f(0.65f, -0.4f);
        glVertex2f(0.75f, -0.1f);
        glVertex2f(0.75f, -0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Primitive OpenGL Rapi");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
