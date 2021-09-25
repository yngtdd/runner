#include "raylib.h"
#include "logo.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RUNNER");
    SetTargetFPS(60);

		draw_raylib_logo();

    Texture2D texture = LoadTexture(ASSETS_PATH"dino.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y+ 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
} 
