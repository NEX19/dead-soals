#include "Game.h"
#include "constants.h"

int main()
{
    SetTraceLogLevel(LOG_ERROR); 
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Make haste");
    Game g = Game();
    g.main_loop(); 
    return 0;
}
