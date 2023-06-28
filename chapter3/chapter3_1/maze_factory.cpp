#include "maze_factory.h"

MazeFactory::MazeFactory() {
}

// EnchantedMazeFactory ==========================

EnchantedMazeFactory::EnchantedMazeFactory() {
}

Spell *EnchantedMazeFactory::CastSpell() const {
    Spell *spl = new Spell("some fucking spell");
    return spl;
}

// BombedMazeFactory =============================

BombedMazeFactory::BombedMazeFactory() {
}

Wall *BombedMazeFactory::MakeWall() const {
    return new BombedWall;
}

Room *BombedMazeFactory::MakeRoom(int n) const {
    return new RoomWithABomb(n);
}