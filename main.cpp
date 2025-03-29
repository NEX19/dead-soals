#include "raylib.h"

int main()
{
    const int screen_width = 1500;
    const int screen_height = 1500;
    InitWindow(screen_width, screen_height, "Dead Soals");

    SetTargetFPS(0);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();   
    return 0;
}