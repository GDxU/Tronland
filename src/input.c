#include "global.h"

void pressedKey(unsigned char key, int x, int y) {
    keyboard[key]=1;
    switch (key){
        case 27:
            exit(0);
            break;
        case '1':
            currentCamera=ONE;
            break;
        case '2':
            currentCamera=TWO;
            break;
        case '3':
            currentCamera=THREE;
            break;
        case '0':
            currentCamera=ZERO;
            currentRide=TOWERFALL;
    }
}

void releasedKey(unsigned char key, int x, int y){
    keyboard[key]=0;
}
