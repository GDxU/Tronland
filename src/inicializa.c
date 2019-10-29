#include <GL/glew.h>
#include <GL/freeglut.h>

#include "global.h"
#include "vetor.h"
#include "glm.h"

void redimensiona(int w, int h) {
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if(orthoperspective==1)
        gluPerspective(45, ((float)w)/h, 1, 1000);
    else
        glOrtho(-100, 100, -100, 100, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inicializa(){
    orthoperspective=1;
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    vec4 luzAmbiente = {{{ 0.3, 0.3, 0.3, 1.0 }}};
    vec4 luzDifusaEspecular = {{{ 1.0, 1.0, 1.0, 0.0 }}};
    vec4 luzPosicao = {{{-1.0, -1.0, 0.0, 0.0 }}};
    vec4 ambienteGlobal = {{{ 0.3, 0.3, 0.3, 1.0 }}};
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente.v);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusaEspecular.v);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzDifusaEspecular.v);
    glLightfv(GL_LIGHT0, GL_POSITION, luzPosicao.v);

    glEnable(GL_LIGHT0);


    principal = glmReadOBJ("../graphics/obj/Tronland.obj");
    rodaGigante = glmReadOBJ("../graphics/obj/roda_gigante_inteira.obj");

    xCursor= 0;
    yCursor= 0; //a câmera começa olhando para o ponto 0
    zCursor= 0;

    camera.x=0;
    camera.y=1;
    camera.z=0;

    phi=90, teta=0;
    xMouse=0, yMouse=0;

    grauRG=0;

    cameraAtual=UM;
}