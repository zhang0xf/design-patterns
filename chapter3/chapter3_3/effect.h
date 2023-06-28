#ifndef EFFECT_H
#define EFFECT_H

#include <string>

// 咒语
class Spell {
public:
    Spell(std::string name) :
        _name(name) {
    }

private:
    std::string _name;
};

#endif