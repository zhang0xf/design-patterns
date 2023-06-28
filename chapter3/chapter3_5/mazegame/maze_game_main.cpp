#include "maze_game.h"

int main() {
    MazeGame game;
    MazeFactory *factory = MazeFactory::Instance();
    game.CreateMaze(*factory);

    return 0;
}