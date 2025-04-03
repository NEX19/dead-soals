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

Player::Player() 
{
    rect = Rectangle{0, 0, 100, 100};
    speed = Vector2{0, 0};
    color = WHITE;

    frame = 0;
    animation = PlayerAnimations::Idle;
    time_since_frame_change = GetTime();
}

void Player::update()
{
    rect.x += speed.y * sin(rotation_angle * M_PI / 180);
    rect.y += speed.y * cos(rotation_angle * M_PI / 180);

    if(speed.y && animation == PlayerAnimations::Idle) {
        animation = PlayerAnimations::Walking;
        frame = 0;
        time_since_frame_change = GetTime();
    }
    if(!speed.y && animation == PlayerAnimations::Walking) {
        animation = PlayerAnimations::Idle;
        frame = 0;
        time_since_frame_change = GetTime();
    }
}  

void Player::apply_input(PlayerInput input)
{
    float delta_time = GetFrameTime();

    if(speed.y)
        rotation_angle += input.angle_change;

    int x_sign = sgn(input.speed_change.x);
    int y_sign = sgn(input.speed_change.y);

    // this->speed.x = std::min(MAX_PLAYER_SPEED, (input.speed_change.x + this->speed.x) * x_sign) * x_sign;
    this->speed.y = std::min(MAX_PLAYER_SPEED, (input.speed_change.y + this->speed.y) * y_sign) * y_sign;

    // if(input.speed_change.x == 0) {
    //     if(abs(this->speed.x) <= BREAK_INCREASE * delta_time) 
    //         this->speed.x = 0;
    //     if(this->speed.x < 0) this->speed.x += BREAK_INCREASE * delta_time;
    //     if(this->speed.x > 0) this->speed.x -= BREAK_INCREASE * delta_time;
    // }
    if(input.speed_change.y == 0) {
        if(abs(this->speed.y) <= BREAK_INCREASE * delta_time)
            this->speed.y = 0;
        if(this->speed.y < 0) this->speed.y += BREAK_INCREASE * delta_time;
        if(this->speed.y > 0) this->speed.y -= BREAK_INCREASE * delta_time;
    }
}

void Player::accept_renderer(Renderer renderer)
{
    renderer.render_player(*this);
}
