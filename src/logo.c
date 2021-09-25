/*******************************************************************************************
*
*   raylib [shapes] example - raylib logo animation
*
*   This example has been created using raylib 2.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

/* Draw the animated Raylib logo
 *
 * This gives credit the raylib and 
 * adds that professional polish.
 */ 
void draw_raylib_logo() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Runner");

    int logoPositionX = screenWidth/2 - 128;
    int logoPositionY = screenHeight/2 - 128;

    int framesCounter = 0;
    int lettersCount = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;

    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;

    int state = 0;                  // Tracking animation states (State Machine)
    float alpha = 1.0f;             // Useful for fading

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	/*TODO(Todd): remove this while loop.
	 *
	 * It should be possible to use a for loop until the animation
	 * has ended. Then, we can move to the launch screen of the game.
	 */
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // State 0: Small box blinking
        if (state == 0)                 
        {
            framesCounter++;

            if (framesCounter == 120)
            {
                state = 1;
                // Reset counter... will be used later...
                framesCounter = 0;      
            }
        }
        // State 1: Top and left bars growing
        else if (state == 1)            
        {
            topSideRecWidth += 4;
            leftSideRecHeight += 4;

            if (topSideRecWidth == 256) state = 2;
        }
        // State 2: Bottom and right bars growing
        else if (state == 2)            
        {
            bottomSideRecWidth += 4;
            rightSideRecHeight += 4;

            if (bottomSideRecWidth == 256) state = 3;
        }
        // State 3: Letters appearing (one by one)
        else if (state == 3)            
        {
            framesCounter++;
            // Every 12 frames, one more letter!
            if (framesCounter/12)       
            {
                lettersCount++;
                framesCounter = 0;
            }
            // When all letters have appeared, just fade out everything
            if (lettersCount >= 10)     
            {
                alpha -= 0.02f;

                if (alpha <= 0.0f)
                {
                    alpha = 0.0f;
                    state = 4;
                }
            }
        }
        // State 4: Reset and Replay
        else if (state == 4)            
        {
			break;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (state == 0)
            {
                if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
            }
            else if (state == 1)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
            }
            else if (state == 2)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

                DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
                DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
            }
            else if (state == 3)
            {
                DrawRectangle(
                    logoPositionX, 
                    logoPositionY, 
                    topSideRecWidth, 
                    16, 
                    Fade(BLACK, alpha)
                );

                DrawRectangle(
                    logoPositionX, 
                    logoPositionY + 16, 
                    16, 
                    leftSideRecHeight - 32, 
                    Fade(BLACK, alpha)
                );

                DrawRectangle(
                    logoPositionX + 240, 
                    logoPositionY + 16, 
                    16, 
                    rightSideRecHeight - 32, 
                    Fade(BLACK, alpha)
                );

                DrawRectangle(
                    logoPositionX, 
                    logoPositionY + 240, 
                    bottomSideRecWidth,
                    16, 
                    Fade(BLACK, alpha)
                );

                DrawRectangle(
                    GetScreenWidth()/2 - 112, 
                    GetScreenHeight()/2 - 112, 
                    224, 
                    224, 
                    Fade(RAYWHITE, alpha)
                );

                DrawText(
                    TextSubtext("raylib", 0, lettersCount), 
                    GetScreenWidth()/2 - 44, 
                    GetScreenHeight()/2 + 48, 
                    50, 
                    Fade(BLACK, alpha)
                );
            }
            else if (state == 4)
            {
				break;
            }

        EndDrawing();
    }
}
