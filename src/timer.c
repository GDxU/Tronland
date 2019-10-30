//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"


void timer(int time){
//    printf("phi, teta  %f %f\n", phi,teta);
    degreeFW++;
    towerFallMovement();
    glutPostRedisplay();
    glutTimerFunc(time, timer, 10);
}

void cameraMovement(int x, int y){

    xChange= x- xMouse;          //xMouse e yMouse são os valores de x e y no frame anterior
    yChange= y- yMouse;

    teta = (teta + xChange/150);//nesse exemplo, usarei coordenadas esféricas para controlar a câmera, assim, ficará mais fácil de enxergar
    phi = (phi - yChange/150); //teta e phi guardam a conversão do vetor 2D para um espaço 3D com coordenada esférica

    if(phi>=180){
        phi=180;  //limite de 180 para o phi
    }


    xMouse = x; //guardam o x e y do mouse para usar na comparação do próximo frame
    yMouse = y;

}

void towerFallMovement(){

    if(waitingdown){
        if(towerfalltimer<100) {
            towerfalltimer++;
        }
        else{
            waitingdown=0;
            goingup=1;
            towerfalltimer=0;
        }
    }

    if(goingup)
        ytowerfallcabins+=0.01;

    if(ytowerfallcabins>=7) {
        goingup = 0;
        waitingup = 1;
    }

    if(waitingup){
        if(towerfalltimer<500)
            towerfalltimer++;
        else{
            waitingup=0;
            towerfalltimer=0;
            falling=1;
        }
    }

    if(falling)
        ytowerfallcabins-=0.1;

    if(ytowerfallcabins<=0) {
        falling = 0;
        waitingdown = 1;
    }

}

