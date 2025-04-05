#pragma once

#include <vector>
#include <memory>

#include "Player.h"
#include "PlayerInput.h"
#include "Renderer.h"
#include "CameraController.h"

class Game {
    private:
        Player player;
        std::unique_ptr<CameraController> camera_controller;
        std::unique_ptr<Renderer> renderer;

    public:
        Game();
        void main_loop();
        PlayerInput get_input();
        void draw();
        void update();
};
