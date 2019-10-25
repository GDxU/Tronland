#include <GL/glew.h>
#include <GL/freeglut.h>

#include "global.h"

void redimensiona(int w, int h) {
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if(orthoperspective==1)
        gluPerspective(45, ((float)w)/h, 1, 100);
    else
        glOrtho(-100, 100, -100, 100, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inicializa(){
    orthoperspective=1;
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);

    modelo=NULL;

    camera.x=0;
    camera.y=1;
    camera.z=0;

    cameraAtual=UM;
}