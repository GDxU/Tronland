#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "initialize.h"
#include "input.h"
#include "drawScene.h"
#include "timer.h"
#include "vector.h"

//Testing commiting on Clion

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("...");

    glutReshapeFunc(reshape);
    glutDisplayFunc(drawScene);
    glutTimerFunc(10, timer, 10);
    glutPassiveMotionFunc(cameraMovement);
    glutKeyboardFunc(pressedKey);
    glutKeyboardUpFunc(releasedKey);
    glewInit();


    initialize();

    glutMainLoop();
    return 0;
}