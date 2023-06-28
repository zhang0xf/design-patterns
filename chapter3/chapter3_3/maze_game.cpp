#include "maze_game.h"

// 使用工厂方法重写(CreateMaze)
Maze *MazeGame::CreateMaze() {
    Maze *aMaze = MakeMaze();

    Room *r1 = MakeRoom(1);
    Room *r2 = MakeRoom(2);
    Door *theDoor = MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(MAP::North, MakeWall());
    r1->SetSide(MAP::East, theDoor);
    r1->SetSide(MAP::South, MakeWall());
    r1->SetSide(MAP::West, MakeWall());

    r1->SetSide(MAP::North, MakeWall());
    r1->SetSide(MAP::East, MakeWall());
    r1->SetSide(MAP::South, MakeWall());
    r1->SetSide(MAP::West, theDoor);

    return aMaze;
}

BombedMazeGame::BombedMazeGame() {
}

EnchantedMazeGame::EnchantedMazeGame() {
}

Spell *EnchantedMazeGame::CastSpell() const {
    Spell *spl = new Spell("some fucking spell");
    return spl;
}