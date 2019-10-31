#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "glm.h"
#include "global.h"


void drawModel(GLMmodel* model, char* string){
    if(model==NULL){
        model = glmReadOBJ(string);
        if(!model)
            exit(0);
        glmScale(model, 10.0);
        glmUnitize(model);
        glmFacetNormals(model);
        glmVertexNormals(model, 90.0, 1);
    }
    glmDraw(model, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
}


void cameraPosition(){

    if(keyboard['w'])
        xCursor-=0.5;
    if(keyboard['s'])
        xCursor+=0.5;
    if(keyboard['d'])
        zCursor-=0.5;
    if(keyboard['a'])
        zCursor+=0.5;

    if(/*cameraAtual==DOIS*/1){
        if(keyboard['q'])
            yCursor-=0.5;
        if(keyboard['e'])
            yCursor+=0.5;

    }



    camera.x = 100*sin(phi)*cos(teta);  //coordenada x denotada em coordenadas esféricas
    camera.z = 100*sin(phi)*sin(teta); //coordenada z denotada em coordenadas esféricas
    camera.y = 100*cos(phi);          //coordenada y denotada em coordenadas esféricas
    //esfera de raio 100


    if(currentCamera==ONE) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(xCursor+camera.x, camera.y, zCursor+camera.z,//câmera posicionada na casca da esfera calculada (terceira pessoa)
                  xCursor+0, 0, zCursor+0,                          //centro da esfera, o ponto em que estamos olhando
                  0, 1, 0);                                        //vetor UP, apontando para o eixo Y (para cima)
    }
    else if(currentCamera==TWO){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
//        printf(" x,y,z %f %f %f\n", xCursor, yCursor, zCursor);
        gluLookAt( xCursor+0, yCursor, zCursor+0,                    //já aqui, a câmera está posicionada no centro da esfera
                   xCursor+camera.x, camera.y, zCursor+camera.z,     //e a câmera estará olhando para a casca da esfera (primeira pessoa)
                   0, 1, 0);                                        //vetor UP, apontando para o eixo Y (para cima)

    }else if(currentCamera==THREE){
//        printf(" x,y,z %f %f %f\n", xCursor, yCursor, zCursor);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 100, 100,   // Z=200
                  0, 0, 0,    // (0, 0, 0) origem do mundo
                  0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0


    }else if(currentCamera==ZERO){

        if(keyboard['t'])
            currentRide=TOWERFALL;
        if(keyboard['f'])
            currentRide=FERRISWHEEL;
        if(keyboard['c'])
            currentRide=CAROUSEL;

        if(currentRide==TOWERFALL){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-11.5, 7.5, -20,   // posicao da camera
                      -9, 4.5, -36,    // posicao do towerfall
                      0, 1, 0);  // vetor UP
        }

        if(currentRide==FERRISWHEEL){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-4.5, 12.5, 39,   // posicao da camera
                      -1, 9, 13,    // posicao do towerfall
                      0, 1, 0);  // vetor UP
        }
    }

}

void drawScene(){
//    printf(" x,y,z %f %f %f\n", xCursor, yCursor, zCursor);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,0);
    glClearColor(0,0,0,0);
    cameraPosition();
    glPushMatrix();
    glTranslatef(0.0,0.0,-1.0);
    drawModel(tronland, "../graphics/obj/Tronland.obj");
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2, 0, 13);
    drawModel(ferriswheelBase, "../graphics/obj/ferriswheelbase.obj");
    glPushMatrix();
    glTranslatef(1,8,0);
    glRotatef(degreeFW,0,0,1);
    drawModel(wheel, "../graphics/obj/wheel.obj");
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-7, 0, -49);
    drawModel(towerFall, "../graphics/obj/towerfLL.obj");
    glPushMatrix();
    glTranslatef(0, ytowerfallcabins, 0);
    drawModel(towerFallCabins, "../graphics/obj/towerfallcabins.obj");
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-28, 0, 8);
    drawModel(carouselStructure, "../graphics/obj/carousel.obj");
    glPushMatrix();
    glTranslatef(0, yMoto, 0);
    glRotatef(degreeCarousel,0,1,0);
    drawModel(carouselMotorcycle, "../graphics/obj/motorcycle.obj");
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}