/*
=================================== ===== ==== === == = =  =   =    =     =
|File     : sdl_wrapper.h
|Author   : Thomas Heegaard
|Created  : 10/28/2014
|Purpose  : 
|
|Comments : 
|
=================================== ===== ==== === == = =  =   =    =     =
*/

#ifndef SDL_WRAPPER_H
#define SDL_WRAPPER_H

#include "global_defines.h"
#include "texture_bank.h"
#include <SDL2/SDL.h>

//======================================================================================
//                  DATA
//======================================================================================

typedef struct Screen
{
    SDL_Window*     window;
    SDL_Renderer*   renderer;
} Screen;

extern SDL_Texture** texture_bank;

//======================================================================================
//                  DEFINITIONS
//======================================================================================

#define TRANSP_R    255
#define TRANSP_G    0
#define TRANSP_B    255

//======================================================================================
//                  FUNCTIONS
//======================================================================================
ERR InitSDL();

//======================================================================================
ERR LoadTexture(unsigned short texture_id);

//======================================================================================
ERR DrawTexture(unsigned short texture_id, float angle, 
                SDL_Rect* src_rect, SDL_Rect* dst_rect);

//======================================================================================
void FreeTexture(unsigned short texture_id);

//======================================================================================
ERR ClearScreen();

//======================================================================================
ERR UpdateScreen();

//======================================================================================
ERR ExitSDL();

#endif //SDL_WRAPPER_H
