#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "glm.h"

int keyboard[256];

enum Camera{UM, DOIS, TRES};
enum Camera cameraAtual;

enum Brinquedo{RODAGIGANTE, CARROSEL, KAMIKAZE};
enum Brinquedo brinquedoAtual;

int ytowerfallcabins;

int xMouse, yMouse;        //variáveis globais que serão usadas na função posicionaCamera
int xCursor, yCursor, zCursor;//guarda o centro do cursor
float phi, teta;       //ângulos das coordenadas esféricas
double xChange; double yChange; //variáveis que guardam o vetor 2D de movimento do mouse na tela


typedef struct{
    GLfloat x,y,z;
}vetor3d;

vetor3d camera;

char orthoperspective;
GLMmodel* principal;
GLMmodel* ferriswheelBase;
GLMmodel* wheel;
GLMmodel* towerFall;
GLMmodel* towerFallCabins;


float grauRG;

#endif