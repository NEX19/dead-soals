#pragma once

#include "raylib.h"
#include <memory>

#include "Player.h"

class CameraController {
    private:
        std::unique_ptr<Camera2D> camera;
    public:
        CameraController(const Player&); 
        void update(const Player&);
        void start_camera_mode();
        void end_camera_mode();
        Camera2D get_camera(); 

        // FUTURE PLANS
        void recoil_effect();
};
