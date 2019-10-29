//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"


void atualizaCena(int time){
//    printf("phi, teta  %f %f\n", phi,teta);
    grauRG++;
    glutPostRedisplay();
    glutTimerFunc(time, atualizaCena, 10);
}

void movimentaCamera(int x, int y){
    printf("x do mouse: %d\n",x);
    printf("y do mouse: %d\n",y);
    xChange= x- xMouse;          //xMouse e yMouse são os valores de x e y no frame anterior
    yChange= y- yMouse;
    printf("xChange: %d\n",xChange);
    printf("yChange: %d\n",yChange);

    teta = (teta + xChange/150);//nesse exemplo, usarei coordenadas esféricas para controlar a câmera, assim, ficará mais fácil de enxergar
    phi = (phi - yChange/150); //teta e phi guardam a conversão do vetor 2D para um espaço 3D com coordenada esférica

    if(phi>=180){
        phi=180;  //limite de 180 para o phi
    }


    xMouse = x; //guardam o x e y do mouse para usar na comparação do próximo frame
    yMouse = y;


}

