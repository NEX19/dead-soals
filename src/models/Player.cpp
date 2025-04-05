#include "raylib.h"
#include "Player.h"
#include "Renderer.h"
#include "constants.h"
#include "utils.h"
#include "PlayerAnimations.h"

#include <algorithm>
#include <cmath>

#include <iostream>

using namespace std;

// PUBLIC METHODS

Player::Player() 
{
    rect = Rectangle{0, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    speed = Vector2{0, 0};
    scalar_speed = 0;
    color = WHITE;
    
    is_targeting = false;

    anim.frame = 0;
    anim.current = PlayerAnimations::Idle;
    anim.frame_timer = GetTime();
}

void Player::update()
{
    recalculate_speed();
    reset_animations();

    rect.x += speed.x;
    rect.y += speed.y;
}  

void Player::set_last_input(const PlayerInput& input)
{
    last_input = input;
}

void Player::accept_renderer(Renderer& renderer)
{
    renderer.render_player(*this);
}

Rectangle Player::get_rectangle() const
{
    return rect;
}

AnimationState Player::get_animation_state() const
{
    return anim;
}

float Player::get_rotation_angle() const
{
    return rotation_angle;
}

Color Player::get_color() const
{
    return color;
}

void Player::update_animation_state(int new_frame)
{
    anim.frame = new_frame;
    anim.frame_timer = GetTime();
}

// PRIVATE METHODS

void Player::recalculate_speed()
{
    float delta_time = GetFrameTime();

    if(!is_targeting) {
        float speed_change = PLAYER_SPEED_INCREASE * delta_time * last_input.direction.y;
        float angle_change = -1 * PLAYER_ANGLE_CHANGE * delta_time * last_input.direction.x;

        bool is_moving = speed.x || speed.y || last_input.direction.y;

        if(is_moving)
            rotation_angle += angle_change;     
        
        scalar_speed += speed_change;
        scalar_speed = clamp(scalar_speed, -MAX_PLAYER_SPEED, MAX_PLAYER_SPEED);

        speed.x = scalar_speed * sin(deg_to_rad(rotation_angle));
        speed.y = scalar_speed * cos(deg_to_rad(rotation_angle));

        // stopping the player if no input
        if(last_input.direction.y == 0) {
            int speed_direction = sgn(scalar_speed); 
            float friction_change = PLAYER_FRICTION_INCREASE * delta_time * speed_direction; 
            if(abs(scalar_speed) < abs(friction_change))
                scalar_speed = 0;
            else
                scalar_speed -= friction_change;
        }
    }
}

void Player::reset_animations()
{
    if(speed.y && anim.current == PlayerAnimations::Idle) {
        anim.current = PlayerAnimations::Walking;
        anim.frame = 0;
        anim.frame_timer = GetTime();
    }
    if(!speed.y && anim.current == PlayerAnimations::Walking) {
        anim.current = PlayerAnimations::Idle;
        anim.frame = 0;
        anim.frame_timer = GetTime();
    }
}
