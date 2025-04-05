#pragma once

#include "raylib.h"

class Player;

class Renderer {    
    private:
        Texture2D player_texture;
    
    public:
        Renderer();
        ~Renderer();
        void render_player(Player&);
};
