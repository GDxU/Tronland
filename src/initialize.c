#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"
#include "vector.h"
#include "glm.h"

void reshape(int w, int h) {
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

void initialize(){

    orthoperspective=1;

    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    vec4 environmentalLight = {{{ 0.5, 0, 0.5, 1.0 }}};
    vec4 diffuseSpecularLight = {{{ 1.0, 1.0, 1.0, 0.0 }}};
    vec4 positionLight = {{{0, 5.0, 0.0, 0.0 }}};
    vec4 environmentalGlobal = {{{ 0.5, 1, 0.5, 1.0 }}};
    glLightfv(GL_LIGHT0, GL_AMBIENT, environmentalLight.v);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight.v);
    glEnable(GL_LIGHT0);


    tronland = glmReadOBJ("../graphics/obj/Tronland.obj");
    ferriswheelBase = glmReadOBJ("../graphics/obj/ferriswheelbase.obj");
    wheel = glmReadOBJ("../graphics/obj/wheel.obj");
    towerFall = glmReadOBJ("../graphics/obj/towerfLL.obj");
    towerFallCabins = glmReadOBJ("../graphics/obj/towerfallcabins.obj");

    ytowerfallcabins=0;
    falling=0;
    goingup=0;
    waitingup=0;      //tower fall variables
    waitingdown=1;
    towerfalltimer=0;


    xCursor= 0;
    yCursor= 0; //a câmera começa olhando para o ponto 0
    zCursor= 0;

    camera.x=0;
    camera.y=1;
    camera.z=0;

    phi=90, teta=0;
    xMouse=0, yMouse=0;

    degreeFW=0;

    currentCamera=THREE;
}