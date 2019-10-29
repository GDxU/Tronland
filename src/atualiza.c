//
// Created by marcus on 22/10/2019.
//
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "global.h"


void atualizaCena(int time){
    printf("%d %d %d\n", camera.x, camera.y, camera.z);
    grauRG++;
    movimentaCamera();
    glutPostRedisplay();
    glutTimerFunc(time, atualizaCena, 10);
}

void movimentaCamera(){
    if(cameraAtual==UM && keyboard['w'])
        camera.z+=0.1;
    if(cameraAtual==UM && keyboard['s'])
        camera.z-=0.1;
    if(cameraAtual==UM && keyboard['d'])
        camera.x+=0.1;
    if(cameraAtual==UM && keyboard['a'])
        camera.x-=0.1;
    if(cameraAtual==UM && keyboard['e'])
        camera.y+=0.1;
    if(cameraAtual==UM && keyboard['q'])
        camera.y-=0.1;

}
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int xMouse=0, yMouse=0;        //variáveis globais que serão usadas na função posicionaCamera
int xCursor, yCursor, zCursor;//guarda o centro do cursor
int modoCAM=1;               //variável responsável por guardar o modo de câmera que está sendo utilizado
float phi=90, teta=0;       //ângulos das coordenadas esféricas

struct camera
{
    float x, y, z;   //definindo a estrutura de dados que representará as coordenadas da câmera
}camera;


void teclado(unsigned char key, int x, int y) {//capturar quando uma tecla é pressionada
    switch (key) {
        case 27:    //aperte ESC para fechar
            exit(0);
            break;
        case 's':   //andar pelo plano X-Z utilizando W A S D
            xCursor++;
            break;
        case 'w':
            xCursor--;
            break;
        case 'a':
            zCursor++;
            break;
        case 'd':
            zCursor--;
            break;
        case '1':
            modoCAM=1; //aperte 1 para modo terceira pessoa
            break;
        case '2':
            modoCAM=2;//aperte 2 para modo primeira pessoa
            break;
        case '3':
            modoCAM=3;//aperte 3 para câmera simples
        default:
            break;
    }
}

void posicionaCamera(int x, int y){//capturar posicionamento do mouse
    double xChange; double yChange; //variáveis que guardam o vetor 2D de movimento do mouse na tela
    xChange= x- xMouse;          //xMouse e yMouse são os valores de x e y no frame anterior
    yChange= y- yMouse;

    teta= (teta+ xChange/150);//nesse exemplo, usarei coordenadas esféricas para controlar a câmera, assim, ficará mais fácil de enxergar
    phi= (phi- yChange/150); //teta e phi guardam a conversão do vetor 2D para um espaço 3D com coordenada esférica

    if(phi>=180){
        phi=180;  //limite de 180 para o phi
    }


    xMouse = x; //guardam o x e y do mouse para usar na comparação do próximo frame
    yMouse = y;

    glutPostRedisplay(); //redisplay ao movimentar, evitando lag quando o usuário movimentar muito rapidamente a câmera
}

void frame(int time){//função que tratará a taxa de atualização, nesse caso, próximo de 60fps (1000/16 = 62.5 fps)

    glutPostRedisplay();
    glutTimerFunc(time, frame, 10);
}

void redimensiona(int w, int h){//função que tratará o redimensionamento da tela

    glEnable(GL_DEPTH_TEST);                // Ativa o Z buffer
    glViewport (0, 0, w, h);               //define a proporção da janela de visualização
    glMatrixMode (GL_PROJECTION);         //define o tipo de matriz de transformação que será utilizada
    glLoadIdentity();                    //carrega a matriz identidade do tipo GL_PROJECTION configurado anteriormente
    gluPerspective(60.0, (float)w/(float)h, 0.2, 400.0);   //funciona como se fosse o glOrtho, mas para o espaço 3D
    glMatrixMode(GL_MODELVIEW);                           //ativa o modo de matriz de visualização para utilizar o LookAt
}

void inicializa(){
    glClearColor(1, 1, 1, 1);                            //cor de fundo branca
    glEnable(GL_BLEND);                                 //ativa a mesclagem de cores
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //ativando o blend, podemos criar objetos transparentes
    xCursor= 0;                                       //a câmera começa olhando para o ponto 0
    yCursor= 0;
    zCursor= 0;
}

void desenhaCena(){//função que desenhará tudo o que aparece na tela


    switch(modoCAM){ //define um LookAt diferente para cada modo da câmera, veja abaixo o uso de cada um
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }

    glColor4f(0, 0, 0, 1);//começa a desenhar com a cor preta
    glutWireTeapot(50);  //desenha uma jarra em preto

    glPushMatrix();
    glColor4f(0.5, 0.5, 0.5, 1); //começa a desenhar com a cor cinza
    glTranslatef(0, -100, 0);   //desenha no ponto Y=-100 para parecer uma mesa para a jarra
    glutSolidCube(100);        //desenha um cubo no ponto (0, -100, 0)
    glColor4f(0, 0, 0, 1);    //começa a desenhar com a cor preta
    glutWireCube(105);       //desenha bordas de um cubo levemente maior
    glPopMatrix();

    glutSwapBuffers();     //SwapBuffers funciona como o Flush, mas para o modo de buffer duplo
}

