#include "audio.h"
#include "logo.h"
#include "physics.h"
#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#include <extras/physac.h>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)
#define VELOCITY    0.5f

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RUNNER");
    SetTargetFPS(60);

    draw_raylib_logo();

    Music music = load_music();
    PlayMusicStream(music);

    PhysicsBody floor = create_floor(SCREEN_WIDTH, SCREEN_HEIGHT);
    PhysicsBody platform_left = create_platform(SCREEN_WIDTH, SCREEN_HEIGHT, 0.25f, 0.6f);
    PhysicsBody platfrom_right = create_platform(SCREEN_WIDTH, SCREEN_HEIGHT, 0.75f, 0.6f);
    PhysicsBody wall_right = create_wall(SCREEN_WIDTH, SCREEN_HEIGHT, 5);
    PhysicsBody player = create_body(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        //UpdatePhysics();

        if (IsKeyDown(KEY_RIGHT)) player->velocity.x = VELOCITY;
        else if (IsKeyDown(KEY_LEFT)) player->velocity.x = -VELOCITY;

        if (IsKeyDown(KEY_UP) && player->isGrounded) player->velocity.y = -VELOCITY*4;

        BeginDrawing();

        ClearBackground(BLACK);
        DrawFPS(SCREEN_WIDTH - 90, SCREEN_HEIGHT - 30);

        int bodies_count = GetPhysicsBodiesCount();
        for (int i = 0; i < bodies_count; i++)
        {
            PhysicsBody body = GetPhysicsBody(i);
            int vertex_count = GetPhysicsShapeVerticesCount(i);
            for (int j = 0; j < vertex_count; j++)
            {
                Vector2 vertex_a = GetPhysicsShapeVertex(body, j);
                int jj = (((j + 1) < vertex_count) ? (j + 1) : 0);
                Vector2 vertex_b = GetPhysicsShapeVertex(body, jj);
                DrawLineV(vertex_a, vertex_b, GREEN);
            }
        }

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
		ClosePhysics();
    CloseWindow();

    return 0;
} 
