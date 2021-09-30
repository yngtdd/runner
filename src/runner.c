#include "audio.h"
#include "logo.h"
#include "physics.h"
#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#include <extras/physac.h>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RUNNER");
    SetTargetFPS(60);

		draw_raylib_logo();

    Music music = load_music();
    PlayMusicStream(music);

    Texture2D texture = LoadTexture(ASSETS_PATH "dino.png");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
} 
