#include "maze_game.h"

int main() {
    // 我们只需要使用基本迷宫构件的原型进行初始化, 就可以由(MazePrototypeFactory)来创建一个原型的或缺省的迷宫.
    MazeGame game;
    MazePrototypeFactory simpleMazeFactory(
        new Maze, new Wall, new Room, new Door); // 可能需要一个原型管理器(维护一个可用的原型注册表)
    Maze *aMaze = game.CreateMaze(simpleMazeFactory);
    UNUSED(aMaze);

    // 为了改变迷宫的类型,我们用一个不同的原型集合来初始化(MazePrototypeFactory)
    MazePrototypeFactory bombedMazeFactory(
        new Maze, new BombedWall, new RoomWithABomb, new Door);
    Maze *aMaze2 = game.CreateMaze(bombedMazeFactory);
    UNUSED(aMaze2);

    return 0;
}