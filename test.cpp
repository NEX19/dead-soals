#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 450;
    const int block_size = 50;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    const int rectangles_count = 200;
    Rectangle rectangles[rectangles_count];

    for(int i = 0;i < rectangles_count;i++) {
        Rectangle a = {0, 0, block_size, block_size};
        a.x = (rand() % (screenWidth / block_size)) * block_size;
        a.y = (rand() % (screenWidth / block_size)) * block_size;
        rectangles[i] = a;
    }

    // for(int i = 0;i < rectangles_count;i++) {
    //     cout << rectangles[i].x << " " << rectangles[i].y << endl;
    // }

    SetTargetFPS(0);
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        for(int i = 0; i < rectangles_count;i++){
            // Vector3 values = {0, 255, 0, 0};
            Color color = {(rand() % 2) * 125, (rand() % 2) * 125, (rand() % 2) * 125, 255};
            DrawRectangleRec(rectangles[i], color);
        }

        for(int i = 0;i < rectangles_count;i++) {
            rectangles[i].x = (rand() % (screenWidth / block_size)) * block_size;
            rectangles[i].y = (rand() % (screenWidth / block_size)) * block_size;
        }
        EndDrawing();
    }

    CloseWindow();   
    return 0;
}