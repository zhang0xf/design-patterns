#include <iostream>
#include "maze_game.h"

int main() {
    // 客户使用(CreateMaze)和(StandardMazeBuilder)来创建一个迷宫
    Maze *maze;
    MazeGame game;
    StandardMazeBuilder builder;

    game.CreateMaze(builder);

    maze = builder.GetMaze();
    UNUSED(maze);

    // 客户使用(CountingMazeBuilder)
    int rooms, doors;
    MazeGame game2;
    CountingMazeBuilder cbuilder;

    game2.CreateMaze(cbuilder);
    cbuilder.GetCounts(rooms, doors);

    std::cout << "The Maze has "
              << rooms << "rooms and "
              << doors << "doors" << std::endl;

    return 0;
}