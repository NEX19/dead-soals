#include "Game.h"
#include "constants.h"

#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

Game::Game()
{
    player = Player();

    camera = Camera2D{0};
    camera.offset = Vector2{500, 500};
    camera.target = Vector2{0, 0};
    camera.zoom = 1.0;
    camera.rotation = 0;
 
    renderer = std::make_unique<Renderer>();;
}

void Game::main_loop()
{
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        this->update();
        this->draw();
    }

    CloseWindow();  
}

void Game::update() {
    PlayerInput input = get_input();  

    player.apply_input(input); 
    player.update();          

    cout << player.rect.x << " " << player.rect.y << endl;

    camera.target = {player.rect.x, player.rect.y};
}

PlayerInput Game::get_input()
{
    PlayerInput input;
    float delta_time = GetFrameTime();
    bool is_button_pressed = false;

    if(IsKeyDown(KEY_A)) input.angle_change += 90.0 * delta_time;
    if(IsKeyDown(KEY_D)) input.angle_change -= 90.0 * delta_time;

    if(player.speed.y)
        camera.rotation += input.angle_change;

    if(IsKeyDown(KEY_W)) input.speed_change.y -= SPEED_INCREASE * delta_time;
    if(IsKeyDown(KEY_S)) input.speed_change.y += SPEED_INCREASE * delta_time;
    if(IsKeyDown(KEY_A)) input.speed_change.x -= SPEED_INCREASE * delta_time;
    if(IsKeyDown(KEY_D)) input.speed_change.x += SPEED_INCREASE * delta_time;

    return input;
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(this->camera);
    
    for(int i = -50;i < 50;i++) {
        for(int j = -50;j < 50;j++) {
            Rectangle rec = Rectangle{float(i * 50), float(j * 50), 50, 50};
            Color color = (i + j) % 2 ? GRAY : PURPLE;
            DrawRectangleRec(rec, color);
        }
    }
    
    player.accept_renderer(*renderer);

    EndMode2D();

    EndDrawing();
}
