#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "map_site.h"

// 我们将引入工厂方法以使子类可以选择这些构件(迷宫、房间、墙壁和门对象)
// 每一个工厂方法返回一个给定类型的迷宫构件, (MazeGame)提供一些缺省的实现, 它们返回最简单的迷宫、房间、墙壁和门
class MazeGame {
public:
    Maze *CreateMaze();

    // Factory Methods

    virtual Maze *MakeMaze() const {
        return new Maze;
    }

    virtual Room *MakeRoom(int n) const {
        return new Room(n);
    }

    virtual Wall *MakeWall() const {
        return new Wall;
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const {
        return new Door(r1, r2);
    }
};

// 不同游戏可以创建(MazeGame)的子类以特别指明一些迷宫构件.
// (MazeGame)子类可以重定义一些或所有的工厂方法以指定产品中的变化, 如: (BombedMazeGame)可以重定义产品Room和Wall以返回爆炸后的变体.
class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame();

    virtual Wall *MakeWall() const {
        return new BombedWall;
    }

    virtual Room *MakeRoom(int n) const {
        return new RoomWithABomb(n);
    }
};

// (EnchantedMazeGame)变体
class EnchantedMazeGame : public MazeGame {
public:
    EnchantedMazeGame();

    virtual Room *MakeRoom(int n) const {
        return new EnchantedRoom(n, CastSpell());
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const {
        return new DoorNeedingSpell(r1, r2);
    }

protected:
    Spell *CastSpell() const;
};

#endif