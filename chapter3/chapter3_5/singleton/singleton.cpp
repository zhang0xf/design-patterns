#include <algorithm>
#include <iostream>
#include "singleton.h"

Singleton *Singleton::_instance = 0;

// 客户仅通过(Instance)访问这个单件
Singleton *Singleton::Instance() {
    if (_instance == 0) {
        _instance = new Singleton(); // 惰性初始化
    }
    return _instance;
}

Singleton::Singleton() {
}

SingletonRegister *SingletonRegister::_instance = 0; // 返回的是子类单件对象而非自己
std::list<SingletonRegister::NameSingletonPair> *
    SingletonRegister::_register = new std::list<SingletonRegister::NameSingletonPair>; // 注意作用域

SingletonRegister *SingletonRegister::Instance() {
    if (_instance == 0) {
        const char *singletonName = getenv("SINGLETON"); // 我们假定一个环境变量指定了所需要的单件的名字
        (void)singletonName;                             // fix error : unused variable 'singletonName'
        // user or envirnoment supplies this at startup

        // 简化测试
        std::string singletonName2("MySingleton");

        _instance = LookUp(singletonName2);
        // LookUp return 0 if there is no such singleton.
    }
    return _instance;
}

std::string SingletonRegister::PrintInfo() {
    return std::string("");
}

SingletonRegister::SingletonRegister() {
}

void SingletonRegister::Register(const std::string &name, SingletonRegister *toRegister) {
    _register->push_back(std::make_pair(name, toRegister));
}

SingletonRegister *SingletonRegister::LookUp(const std::string &name) {
    std::list<NameSingletonPair>::iterator iter;
    for (iter = _register->begin(); iter != _register->end(); iter++) {
        if (iter->first == name) {
            return iter->second;
        }
    }
    return nullptr;
}

MySingleton *MySingleton::_instance = 0;

MySingleton *MySingleton::Instance() {
    if (_instance == 0) {
        _instance = new MySingleton();
    }
    return _instance;
}

std::string MySingleton::PrintInfo() {
    std::string info("it's me, MySingleton, hia hia hia ...");
    std::cout << info << std::endl;
    return info;
}

// 除非实例化否则这个构造器是不会被调用的, 可以定义一个静态实例来避免这个问题, 如: 在(MySingleton)实现的文件中添加定义
MySingleton::MySingleton() {
    // ...
    // 在构造器中注册自己
    SingletonRegister::Register("MySingleton", this);
}

// 添加(MySingleton)定义, 调用构造器, 被(Register)
static MySingleton *theSingleton = MySingleton::Instance();