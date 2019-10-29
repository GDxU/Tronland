#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm.h"
#include "global.h"


void drawModel(GLMmodel* modelo, char* string){
    if(modelo==NULL){
        modelo = glmReadOBJ(string);
        if(!modelo)
            exit(0);
        glmScale(modelo, 10.0);
        glmUnitize(modelo);
        glmFacetNormals(modelo);
        glmVertexNormals(modelo, 90.0, 1);
    }
    glmDraw(modelo, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
}


void posicionaCamera(){

    camera.x = 100*sin(phi)*cos(teta);  //coordenada x denotada em coordenadas esféricas
    camera.z = 100*sin(phi)*sin(teta); //coordenada z denotada em coordenadas esféricas
    camera.y = 100*cos(phi);          //coordenada y denotada em coordenadas esféricas
    //esfera de raio 100


    if(cameraAtual==UM) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(xCursor+camera.x, camera.y, zCursor+camera.z,//câmera posicionada na casca da esfera calculada (terceira pessoa)
                  xCursor+0, 0, zCursor+0,                          //centro da esfera, o ponto em que estamos olhando
                  0, 1, 0);                                        //vetor UP, apontando para o eixo Y (para cima)
    }
    else if(cameraAtual==DOIS){
        gluLookAt( xCursor+0, 0, zCursor+0,                    //já aqui, a câmera está posicionada no centro da esfera
                   xCursor+camera.x, camera.y, zCursor+camera.z,     //e a câmera estará olhando para a casca da esfera (primeira pessoa)
                   0, 1, 0);                                        //vetor UP, apontando para o eixo Y (para cima)

    }else if(cameraAtual==TRES){
        gluLookAt(0, 0, 200,   // Z=200
                  0, 0, 0,    // (0, 0, 0) origem do mundo
                  0, 1, 0);  //nesse exemplo mais simples, estamos no ponto Z=200 olhando para o ponto 0


    }

}

void desenhaCena(){



    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,0);
    glClearColor(0,0,0,0);
    posicionaCamera();
    glPushMatrix();
    glTranslatef(0.0,0.0,-1.0);
    drawModel(principal, "../graphics/obj/Tronland.obj");
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.068,0.0,-1.0);
    glRotatef(grauRG,0,0,1);
    drawModel(rodaGigante, "../graphics/obj/roda_gigante_inteira.obj");
    glPopMatrix();
    glColor3f(0,0,0);
    glutSolidSphere(1000,1,1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(28.0,0.0,-1.0);
    glutSolidSphere(1000,1,1);
    glPopMatrix();
    glutSwapBuffers();
}