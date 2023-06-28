#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "maze_builder.h"

// 创建迷宫类
class MazeGame {
public:
    Maze *CreateMaze(MazeBuilder &builder);
    Maze *CreateComplexMaze(MazeBuilder &builder);
};

#endif