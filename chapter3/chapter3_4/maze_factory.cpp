#include "maze_factory.h"

MazeFactory::MazeFactory() {
}

// 新的构造器只初始化它的原型
MazePrototypeFactory::MazePrototypeFactory(Maze *m, Wall *w, Room *r, Door *d) {
    _prototypeMaze = m;
    _prototypeWall = w;
    _prototypeRoom = r;
    _prototypeDoor = d;
}

// 用于创建墙壁、房间和门的成员函数是相似的: 每个都要克隆一个原型, 然后初始化.
// 重定义(MakeWall)和(MakeDoor)
Wall *MazePrototypeFactory::MakeWall() const {
    return _prototypeWall->Clone();
}

Door *MazePrototypeFactory::MakeDoor(Room *r1, Room *r2) const {
    Door *door = _prototypeDoor->Clone();
    door->Initialize(r1, r2, false);
    return door;
}