#include "maze_game.h"

// 注意生成器是如何隐藏迷宫内部表示的(定义房间、门、墙壁的那些类), 以及这些部件是如何组装成最终的迷宫的
Maze *MazeGame::CreateMaze(MazeBuilder &builder) {
    builder.BuildMaze();

    builder.BuildRoom(1);
    builder.BuildRoom(2);
    builder.BuildDoor(1, 2);

    return builder.GetMaze();
}

// 像其他创建型模式一样, Builder模式封装了对象是如何被创建的, 我们可以复用(MazeBuilder)来创建不同种类的迷宫
Maze *MazeGame::CreateComplexMaze(MazeBuilder &builder) {
    builder.BuildRoom(1);
    // ...
    builder.BuildRoom(1001);

    return builder.GetMaze();
}