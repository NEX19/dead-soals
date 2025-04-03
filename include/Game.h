#pragma once

#include <vector>
#include <memory>

#include "Player.h"
#include "PlayerInput.h"
#include "Renderer.h"

class Game {
    private:
        Player player;
        Camera2D camera;
        std::unique_ptr<Renderer> renderer;

    public:
        Game();
        void main_loop();
        PlayerInput get_input();
        void draw();
        void update();
};
