#include <iostream>
#include "map_site.h"

// Room ============================================

Room::Room() {
}

Room::Room(const Room &other) {
    _roomNumber = other._roomNumber;
    int length = sizeof(other._side) / sizeof(other._side[0]);
    for (int i = 0; i < length; i++) {
        _side[i] = other._side[i];
    }
}

void Room::Initialize(int n) {
    _roomNumber = n;
}

Room *Room::Clone() const {
    return new Room(*this);
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

Wall::Wall(const Wall &other) {
    UNUSED(other);
}

Wall *Wall::Clone() const {
    return new Wall(*this);
}

void Wall::Enter() {
    std::cout << "Wall Enter" << std::endl;
}

// Door ============================================

Door::Door() {
}

Door::Door(const Door &other) {
    _room1 = other._room1;
    _room2 = other._room2;
    _isOpen = other._isOpen;
}

void Door::Initialize(Room *r1, Room *r2, bool isOpen) {
    _room1 = r1;
    _room2 = r2;
    _isOpen = isOpen;
}

Door *Door::Clone() const {
    return new Door(*this);
}

void Door::Enter() {
    std::cout << "Door Enter" << std::endl;
}

// EnchantedRoom ===================================

EnchantedRoom::EnchantedRoom() {
    _spell = new Spell("some fucking sepll");
}

EnchantedRoom::EnchantedRoom(const EnchantedRoom &other) :
    Room(other) { // 调用基类的拷贝构造函数处理基类部分
    if (_spell != nullptr) {
        delete _spell;
        _spell = nullptr;
    }
    _spell = other._spell;
}

void EnchantedRoom::Initialize(int n) {
    Room::Initialize(n);     // 调用基类
    if (_spell != nullptr) { // 子类自身
        delete _spell;
        _spell = new Spell("some fucking sepll");
    }
}

EnchantedRoom *EnchantedRoom::Clone() const {
    return new EnchantedRoom(*this);
}

void EnchantedRoom::Enter() {
    std::cout << "EnchantedRoom Enter" << std::endl;
}

// DoorNeedingSpell ================================

DoorNeedingSpell::DoorNeedingSpell(Room *r1, Room *r2) {
    Initialize(r1, r2, false);
}

void DoorNeedingSpell::Enter() {
    std::cout << "DoorNeedingSpell Enter" << std::endl;
}

// RoomWithABomb ===================================

RoomWithABomb::RoomWithABomb() {
}

RoomWithABomb::RoomWithABomb(const RoomWithABomb &other) :
    Room(other) { // 调用基类拷贝构造函数
    if (_bomb != nullptr) {
        delete _bomb;
        _bomb = nullptr;
    }
    _bomb = other._bomb;
}

void RoomWithABomb::Initialize(int n) {
    Room::Initialize(n);
    if (_bomb != nullptr) {
        delete _bomb;
        _bomb = nullptr;
    }
    _bomb = new Item(10001); // 编号为10001的炸弹
}

RoomWithABomb *RoomWithABomb::Clone() const {
    return new RoomWithABomb(*this);
}

void RoomWithABomb::Enter() {
    std::cout << "RoomWithABomb Enter" << std::endl;
}

// BombedWall ======================================

BombedWall::BombedWall() {
}

BombedWall::BombedWall(const BombedWall &other) :
    Wall(other) { // 调用基类拷贝构造
    _bomb = other._bomb;
}

Wall *BombedWall::Clone() const {
    return new BombedWall(*this);
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