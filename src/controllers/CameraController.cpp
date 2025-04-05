#include "constants.h"
#include "CameraController.h"
#include "Player.h"

CameraController::CameraController(const Player& p)
{
    Rectangle rect = p.get_rectangle();

    camera = std::make_unique<Camera2D>();
    camera->offset = Vector2{SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    camera->target = Vector2{rect.x, rect.y};
    camera->zoom = 1.0;
    camera->rotation = 0;
}

void CameraController::update(const Player& p)
{
    Rectangle rect = p.get_rectangle();
    
    camera->target.x = rect.x;
    camera->target.y = rect.y;
}

void CameraController::start_camera_mode()
{
    BeginMode2D(*camera);
}

void CameraController::end_camera_mode()
{
    EndMode2D();
}

Camera2D CameraController::get_camera()
{
    return *camera;
}


void CameraController::recoil_effect() {}