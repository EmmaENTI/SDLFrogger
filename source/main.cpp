//#include <SDL.h>
//#include <stdio.h>
#include "GameEngine.h"

int main(int argc, char *args[]) //Argument count, arguments, cada argumento esta separado por un espacio.
{
    GameEngine game(500, 500);
    game.Init();
    game.Run();
    game.Quit();
    return 0;
}