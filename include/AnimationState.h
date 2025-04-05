#pragma once

#include "PlayerAnimations.h"

struct AnimationState {
    PlayerAnimations current;
    int frame = 0;
    double frame_timer;
};
