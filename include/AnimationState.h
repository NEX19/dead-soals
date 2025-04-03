#pragma once

#include "PlayerAnimations.h"

struct AnimationState {
    PlayerAnimations current;
    int frame;
    double frame_timer;
};
