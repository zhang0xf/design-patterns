#ifndef SINGLETON_H
#define SINGLETON_H

#include <list>
#include <string>

class Singleton {
public:
    static Singleton *Instance();

protected:
    Singleton(); // 构造器是保护型的

private:
    static Singleton *_instance;
};

// =======================================

// 创建(SingletonRegister)类的子类
// SingletonRegister不再负责创建单件，它的主要职责是使得供选择的单件对象在系统中可以访问.
class SingletonRegister {
public:
    typedef std::pair<const std::string, SingletonRegister *> NameSingletonPair;

    static void Register(const std::string &, SingletonRegister *); // (Register)以给定的名字注册(SingletonRegister)实例
    static SingletonRegister *Instance();

    virtual std::string PrintInfo();

protected:
    SingletonRegister();
    static SingletonRegister *LookUp(const std::string &); // (LookUp)根据给定单词查找

private:
    static SingletonRegister *_instance;
    static std::list<NameSingletonPair> *_register; // 每个(NameSingletonPair)对象将一个名字映射到一个单件
};

// (SingletonRegister)类如何注册自己?
class MySingleton : public SingletonRegister {
public:
    static MySingleton *Instance();

    virtual std::string PrintInfo();

protected:
    MySingleton();

private:
    static MySingleton *_instance;
};

#endif