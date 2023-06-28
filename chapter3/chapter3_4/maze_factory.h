#ifndef MAZE_FACTORY_H
#define MAZE_FACTORY_H

#include "map_site.h"

class MazeFactory {
public:
    MazeFactory();

    virtual Maze *MakeMaze() const {
        return new Maze;
    }

    virtual Wall *MakeWall() const {
        return new Wall;
    }

    virtual Room *MakeRoom(int n) const {
        Room *room = new Room;
        room->Initialize(n);
        return room;
    }

    virtual Door *MakeDoor(Room *r1, Room *r2) const {
        Door *door = new Door;
        door->Initialize(r1, r2, false);
        return door;
    }
};

// 我们将定义(MazeFactory(3.1))的子类(MazePrototypeFactory), 该子类将使用它要创建的对象的原型来初始化.
// 这样我们就不需要仅仅为了改变它所创建的墙壁或房间的类而生成子类
class MazePrototypeFactory : public MazeFactory {
public:
    MazePrototypeFactory(Maze *, Wall *, Room *, Door *);

    virtual Wall *MakeWall() const;
    virtual Door *MakeDoor(Room *r1, Room *r2) const;

private:
    Maze *_prototypeMaze;
    Room *_prototypeRoom;
    Wall *_prototypeWall;
    Door *_prototypeDoor;
};

#endif