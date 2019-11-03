#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "glm.h"

int keyboard[256];

enum Camera{ONE, TWO, THREE};
enum Camera currentCamera;

enum Screen{MENU, PLAYING};
enum Screen currentScreen;

int currentRide;
int currentTopCamera;

float ytowerfallcabins;
int falling;
int goingup;
int waitingup;
int waitingdown;
int towerfalltimer;

float red, green, blue;
int lighttimer;


int xMouse, yMouse;        //variáveis globais que serão usadas na função posicionaCamera
float xCursor, yCursor, zCursor;//guarda o centro do cursor
float phi, teta;       //ângulos das coordenadas esféricas
double xChange; double yChange; //variáveis que guardam o vetor 2D de movimento do mouse na tela


typedef struct{
    GLfloat x,y,z;
}vetor3d;
vetor3d camera;

char orthoperspective=1; //1 se perspective 0 se ortho
GLMmodel* tronland=NULL;
GLMmodel* ferriswheelBase=NULL;
GLMmodel* wheel=NULL;
GLMmodel* towerFall=NULL;
GLMmodel* towerFallCabins=NULL;
GLMmodel* carouselStructure=NULL;
GLMmodel* carouselMoto1=NULL;
GLMmodel* carouselMoto2=NULL;
GLMmodel* globeOfDeath=NULL;
GLMmodel* globeOfDeathMoto=NULL;


float degreeFW;
float degreeCarousel;
float degreeGlobeOfDeath;
float yCMoto1;
float yCMoto2;
int carouselTimer;