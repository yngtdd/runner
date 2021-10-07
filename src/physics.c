#include "raylib.h"
#include <extras/physac.h>

PhysicsBody create_floor(int screen_width, int screen_height)
{
    PhysicsBody floor = CreatePhysicsBodyRectangle(
        (Vector2) {screen_width/2, screen_height},
        screen_width,
        100,
        10
    );

    floor->enabled = false;

    return floor; 
}

/* Create a platform for bodies
 */
PhysicsBody create_platform(int screen_width, int screen_height, float x_offset, float y_offset)
{
    PhysicsBody platform = CreatePhysicsBodyRectangle(
        (Vector2) {screen_width * x_offset, screen_height * y_offset},
	    screen_width*0.25f,
	    10,
	    10
    );

    platform->enabled = false;

    return platform;
}

/* Create a wall for bodies
 */
PhysicsBody create_wall(int screen_width, int screen_height, int offset)
{
    PhysicsBody wall = CreatePhysicsBodyRectangle(
        (Vector2) {screen_width + offset, screen_height / 2},
	    10,
	    screen_height,
	    10
    );

    wall->enabled = false;

    return wall;
}

/* Create a body
 */
PhysicsBody create_body(int screen_width, int screen_height)
{
    PhysicsBody body = CreatePhysicsBodyRectangle(
        (Vector2) {screen_width / 2, screen_height / 2},
	      20,
	      20,
        1
    );

    // constrain body rotation
    body->freezeOrient = true;
    body->staticFriction = 0.5f;
    body->dynamicFriction = 0.6f;
    body->restitution = 0.5f;

    return body;
}
