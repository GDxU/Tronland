#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm.h"
#include "global.h"

void drawModel(){
    if(modelo==NULL){
        modelo = glmReadOBJ("../graphics/obj/LibertStatue.obj");
        if(!modelo)
            exit(0);
        glmScale(modelo, 10.0);
        glmUnitize(modelo);
        glmFacetNormals(modelo);
        glmVertexNormals(modelo, 90.0, 1);
    }
    glmDraw(modelo, GLM_SMOOTH | GLM_TEXTURE | GLM_COLOR);
}

void desenhaCena(){
    glClearColor(1,1,1,1);
    gluLookAt(0, 0, 0,
                0, 0, 50,
                    0, 1, 0);
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    drawModel();
    glPopMatrix();
    glutSwapBuffers();
}