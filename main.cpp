#include <iostream>
#include <GL/freeglut.h>

void Display(void){
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 240);


    glutCreateWindow("Bounce");

    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}