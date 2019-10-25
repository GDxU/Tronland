#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm.h"
#include "global.h"


void drawModel(){
    if(modelo==NULL){
        modelo = glmReadOBJ("../graphics/obj/Tronland.obj");
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
    if(cameraAtual==UM) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(camera.x, camera.y, camera.z,   //posicao do olho
                  0, 0, -1,                        //para onde olhamos
                  0, 1, 0);                       //onde fica o pra cima
    }
    else{

    }

}

void desenhaCena(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,0);
    glClearColor(1,1,1,1);
    posicionaCamera();
    glPushMatrix();
    glTranslatef(0.0,0.0,-1.0);
    drawModel();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5.0,0.0,-21.0);
    glutSolidSphere(10,1,1);
    glPopMatrix();
    glutSwapBuffers();
}