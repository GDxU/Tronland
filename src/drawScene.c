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
        if(keyboard['q'] && yCursor>1)
            yCursor-=0.5;
        if(keyboard['e'])
            yCursor+=0.5;

    }



    camera.x = 100*sin(phi)*cos(teta);  //coordenada x denotada em coordenadas esféricas
    camera.z = 100*sin(phi)*sin(teta); //coordenada z denotada em coordenadas esféricas
    camera.y = 100*cos(phi);          //coordenada y denotada em coordenadas esféricas
    //esfera de raio 100


    if(currentCamera==ONE){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
//        printf(" x,y,z %f %f %f\n", xCursor, yCursor, zCursor);
        gluLookAt( xCursor+0, yCursor, zCursor+0,                    //já aqui, a câmera está posicionada no centro da esfera
                   xCursor+camera.x, camera.y, zCursor+camera.z,     //e a câmera estará olhando para a casca da esfera (primeira pessoa)
                   0, 1, 0);                                        //vetor UP, apontando para o eixo Y (para cima)

    }else if(currentCamera==TWO){

        if(currentTopCamera==0) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0, 100, 100,   // Z=200
                      0, 0, 0,    // (0, 0, 0) origem do mundo
                      0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0
        }
        else if(currentTopCamera==1){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(80, 100, 0,   // Z=200
                      0, 0, 0,    // (0, 0, 0) origem do mundo
                      0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0
        }
        else if(currentTopCamera==2){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0, 100, -60,   // Z=200
                      0, 0, 0,    // (0, 0, 0) origem do mundo
                      0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0
        }
        else if(currentTopCamera==3){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-80, 100, 0,   // Z=200
                      0, 0, 0,    // (0, 0, 0) origem do mundo
                      0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0
        }

    }else if(currentCamera==THREE){

        if(currentRide==0){ //FerrisWheel
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-4.5, 12.5, 39,   // posicao da camera
                      -1, 9, 13,    // posicao da FerrisWheel
                      0, 1, 0);  // vetor UP
        }

        if(currentRide==1){ //Carousel
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-28.5, 2, 20.5,   // posicao da camera
                      -28, 1, 8,    // posicao do Carousel
                      0, 1, 0);  // vetor UP
        }


        if(currentRide==2){ //TowerFall
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-11.5, 7.5, -20,   // posicao da camera
                      -9, 4.5, -36,    // posicao do towerfall
                      0, 1, 0);  // vetor UP
        }

        if(currentRide==3){ //TronShip
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-4.5, 12.5, 39,   // posicao da camera
                      -1, 9, 13,    // posicao da FerrisWheel
                      0, 1, 0);  // vetor UP
        }

        if(currentRide==4){ //GlobeOfDeath
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(27, 16.5, -0.5,   // posicao da camera
                      36, 8, 26,    // posicao do GlobeOfDeath
                      0, 1, 0);  // vetor UP
        }



    }

}

void drawScene(){
    printf(" x,y,z %f %f %f\n", xCursor, yCursor, zCursor);
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
    glTranslatef(1,8,1);
    glRotatef(degreeFW,0,0,1);
    drawModel(wheel, "../graphics/obj/wheel.obj");
    glPopMatrix();
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
//    glTranslatef(xCursor,yCursor,zCursor);
    drawModel(carouselStructure, "../graphics/obj/carousel.obj");
    glPushMatrix();
    glTranslatef(0, yCMoto1, 0);
    glRotatef(degreeCarousel,0,1,0);
    drawModel(carouselMoto1, "../graphics/obj/motorcycle1.obj");
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, yCMoto2, 0);
    glRotatef(degreeCarousel,0,1,0);
    drawModel(carouselMoto2, "../graphics/obj/motorcycle2.obj");
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(36, 0, 26);
//    glTranslatef(xCursor,yCursor,zCursor);
    drawModel(globeOfDeath, "../graphics/obj/globeofdeath.obj");
    glPushMatrix();
    glTranslatef(1,8,1);
    glRotatef(degreeGlobeOfDeath,1,0,1);
    drawModel(globeOfDeathMoto, "../graphics/obj/globeofdeathMotorcycle.obj");
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}