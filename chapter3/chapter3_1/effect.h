#ifndef EFFECT_H
#define EFFECT_H

#include <string>

// 咒语
class Spell {
public:
    Spell(std::string name) :
        _name(name) {
    }

    // ...
    // 主角是抽象工厂

private:
    std::string _name;
};

#endif