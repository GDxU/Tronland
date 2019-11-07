#include "global.h"

void pressedKey(unsigned char key, int x, int y) {
    keyboard[key]=1;
    switch (key) {
        case 27:
            exit(0);
            break;
        case '1':
            currentCamera = ONE;
            yCursor = 2;
            break;
        case '2':
            currentCamera = TWO;
            break;
        case '3':
            currentCamera = THREE;
            currentRide = 0;
            break;
        case 'a':
//            if (currentCamera == TWO) {
//                currentTopCamera--;
//                if (currentTopCamera == -1)
//                    currentTopCamera = 3;
//            }
            if (currentCamera == THREE){
                currentRide--;
                if(currentRide == -1)
                    currentRide = 3;
            }
            break;
        case 'd':
//            if (currentCamera == TWO) {
//                    currentTopCamera++;
//                if (currentTopCamera == 4)
//                    currentTopCamera = 0;
//            }
            if (currentCamera == THREE){
                currentRide++;
                if(currentRide == 4)
                    currentRide = 0;
            }
            break;
        case 'w':
            if(currentScreen==MENU)
                currentButton=START;
            break;
        case 's':
            if(currentScreen==MENU)
                currentButton=EXIT;
            break;
        case 13:
            if(currentScreen==MENU){
                if(currentButton==START) {
                    currentScreen = PLAYING;
                    glEnable(GL_LIGHTING);
                    glEnable(GL_DEPTH_TEST);
                    orthoperspective = 1;
                }
                else
                    exit(0);
            }
            break;
    }
}

void releasedKey(unsigned char key, int x, int y){
    keyboard[key]=0;
}
