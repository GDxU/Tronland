#include <GL/glew.h>
#include <GL/freeglut.h>

#include "global.h"

void atualizaCena(int time){
    glutPostRedisplay();
    glutTimerFunc(time, atualizaCena, 10);
}

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
    glMatrixMode(GL_PROJECTION);
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    gluPerspective(45.0f, 1920/1080, 1, 100);

}