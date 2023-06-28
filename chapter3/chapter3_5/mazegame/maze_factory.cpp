#include "maze_factory.h"

MazeFactory *MazeFactory::_instance = 0;

MazeFactory::MazeFactory() {
}

// MazeFactory *MazeFactory::Instance() {
//     if (_instance == 0) {
//         _instance = new MazeFactory();
//     }
//     return _instance;
// }

// 当存在多个(MazeFactory)子类时, 我们将通过环境变量选择迷宫的种类并根据环境变量的值增加代码用于实例化适当的(MazeFactory)子类
// 注意:无论何时定义一个新的(MazeFactory)子类, Instance都必须被修改.(可以使用(Singleton)中描述的注册表方法)
MazeFactory *MazeFactory::Instance() {
    if (_instance == 0) {
        const char *mazeStyle = getenv("MAZESTYLE"); // 获取环境变量的值

        mazeStyle = "bombed"; // 简化测试

        if (strcmp(mazeStyle, "bombed") == 0) {
            _instance = new BombedMazeFactory;
        } else if (strcmp(mazeStyle, "enchanted") == 0) {
            _instance = new EnchantedMazeFactory;
        }

        // ... other possible subclasses

        else { // default
            _instance = new MazeFactory;
        }
    }
    return _instance;
}

EnchantedMazeFactory::EnchantedMazeFactory() {
}

Spell *EnchantedMazeFactory::CastSpell() const {
    Spell *spl = new Spell("some fucking spell");
    return spl;
}

BombedMazeFactory::BombedMazeFactory() {
}

Wall *BombedMazeFactory::MakeWall() const {
    return new BombedWall;
}

Room *BombedMazeFactory::MakeRoom(int n) const {
    return new RoomWithABomb(n);
}