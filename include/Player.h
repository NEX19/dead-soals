#pragma once

#include "PlayerInput.h"
#include "PlayerAnimations.h"

class Renderer;

class Player {
    private:
        ;

    public:
        Vector2 speed;
        Rectangle rect;
        float rotation_angle;
        Color color;
        int frame;
        double time_since_frame_change;
        PlayerAnimations animation;

        Player();
        void update();

        void apply_input(PlayerInput);

        void accept_renderer(Renderer);
};
