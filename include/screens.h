/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Screens Functions Declarations (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2021 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef SCREENS_H
#define SCREENS_H

typedef enum GameScreen {
    TITLE = 0
} GameScreen;

extern GameScreen current_screen;
extern Font font;
extern Music music;
extern Sound fxCoin;

#ifdef __cplusplus
extern "C" {
#endif

void init_title_screen(void);
void update_title_screen(void);
void draw_title_screen(void);
void unload_tile_screen(void);
int finish_title_screen(void);

#ifdef __cplusplus
}
#endif

#endif // SCREENS_H
