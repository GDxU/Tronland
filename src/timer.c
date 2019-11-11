//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"
#include "vector.h"
#include "music.h"

void timer(int time){
//    printf("phi, teta  %f %f\n", phi,teta);
    if(currentScreen==PLAYING){
        updateLighting();
        degreeFW += 0.3;
        degreeGlobeOfDeath+=7.5;
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

    if(ytowerfallcabins<=0.6) {
        falling = 0;
        waitingdown = 1;
    }

}

void updateLighting(){

    lighttimer++;

//    printf("R G B %f %f %f \n",red,green,blue);


//    red = green = blue = 0;

    if(lighttimer<=1000){
        red=1;
        green=1;
        blue=1;
    }

    if(lighttimer>1000 && lighttimer<=1160) {
        red -= 0.0025;
        green -= 0.005;
        blue -= 0.005;
    }

    if(lighttimer>1300 && lighttimer<=1500 && blue<=0.4){
        printf("%d\n",lighttimer);
        red -= 0.003;
        blue += 0.0005;  //noite ideal
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

    vec4 environmentalLight = {{{ red, green, blue, 1.0 }}};
    vec4 diffuseSpecularLight = {{{ red, green, blue, 0.0 }}};
    vec4 positionLight = {{{0, 5.0, 0.0, 0.0 }}};
    vec4 environmentalGlobal = {{{ red, green, blue, 1.0 }}};
    glLightfv(GL_LIGHT0, GL_AMBIENT, environmentalLight.v);   //Global (Sun/Moon)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseSpecularLight.v);
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight.v);
    glEnable(GL_LIGHT0);

    vec4 environmentalLight1 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight1 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 positionLight1 = {{{-1, 8.0, 14.0, 1.0 }}};
    vec4 environmentalGlobal1 = {{{ 0.2, 1, 1, 1.0 }}};  //FerrisWheel
    glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION, 0.3);
    glLightfv(GL_LIGHT1, GL_AMBIENT, environmentalLight1.v);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseSpecularLight1.v);
    glLightfv(GL_LIGHT1, GL_SPECULAR, diffuseSpecularLight1.v);
    glLightfv(GL_LIGHT1, GL_POSITION, positionLight1.v);
    glEnable(GL_LIGHT1);
    
    vec4 environmentalLight2 = {{{ 0, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight2 = {{{ 0, 1, 1, 1.0 }}};
    vec4 positionLight2 = {{{-29.5, 3.5, -11.5, 1 }}};
    vec4 environmentalGlobal2 = {{{ 0.2, 1, 1, 1.0 }}};  //TronLogo
    glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION, 0.1);
    glLightfv(GL_LIGHT2, GL_AMBIENT, environmentalLight2.v);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseSpecularLight2.v);
    glLightfv(GL_LIGHT2, GL_SPECULAR, diffuseSpecularLight2.v);
    glLightfv(GL_LIGHT2, GL_POSITION, positionLight2.v);
    glEnable(GL_LIGHT2);
    
    vec4 environmentalLight3 = {{{ 0, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight3 = {{{ 0, 1, 1, 1.0 }}};
    vec4 positionLight3 = {{{-28, 0, 8.0, 1.0 }}};
    vec4 environmentalGlobal3 = {{{ 0.2, 1, 1, 1.0 }}};  //Carousel
    glLightf(GL_LIGHT3,GL_LINEAR_ATTENUATION, 0.3);
    glLightfv(GL_LIGHT3, GL_AMBIENT, environmentalLight3.v);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseSpecularLight3.v);
    glLightfv(GL_LIGHT3, GL_SPECULAR, diffuseSpecularLight3.v);
    glLightfv(GL_LIGHT3, GL_POSITION, positionLight3.v);
    glEnable(GL_LIGHT3);
    
    vec4 environmentalLight4 = {{{ 0, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight4 = {{{ 0, 1, 1, 1.0 }}};
    vec4 positionLight4 = {{{-7, ytowerfallcabins, -38.0, 1.0 }}};
    vec4 environmentalGlobal4 = {{{ 0.2, 1, 1, 1.0 }}};  //TowerFall
    glLightf(GL_LIGHT4,GL_LINEAR_ATTENUATION, 0.3);
    glLightfv(GL_LIGHT4, GL_AMBIENT, environmentalLight4.v);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseSpecularLight4.v);
    glLightfv(GL_LIGHT4, GL_SPECULAR, diffuseSpecularLight4.v);
    glLightfv(GL_LIGHT4, GL_POSITION, positionLight4.v);
    glEnable(GL_LIGHT4);
    
    vec4 environmentalLight5 = {{{ 0, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight5 = {{{ 0, 1, 1, 1.0 }}};
    vec4 positionLight5 = {{{37, 6.0, 26.0, 1.0 }}};
    vec4 environmentalGlobal5 = {{{ 0.2, 1, 1, 1.0 }}};  //GlobeOfDeath
    glLightf(GL_LIGHT5,GL_LINEAR_ATTENUATION, 0.3);
    glLightfv(GL_LIGHT5, GL_AMBIENT, environmentalLight5.v);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuseSpecularLight5.v);
    glLightfv(GL_LIGHT5, GL_SPECULAR, diffuseSpecularLight5.v);
    glLightfv(GL_LIGHT5, GL_POSITION, positionLight5.v);
    glEnable(GL_LIGHT5);
    
    vec4 environmentalLight6 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight6 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 positionLight6 = {{{56.5, 4.5, 4.5, 1.0 }}};
    vec4 environmentalGlobal6 = {{{ 0.2, 1, 1, 1.0 }}};  //park car
    glLightf(GL_LIGHT6,GL_LINEAR_ATTENUATION, 0.15);
    glLightfv(GL_LIGHT6, GL_AMBIENT, environmentalLight6.v);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuseSpecularLight6.v);
    glLightfv(GL_LIGHT6, GL_SPECULAR, diffuseSpecularLight6.v);
    glLightfv(GL_LIGHT6, GL_POSITION, positionLight6.v);
    glEnable(GL_LIGHT6);
    
    vec4 environmentalLight7 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 diffuseSpecularLight7 = {{{ 0.2, 1, 1, 1.0 }}};
    vec4 positionLight7 = {{{36.5, 5.5, -4.5, 1.0 }}};
    vec4 environmentalGlobal7 = {{{ 0.2, 1, 1, 1.0 }}};
    glLightf(GL_LIGHT7,GL_LINEAR_ATTENUATION, 0.15);
    glLightfv(GL_LIGHT7, GL_AMBIENT, environmentalLight7.v);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuseSpecularLight7.v);
    glLightfv(GL_LIGHT7, GL_SPECULAR, diffuseSpecularLight7.v);
    glLightfv(GL_LIGHT7, GL_POSITION, positionLight7.v);
    glEnable(GL_LIGHT7);
    

}

