//#include <gl/glut.h>
//
//void Kubus(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 0.6f, 0.1f);
//
//    // Bawah
//    glVertex3f(-0.10f, -0.60f, 0.0f);
//    glVertex3f(0.10f, -0.60f, 0.0f);
//    glVertex3f(0.10f, -0.40f, 0.0f);
//    glVertex3f(-0.10f, -0.40f, 0.0f);
//
//    // Tengah (kiri)
//    glVertex3f(-0.22f, -0.39f, 0.0f);
//    glVertex3f(-0.02f, -0.39f, 0.0f);
//    glVertex3f(-0.02f, -0.19f, 0.0f);
//    glVertex3f(-0.22f, -0.19f, 0.0f);
//
//    // Tengah (kanan)
//    glVertex3f(0.02f, -0.39f, 0.0f);
//    glVertex3f(0.22f, -0.39f, 0.0f);
//    glVertex3f(0.22f, -0.19f, 0.0f);
//    glVertex3f(0.02f, -0.19f, 0.0f);
//
//    // Atas (kiri)
//    glVertex3f(-0.34f, -0.18f, 0.0f);
//    glVertex3f(-0.14f, -0.18f, 0.0f);
//    glVertex3f(-0.14f, 0.02f, 0.0f);
//    glVertex3f(-0.34f, 0.02f, 0.0f);
//
//    // Atas (tengah)
//    glVertex3f(-0.10f, -0.18f, 0.0f);
//    glVertex3f(0.10f, -0.18f, 0.0f);
//    glVertex3f(0.10f, 0.02f, 0.0f);
//    glVertex3f(-0.10f, 0.02f, 0.0f);
//
//    // Atas (kanan)
//    glVertex3f(0.14f, -0.18f, 0.0f);
//    glVertex3f(0.34f, -0.18f, 0.0f);
//    glVertex3f(0.34f, 0.02f, 0.0f);
//    glVertex3f(0.14f, 0.02f, 0.0f);
//
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char* argv[]) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(640, 480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("Kubus Bertingkat");
//    glutDisplayFunc(Kubus);
//
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//    glutMainLoop();
//    return 0;
//}
