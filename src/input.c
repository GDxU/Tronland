#include "global.h"
#include "music.h"

void pressedKey(unsigned char key, int x, int y) {
    keyboard[key]=1;
    switch (key) {
        case 27:
            exit(0);
            break;
        case '1':
            if(currentScreen==PLAYING){
                currentCamera = ONE;
                yCursor = 2;
            }
            break;
        case '2':
            if(currentScreen==PLAYING)
                currentCamera = TWO;
            break;
        case '3':
            if(currentScreen==PLAYING){
                currentCamera = THREE;
                currentRide = 0;
            }
            break;
        case 'a':
            if(currentScreen==PLAYING){
/*               if (currentCamera == TWO) {
                   currentTopCamera--;
                   if (currentTopCamera == -1)
                       currentTopCamera = 3;
               }*/
                if (currentCamera == THREE){
                    currentRide--;
                    if(currentRide == -1)
                        currentRide = 3;
                }
            }    
            break;
        case 'd':
            if(currentScreen==PLAYING){            
/*               if (currentCamera == TWO) {
                       currentTopCamera++;
                   if (currentTopCamera == 4)
                       currentTopCamera = 0;
               }*/
                if (currentCamera == THREE){
                    currentRide++;
                    if(currentRide == 4)
                        currentRide = 0;
                }
            }    
            break;
        case 'w':
            if(currentScreen==MENU){
                if(currentButton==EXIT){
                    play_music(choise,3,0);
                    currentButton=START;
                }
            }    
            break;
        case 's':
            if(currentScreen==MENU){
                if(currentButton==START){
                    currentButton=EXIT;
                    play_music(choise,3,0);
                }
            }    
            break;
        case 'l':
            if(currentScreen==PLAYING){
                if(lightingswitch==1){
                    glDisable(GL_LIGHTING);
                    lightingswitch=0;
                }    
                else{
                    glEnable(GL_LIGHTING);
                    lightingswitch=1;
                }
            }
            break;
        case 'n':
            if(currentScreen==PLAYING){
                if(fogswitch==1){
                    glDisable(GL_FOG);
                    fogswitch=0;
                }    
                else{
                    glEnable(GL_FOG);
                    fogswitch=1;
                }
            }
            break;
        case 'p':
            if(currentScreen==PLAYING){
                orthoperspective=0;
                glDisable(GL_LIGHTING);
                currentScreen=PAUSE;
            }
            else if(currentScreen==PAUSE){
                orthoperspective=1;
                glEnable(GL_LIGHTING);
                currentScreen=PLAYING;
            }
            break;
        case 13:
            if(currentScreen==MENU){
                if(currentButton==START) {
                    currentScreen = PLAYING;
                    glEnable(GL_LIGHTING);
                    glEnable(GL_DEPTH_TEST);
                    orthoperspective = 1;
                    stop_music(1);
                    play_music(playingMusic,2,-1);
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
