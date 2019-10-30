#include <SOIL/SOIL.h>

#include "global.h"



GLuint loadTexture(const char* file) {

    GLuint textureID = SOIL_load_OGL_texture(
            file,
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
    );

    if (textureID == 0) {
        printf("SOIL error: '%s'\n", SOIL_last_result());
    }

    return textureID;
}