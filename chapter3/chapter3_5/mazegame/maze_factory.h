#ifndef MAZE_FACTORY_H
#define MAZE_FACTORY_H

#include "map_site.h"

class MazeFactory {
public:
    static MazeFactory *Instance();

    // exiting interface goes here
    virtual Maze *MakeMaze() const {
        return new Maze;
    }

    virtual Wall *MakeWall() const {
        return new Wall;
    }

    virtual Room *MakeRoom(int n) const {
        return new Room(n);
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const {
        return new Door(r1, r2);
    }

protected:
    MazeFactory();

private:
    static MazeFactory *_instance;
};

// 创建(MazeFactory)的子类(EnchantedMazeFactory), 这是一个创建施了魔法的迷宫的工厂
// (EnchantedMazeFactory)将重新定义不同的成员函数并返回Room、Wall等不同的子类
class EnchantedMazeFactory : public MazeFactory {
public:
    EnchantedMazeFactory();

    virtual Room *MakeRoom(int n) const {
        return new EnchantedRoom(n, CastSpell());
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const {
        return new DoorNeedingSpell(r1, r2);
    }

protected:
    Spell *CastSpell() const;
};

// (BombedMazeFactory)保证了墙壁是(BombedWall)类而房间是(RoomWithABomb)类
class BombedMazeFactory : public MazeFactory {
public:
    BombedMazeFactory();

    virtual Wall *MakeWall() const;

    virtual Room *MakeRoom(int n) const;
};

#endif