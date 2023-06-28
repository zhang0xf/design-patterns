#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "maze_factory.h"

// 创建迷宫类
class MazeGame {
public:
    Maze *CreateMaze(MazeFactory &factory);
};

#endif