//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"
#include "vector.h"


void timer(int time){
//    printf("phi, teta  %f %f\n", phi,teta);
    if(currentScreen==PLAYING){
        updateLighting();
        degreeFW += 0.1;
        degreeGlobeOfDeath += 5;
        towerFallMovement();
        carouselMovement();
    }
    
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

void carouselMovement(){
    degreeCarousel -= 1;

    carouselTimer++;

    if(carouselTimer<150) {
        yCMoto1 += 0.01;
        yCMoto2 -= 0.01;
    }
    else if(carouselTimer<300) {
        yCMoto1 -= 0.01;
        yCMoto2 += 0.01;
    }
    else
        carouselTimer=0;

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
        ytowerfallcabins+=0.03;

    if(ytowerfallcabins>=14) {
        goingup = 0;
        waitingup = 1;
    }

    if(waitingup){
        if(towerfalltimer<250)
            towerfalltimer++;
        else{
            waitingup=0;
            towerfalltimer=0;
            falling=1;
        }
    }

    if(falling)
        ytowerfallcabins-=0.2;

    if(ytowerfallcabins<=0.5) {
        falling = 0;
        waitingdown = 1;
    }

}

void updateLighting(){

   if(keyboard['l'] && lightingswitch%2!=0){
        glDisable(GL_LIGHTING);
        lightingswitch++;
   }     
   if(keyboard['l'] && lightingswitch%2==0){
        glEnable(GL_LIGHTING);
        lightingswitch++;
   }     

   lighttimer++;
//    printf("R G B %f %f %f \n",red,green,blue);


//    red = green = blue = 0.5;

    if(lighttimer<=1000){
        red=1;
        green=1;
        blue=1;
    }

    if(lighttimer>1000 && lighttimer<=1160) {
        red -= 0.001;
        green -= 0.005;
        blue -= 0.005;
    }

    if(lighttimer>1300 && lighttimer<=1500 && blue<=0.4){
        printf("%d\n",lighttimer);
        red -= 0.003;
        blue += 0.001;  //noite ideal
        green -= 0.001;
    }

    if(lighttimer>2300){
        if(red<1)
            red += 0.002;
        if(blue<1)
            blue += 0.001;
        if(green<1)
            green += 0.002;
    }

    if(lighttimer>2300 && red>1 && green>1 && blue>1) {
        lighttimer = 0;
        red=1;
        green=1;
        blue=1;
    }

/*    if(lighttimer>1300 && lighttimer<2500){

        vec4 environmentalLight1 = {{{ 0.1, 0.1, 0.1, 1.0 }}};
        vec4 diffuseSpecularLight1 = {{{ 1, 0, 1, 0.0 }}};
        vec4 positionLight1 = {{{-2, 8.0, 13.0, 0.0 }}};
        vec4 environmentalGlobal1 = {{{ 0.1, 0.1, 0.1, 1.0 }}};
        glLightfv(GL_LIGHT1, GL_AMBIENT, environmentalLight1.v);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseSpecularLight1.v);
        glLightfv(GL_LIGHT1, GL_SPECULAR, diffuseSpecularLight1.v);
        glLightfv(GL_LIGHT1, GL_POSITION, positionLight1.v);
        glEnable(GL_LIGHT1);

    }
*/

    vec4 environmentalLight = {{{ red, green, blue, 1.0 }}};
    vec4 diffuseSpecularLight = {{{ red, green, blue, 0.0 }}};
    vec4 positionLight = {{{0, 5.0, 0.0, 0.0 }}};
    vec4 environmentalGlobal = {{{ red, green, blue, 1.0 }}};
    glLightfv(GL_LIGHT0, GL_AMBIENT, environmentalLight.v);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight.v);
    glEnable(GL_LIGHT0);

}

