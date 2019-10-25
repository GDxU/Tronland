#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "glm.h"

int keyboard[256];

enum Camera{UM, DOIS};
enum Camera cameraAtual;

enum Brinquedo{RODAGIGANTE, CARROSEL, KAMIKAZE};
enum Brinquedo brinquedoAtual;

typedef struct{
    GLfloat x,y,z;
}vetor3d;

vetor3d camera;

char orthoperspective;
GLMmodel* modelo;

#endif