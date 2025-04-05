#include "Game.h"
#include "constants.h"

#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

Game::Game()
{    
    renderer = std::make_unique<Renderer>();
    camera_controller = make_unique<CameraController>(player);
}

void Game::main_loop()
{
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();  
}

void Game::update() {
    
    // update player
    PlayerInput input = get_input();  
    player.set_last_input(input); 
    player.update();          

    // update camera
    camera_controller->update(player);
}

PlayerInput Game::get_input()
{
    PlayerInput input;

    if(IsKeyDown(KEY_W)) input.direction.y -= 1;
    if(IsKeyDown(KEY_S)) input.direction.y += 1;
    if(IsKeyDown(KEY_A)) input.direction.x -= 1;
    if(IsKeyDown(KEY_D)) input.direction.x += 1;

    return input;
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    camera_controller->start_camera_mode();
    
    // printing the grid
    for(int i = -50;i < 50;i++) {
        for(int j = -50;j < 50;j++) {
            Rectangle rec = Rectangle{float(i * 50), float(j * 50), 50, 50};
            Color color = (i + j) % 2 ? GRAY : PURPLE;
            DrawRectangleRec(rec, color);
        }
    }
    
    player.accept_renderer(*renderer);

    camera_controller->end_camera_mode();

    EndDrawing();
}
