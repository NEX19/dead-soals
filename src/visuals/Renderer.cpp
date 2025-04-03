#include "Player.h"
#include "Renderer.h"

#include "raylib.h"

// #include <iostream>
// using namespace std;

Renderer::Renderer()
{
    player_texture = LoadTexture("./resources/cropped_monster.png");

    if (!player_texture.id) {
        TraceLog(LOG_ERROR, "Failed to load textures!");
    }
}

void Renderer::render_player(Player& player)
{
    if(player.animation == PlayerAnimations::Idle) {
        Rectangle source = Rectangle{float(176 * 4), float(161 * player.frame), 176, 161};
        if(GetTime() - player.time_since_frame_change > 0.125) {
            player.frame = (player.frame + 1) % 4;
            player.time_since_frame_change = GetTime();
        }

        DrawTexturePro(player_texture, source, player.rect, Vector2{50, 50},
        -player.rotation_angle, player.color);
    }
    else if(player.animation == PlayerAnimations::Walking) {
        Rectangle source = Rectangle{float(176 * 3), float(161 * player.frame), 176, 161};
        if(GetTime() - player.time_since_frame_change > 0.125) {
            player.frame = (player.frame + 1) % 4;
            player.time_since_frame_change = GetTime();
        }

        DrawTexturePro(player_texture, source, player.rect, Vector2{50, 50},
        -player.rotation_angle, player.color);
    }
}
