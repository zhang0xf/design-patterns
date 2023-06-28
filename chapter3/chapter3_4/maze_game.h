#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "maze_factory.h"

class MazeGame {
public:
    Maze *CreateMaze(MazeFactory &factory);
};

#endif