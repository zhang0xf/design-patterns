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
    _isOpen = true;
}

void Door::Enter() {
    std::cout << "Door Enter" << std::endl;
}

// EnchantedRoom ===================================

EnchantedRoom::EnchantedRoom(int n, Spell *spl) :
    Room(n) {
    _spell = spl;
}

void EnchantedRoom::Enter() {
    std::cout << "EnchantedRoom Enter" << std::endl;
}

// DoorNeedingSpell ================================

DoorNeedingSpell::DoorNeedingSpell(Room *r1, Room *r2) :
    Door(r1, r2) {
}

void DoorNeedingSpell::Enter() {
    std::cout << "DoorNeedingSpell Enter" << std::endl;
}

// RoomWithABomb ===================================

RoomWithABomb::RoomWithABomb(int n) :
    Room(n) {
    _bomb = new Item(1000);                   // 编号为1000的炸弹
    std::cout << _bomb->GetId() << std::endl; // error : '_itemID' is not used
}

void RoomWithABomb::Enter() {
    std::cout << "RoomWithABomb Enter" << std::endl;
}

// BombedWall ======================================

BombedWall::BombedWall() {
}

void BombedWall::Enter() {
    std::cout << "BombedWall Enter" << std::endl;
}

// Maze ============================================

Maze::Maze() {
}

void Maze::AddRoom(Room *r) {
    // rooms.insert(std::make_pair(r->GetRoomNo(), r));
    rooms.insert(std::pair<int, Room *>(r->GetRoomNo(), r));
}

Room *Maze::RoomNo(int n) const {
    if (rooms.find(n) == rooms.end()) {
        return nullptr;
    }
    return rooms.at(n);
}