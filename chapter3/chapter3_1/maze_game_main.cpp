#include "maze_game.h"

int main() {
    MazeGame game;

    BombedMazeFactory factory1;
    // 建造一个包含炸弹的简单迷宫
    game.CreateMaze(factory1);

    // 建造一个施了魔法的房间
    EnchantedMazeFactory factory2;
    game.CreateMaze(factory2);

    return 0;
}