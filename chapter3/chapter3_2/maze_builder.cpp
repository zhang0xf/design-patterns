#include "maze_builder.h"

// 大问题: 实现如果放在头文件,StandardMazeBuilder::StandardMazeBuilder()会找不到MazeBuilder::MazeBuilder()定义???
MazeBuilder::MazeBuilder() {
}

void MazeBuilder::BuildMaze() {
}

void MazeBuilder::BuildRoom(int room) {
    UNUSED(room);
}

void MazeBuilder::BuildDoor(int roomFrom, int roomTo) {
    UNUSED(roomFrom);
    UNUSED(roomTo);
}

Maze *MazeBuilder::GetMaze() {
    return 0;
}

StandardMazeBuilder::StandardMazeBuilder() {
    _currentMaze = 0; // 构造器只是初始化了(_currentMaze)
}

void StandardMazeBuilder::BuildMaze() {
    _currentMaze = new Maze;
}

Maze *StandardMazeBuilder::GetMaze() {
    return _currentMaze;
}

// BuildRoom创建一个房间并建造它周围的墙壁
void StandardMazeBuilder::BuildRoom(int n) {
    if (!_currentMaze->RoomNo(n)) {
        Room *room = new Room(n);
        _currentMaze->AddRoom(room);

        room->SetSide(MAP::North, new Wall);
        room->SetSide(MAP::South, new Wall);
        room->SetSide(MAP::East, new Wall);
        room->SetSide(MAP::West, new Wall);
    }
}

// 为建造一扇两个房间之间的门, (StandardMazeBuilder)查找迷宫中的这两个房间并找到它们相邻的墙
void StandardMazeBuilder::buildDoor(int roomFrom, int roomTo) {
    Room *r1 = _currentMaze->RoomNo(roomFrom);
    Room *r2 = _currentMaze->RoomNo(roomTo);
    Door *d = new Door(r1, r2);

    r1->SetSide(CommonWall(r1, r2), d); // Wall -> Door
    r2->SetSide(CommonWall(r2, r1), d);
}

// 指定两个房间之间公共墙壁的方向
MAP::Direction StandardMazeBuilder::CommonWall(Room *roomFrom, Room *roomTo) {
    // 简化版逻辑
    if (roomFrom->GetRoomNo() < roomTo->GetRoomNo()) {
        return MAP::East;
    } else {
        return MAP::West;
    }
}

// 构造器初始化该计数器, 而重定义了的(MazeBuilder)操作知识相应地增加计数
CountingMazeBuilder::CountingMazeBuilder() {
    _rooms = _doors = 0;
}

void CountingMazeBuilder::BuildRoom(int) {
    _rooms++;
}

void CountingMazeBuilder::buildDoor(int, int) {
    _doors++;
}

void CountingMazeBuilder::AddWall(int, MAP::Direction) {
}

void CountingMazeBuilder::GetCounts(int &rooms, int &doors) const {
    rooms = _rooms;
    doors = _doors;
}