#ifndef MAP_SITE_H
#define MAP_SITE_H

#include <map>
#include "def.h"
#include "effect.h"
#include "item.h"

// 所有迷宫构件的公共抽象类
// Enter的含义取决于要进入的对象 : 房间、窗户、门等等.
class MapSite {
public:
    virtual void Enter() = 0;
};

// 房间
// 一个可以被用作原型的对象，必须支持(Clone)操作.它还必须有一个拷贝构造器用于克隆.
class Room : public MapSite {
public:
    Room();
    Room(const Room &);

    virtual void Initialize(int n);
    virtual Room *Clone() const;

    MapSite *GetSide(MAP::Direction) const;
    void SetSide(MAP::Direction, MapSite *);
    int GetRoomNo() const;

    virtual void Enter();

private:
    MapSite *_side[4]; // 指向其他MapSite对象的引用(指针数组)
    int _roomNumber;
};

// 房间的每一面所出现的墙壁
class Wall : public MapSite {
public:
    Wall();
    Wall(const Wall &);

    virtual Wall *Clone() const;

    virtual void Enter();
};

// 房间的每一面所出现的门
class Door : public MapSite {
public:
    Door();
    Door(const Door &);

    virtual void Initialize(Room *, Room *, bool);
    virtual Door *Clone() const;

    virtual void Enter();

    Room *OtherSideFrom(Room *);

private:
    Room *_room1;
    Room *_room2;
    bool _isOpen;
};

// 施了魔法的房间
class EnchantedRoom : public Room {
public:
    EnchantedRoom();
    EnchantedRoom(const EnchantedRoom &);

    virtual void Initialize(int n);
    virtual EnchantedRoom *Clone() const;

    virtual void Enter();

private:
    Spell *_spell;
};

// 需要咒语的门
class DoorNeedingSpell : public Door {
public:
    // TODO
    DoorNeedingSpell(Room *r1, Room *r2);

    virtual void Enter();

private:
    // Spell *_spell;
};

// 有炸弹的房间
class RoomWithABomb : public Room {
public:
    RoomWithABomb();
    RoomWithABomb(const RoomWithABomb &);

    virtual void Initialize(int n);
    virtual RoomWithABomb *Clone() const;

    virtual void Enter();

private:
    Item *_bomb;
};

// 破坏的墙壁
class BombedWall : public Wall {
public:
    BombedWall();
    BombedWall(const BombedWall &);

    virtual Wall *Clone() const;
    bool HasBomb();

    virtual void Enter();

private:
    bool _bomb;
};

// 表示房间合集的Maze
class Maze {
public:
    Maze();

    void AddRoom(Room *);
    Room *RoomNo(int) const;

private:
    // ...
    // RoomNo可以使用线性搜索、hash表、甚至简单数组查找
    std::map<int, Room *> rooms;
};

#endif