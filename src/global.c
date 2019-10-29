#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "glm.h"

int keyboard[256];

enum Camera{UM, DOIS, TRES};
enum Camera cameraAtual;

enum Brinquedo{RODAGIGANTE, CARROSEL, KAMIKAZE};
enum Brinquedo brinquedoAtual;

typedef struct{
    GLfloat x,y,z;
}vetor3d;
vetor3d camera;

char orthoperspective=1; //1 se perspective 0 se ortho
GLMmodel* principal=NULL;
GLMmodel* rodaGigante=NULL;

float grauRG;
