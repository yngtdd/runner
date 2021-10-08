#include "raylib.h"
#include "screens.h"

static int frames_counter = 0;
static int finish_screen = 0;

/* Tile screen initialization
 */
void init_title_screen(void)
{
    frames_counter = 0;
    finish_screen = 0;
}

/* Update the screen
 */
void update_title_screen(void)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finish_screen = 2;
        PlaySound(fxCoin);
    }
}

/* Draw the screen
 */
void draw_title_screen(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
    DrawTextEx(font, "TITLE SCREEN", (Vector2){ 20, 10 }, font.baseSize*3, 4, DARKGREEN);
    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
}

/* Unload the title screen
 */
void unload_title_screen(void)
{
    //TODO(Todd)
}

/* Get the finish screen
 */
int finish_title_screen(void)
{
    return finish_screen;
}

