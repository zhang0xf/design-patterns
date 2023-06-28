#include <iostream>
#include "map_site.h"

// Room ============================================

Room::Room(int roomNo) {
    _roomNumber = roomNo;
    // nothing to do with _side.
}

MapSite *Room::GetSide(MAP::Direction dir) const {
    return _side[dir];
}

void Room::SetSide(MAP::Direction dir, MapSite *m) {
    _side[dir] = m;
}

int Room::GetRoomNo() const {
    return _roomNumber;
}

void Room::Enter() {
    std::cout << "Room Enter" << std::endl;
}

// Wall ============================================

Wall::Wall() {
}

void Wall::Enter() {
    std::cout << "Wall Enter" << std::endl;
}

// Door ============================================

Door::Door(Room *r1, Room *r2) {
    _room1 = r1;
    _room2 = r2;
    _isOpen = false;
}

void Door::Enter() {
    std::cout << "Door Enter" << std::endl;
}

// Maze ============================================

Maze::Maze() {
}

void Maze::AddRoom(Room *r) {
    // rooms.insert(std::make_pair(r->GetRoomNo(), r));
    rooms.insert(std::pair<int, Room *>(r->GetRoomNo(), r));
}

// 此函数的问题在于它不灵活!
// 它对迷宫进行硬编码, 改变布局意味着需要改变这个函数
// 1. 通过(override)重定义它: 意味着重新实现整个过程
// 2. 部分修改它: 容易产生错误且不利于复用
// 创建型模式表明如何使得这个设计更灵活,但未必更小。
// 假设你想在一个包含(所有的东西)施了魔法的迷宫的新游戏中复用一个已有的迷宫布局.
// 施了魔法的迷宫有新的构件, 如: DoorNeedingSpell(需要咒语才能锁上和打开的门)、EnchantedRoom(一个可以有不寻常东西的房间, 如: 魔法钥匙)
// 如何才能较容易地改变CreateMaze()以让它用这些新类型的对象创建迷宫呢???
Maze *MazeGame::CreateMaze() {
    Maze *aMaze = new Maze();
    Room *r1 = new Room(1);
    Room *r2 = new Room(2);
    Door *theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(MAP::North, new Wall);
    r1->SetSide(MAP::East, theDoor);
    r1->SetSide(MAP::South, new Wall);
    r1->SetSide(MAP::West, new Wall);

    r2->SetSide(MAP::North, new Wall);
    r2->SetSide(MAP::East, new Wall);
    r2->SetSide(MAP::South, new Wall);
    r2->SetSide(MAP::West, theDoor);

    return aMaze;
}