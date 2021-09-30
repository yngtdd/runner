#include "raylib.h"
#include <extras/physac.h>

PhysicsBody create_floor(int screen_width, int screen_height)
{
    PhysicsBody floor = CreatePhysicsBodyRectangle(
        (Vector2) {screen_width/2, screen_height},
	screen_width,
	10,
	100
    );

    return floor; 
}