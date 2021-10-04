#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H 

#include "raylib.h"
#include <extras/physac.h>

PhysicsBody create_floor(int screen_width, int screen_height);

PhysicsBody create_platform(int screen_width, int screen_height, float x_offset, float y_offset);

PhysicsBody create_wall(int screen_width, int screen_height, int offset);

PhysicsBody create_body(int screen_width, int screen_height);

#endif // Physics implementation
