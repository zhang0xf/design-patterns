#include "maze_game.h"

Maze *MazeGame::CreateMaze(MazeFactory &factory) {
    Maze *aMaze = factory.MakeMaze();
    Room *r1 = factory.MakeRoom(1);
    Room *r2 = factory.MakeRoom(2);
    Door *aDoor = factory.MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(MAP::North, factory.MakeWall());
    r1->SetSide(MAP::East, aDoor);
    r1->SetSide(MAP::South, factory.MakeWall());
    r1->SetSide(MAP::West, factory.MakeWall());

    r2->SetSide(MAP::North, factory.MakeWall());
    r2->SetSide(MAP::East, factory.MakeWall());
    r2->SetSide(MAP::South, factory.MakeWall());
    r2->SetSide(MAP::West, aDoor);

    return aMaze;
}