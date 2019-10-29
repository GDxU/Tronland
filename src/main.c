#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "inicializa.h"
#include "input.h"
#include "desenhaCena.h"
#include "atualiza.h"
#include "vetor.h"

//Testing commiting on Clion

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("...");

    glutReshapeFunc(redimensiona);
    glutDisplayFunc(desenhaCena);
    glutTimerFunc(10, atualizaCena, 10);
    glutPassiveMotionFunc(movimentaCamera);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glewInit();
    inicializa();


    glutMainLoop();
    return 0;
}