#ifndef MAZE_BUILDER_H
#define MAZE_BUILDER_H

#include "map_site.h"

// 我们将定义一个(CreateMaze)成员函数的变体, 它以类(MazeBuilder)的一个生成器对象作为参数

// (MazeBuilder)使用下面的接口来创建迷宫
// 注意: (MazeBuilder)自己并不创建迷宫, 它的主要目的仅仅是为创建迷宫定义一个接口, (MazeBuilder)的子类做实际的工作.
class MazeBuilder {
public:
    // 故意不申明纯虚函数成员, 而是把他们定义成空方法, 这使客户只重定义他们感兴趣的操作
    virtual void BuildMaze();
    virtual void BuildRoom(int room);
    virtual void BuildDoor(int roomFrom, int roomTo);

    virtual Maze *GetMaze();

protected:
    MazeBuilder();
};

// 子类(StandardMazeBuilder)是一个创建简单迷宫的实现. 它将它正在创建的迷宫放在变量(_currentMaze)中.
class StandardMazeBuilder : public MazeBuilder {
public:
    StandardMazeBuilder();

    virtual void BuildMaze();
    virtual void BuildRoom(int);
    virtual void buildDoor(int, int);

    virtual Maze *GetMaze();

private:
    MAP::Direction CommonWall(Room *, Room *); // (CommonWall)是一个功能性操作,它决定两个房间公共墙壁的方向.
    Maze *_currentMaze;
};

// (CountingMazeBuilder)这个生成器根本不创建迷宫, 它仅仅对已被创建的不同种类的构件进行计数.
class CountingMazeBuilder : public MazeBuilder {
public:
    CountingMazeBuilder();

    virtual void BuildRoom(int);
    virtual void buildDoor(int, int);
    virtual void AddWall(int, MAP::Direction);

    void GetCounts(int &, int &) const;

private:
    int _doors;
    int _rooms;
};

#endif