#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "glm.h"
#include "music.h"

int keyboard[256];

enum Camera{ONE, TWO, THREE};
enum Camera currentCamera;

enum Screen{MENU, PLAYING, PAUSE, EXITING};
enum Screen currentScreen;

enum Button{START, EXIT};
enum Button currentButton;

int currentRide;
int currentTopCamera;
int lightingswitch;

int pauseSwitch;

float ytowerfallcabins;
int falling;
int goingup;
int waitingup;
int waitingdown;
int towerfalltimer;

float degreeFW;
float degreeCarousel;
float degreeGlobeOfDeath;
float yCMoto1;
float yCMoto2;
int carouselTimer;

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

char orthoperspective=1; //1 if perspective 0 if ortho
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

GLuint idMenu;
GLuint idStart;
GLuint idSelectedStart;
GLuint idExit;
GLuint idSelectedExit;
GLuint idPause;

Mix_Chunk * menuMusic;
Mix_Chunk * playingMusic;
Mix_Chunk * choise;