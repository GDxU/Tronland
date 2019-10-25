//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "global.h"

void atualizaCena(int time){
    movimentaCamera();
    glutPostRedisplay();
    glutTimerFunc(time, atualizaCena, 10);
}

void movimentaCamera(){
    if(cameraAtual==UM && keyboard['w'])
        camera.z+=0.1;
    if(cameraAtual==UM && keyboard['s'])
        camera.z-=0.1;
    if(cameraAtual==UM && keyboard['d'])
        camera.x+=0.1;
    if(cameraAtual==UM && keyboard['a'])
        camera.x-=0.1;
}
