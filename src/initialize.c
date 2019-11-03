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


    red = green = blue = 1;
    lighttimer=0;


    tronland = glmReadOBJ("../graphics/obj/Tronland.obj");
    ferriswheelBase = glmReadOBJ("../graphics/obj/ferriswheelbase.obj");
    wheel = glmReadOBJ("../graphics/obj/wheel.obj");
    towerFall = glmReadOBJ("../graphics/obj/towerfLL.obj");
    towerFallCabins = glmReadOBJ("../graphics/obj/towerfallcabins.obj");
    carouselStructure = glmReadOBJ("../graphics/obj/carousel.obj");
    carouselMoto1 = glmReadOBJ("../graphics/obj/motorcycle1.obj");
    carouselMoto2 = glmReadOBJ("../graphics/obj/motorcycle2.obj");
    globeOfDeath = glmReadOBJ("../graphics/obj/globeofdeath.obj");
    globeOfDeathMoto = glmReadOBJ("../graphics/obj/globeofdeathMotorcycle.obj");


    ytowerfallcabins=0;
    falling=0;
    goingup=0;
    waitingup=0;      //tower fall variables
    waitingdown=1;
    towerfalltimer=0;


    xCursor= 0;
    yCursor= 2; //a câmera começa olhando para o ponto 0
    zCursor= 0;

    camera.x=0;
    camera.y=1;
    camera.z=0;

    phi=90, teta=0;
    xMouse=0, yMouse=0;

    degreeFW=0;
    degreeCarousel=0;
    degreeGlobeOfDeath=0;
    yCMoto1=-0.5;
    yCMoto2=0.5;
    carouselTimer=0;

    currentCamera=TWO;
    currentTopCamera=0;
    currentScreen=MENU;
}