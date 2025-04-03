#pragma once

#include "raylib.h"

class Player;

class Renderer {    
    public:
        Texture2D player_texture;

        Renderer();
        void render_player(Player&);
};
