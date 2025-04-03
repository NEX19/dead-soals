#pragma once

#include "raylib.h"

struct PlayerInput
{
    Vector2 speed_change = Vector2{0, 0};
    float angle_change = 0.0;
};
