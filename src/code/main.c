#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitContextVersion(2, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("...");

    glutReshapeFunc(redimensiona);
    glutDisplayFunc(desenhaCena);
    glutIdleFunc(atualiza);
    glutTimerFunc(0, atualizaFPS, 1000);
    glutKeyboardFunc(teclado);

    glewInit();
    inicializa();


    glutMainLoop();
    return 0;
}