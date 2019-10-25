#include "global.h"

void teclaPressionada(unsigned char key, int x, int y) {
    keyboard[key]=1;
    switch (key){
        case 27:
            exit(0);
            break;
        case 1:
            cameraAtual=UM;
            break;
        case 2:
            cameraAtual=DOIS;
            break;
    }
}

void teclaLiberada(unsigned char key, int x, int y){
    keyboard[key]=0;
}
