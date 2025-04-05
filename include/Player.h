#pragma once

#include "PlayerInput.h"
#include "AnimationState.h"

class Renderer;

class Player {
    private:
        Vector2 speed;
        float scalar_speed;     // used for no-target mode
        float rotation_angle;
        Color color;
        Rectangle rect;
        AnimationState anim;
        bool is_targeting;
        PlayerInput last_input;


        void recalculate_speed();
        void reset_animations();

    public:

        Player();
        void update();

        Rectangle get_rectangle() const;
        
        void update_animation_state(int);
        AnimationState get_animation_state() const;
        float get_rotation_angle() const;
        Color get_color() const;

        void set_last_input(const PlayerInput&);
        void accept_renderer(Renderer&);
};
