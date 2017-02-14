#include "bresenham.h"


int main(int argc, char **argv) {
    init();
    menu();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);


    glutCreateWindow("Bresenham algorithm");

    glutDisplayFunc(Display);
    glutReshapeFunc(changeSize);

    timer(0);
    glutMainLoop();
    return 0;
}