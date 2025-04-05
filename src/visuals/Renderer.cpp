#include "Player.h"
#include "Renderer.h"
#include "constants.h"

#include "raylib.h"


Renderer::Renderer()
{
    player_texture = LoadTexture("./resources/cropped_monster.png");

    if (!player_texture.id) {
        TraceLog(LOG_ERROR, "Failed to load textures!");
    }
}

void Renderer::render_player(Player& player)
{
    AnimationState anim = player.get_animation_state();
    Rectangle rect = player.get_rectangle();
    float rotation_angle = player.get_rotation_angle();
    Color color = player.get_color();

    if(anim.current == PlayerAnimations::Idle) {
        Rectangle source = Rectangle{
            PLAYER_SPRITE_WIDTH * IDLE_ANIMATION_COLUMN,
            PLAYER_SPRITE_HEIGHT * anim.frame,
            PLAYER_SPRITE_WIDTH, 
            PLAYER_SPRITE_HEIGHT
        };

        if(GetTime() - anim.frame_timer > ANIMATION_UPDATE_RATE) { 
            int new_frame = (anim.frame + 1) % PLAYER_ANIMATIONS_FRAMES_COUNT;
            player.update_animation_state(new_frame);
        }

        DrawTexturePro(player_texture, source, rect, Vector2{PLAYER_WIDTH/2, PLAYER_HEIGHT/2},
            -rotation_angle, color);
    }
    else if(anim.current == PlayerAnimations::Walking) {
        Rectangle source = Rectangle{
            PLAYER_SPRITE_WIDTH * WALKING_ANIMATION_COLUMN,
            PLAYER_SPRITE_HEIGHT * anim.frame,
            PLAYER_SPRITE_WIDTH, 
            PLAYER_SPRITE_HEIGHT
        };

        if(GetTime() - anim.frame_timer > ANIMATION_UPDATE_RATE) { 
            int new_frame = (anim.frame + 1) % PLAYER_ANIMATIONS_FRAMES_COUNT;
            player.update_animation_state(new_frame);
        }

        DrawTexturePro(player_texture, source, rect, Vector2{PLAYER_WIDTH/2, PLAYER_HEIGHT/2},
            -rotation_angle, color);
    }
}

Renderer::~Renderer() {
    UnloadTexture(player_texture); 
}
