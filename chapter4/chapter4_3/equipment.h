#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "def.h"
#include "iterator.h"

// (Equipment)类为部分-整体层次结构中的所有设备定义了一个接口.
// (Equipment)申明一些操作返回一个设备的属性,例如它的能量消耗和价格.

class Equipment {
public:
    virtual ~Equipment();

    const char *Name();

    virtual Watt Power(); // watt = 瓦特
    virtual Currency NetPrice();
    virtual Currency DicountPrice();

    virtual void Add(Equipment *);
    virtual void Remove(Equipment *);

    // 该操作为了访问它的零件返回一个(Iterator), 缺省实现返回一个(NullIterator), 它在空集上迭代.
    virtual cps::Iterator<Equipment *> *CreateIterator();

protected:
    Equipment(const char *);

private:
    const char *_name;
};

// (Equipment)的子类包括表示磁盘驱动器、集成电路和开关的Leaf类.
class FloppyDisk : public Equipment {
public:
    FloppyDisk(const char *);
    virtual ~FloppyDisk();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();
};

// (CompositeEquipment)是包含其他设备的基类, 也是(Equipment)的子类
// (CompositeEquipment)为访问和管理子设备定义了一些操作
// 操作(Add)和(Remove)从存储在(_equipments)成员变量的设备列表中插入并删除设备
// 操作(CreateIterator)返回一个迭代器(ListIterator的一个实例)遍历这个链表
class CompositeEquipment : public Equipment {
public:
    virtual ~CompositeEquipment();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();

    virtual void Add(Equipment *);
    virtual void Remove(Equipment *);
    virtual cps::Iterator<Equipment *> *CreateIterator();

protected:
    CompositeEquipment(const char *);

private:
    cps::List<Equipment *> _equipments;
};

// 我们将计算机的底盘表示为(CompositeEquipment)的子类(Chassis), (Chassis)从(CompositeEquipment)继承了与子类有关的操作.
class Chassis : public CompositeEquipment {
public:
    Chassis(const char *);
    virtual ~Chassis();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();
};

// 我们可以用相似的方式定义其他设备,如:(Cabinet)和(Bus).这样我们就得到了组装一台(非常简单的)个人计算机所需的所有设备.
// Cabinet = 机壳
class Cabinet : public CompositeEquipment {
public:
    Cabinet(const char *);
    virtual ~Cabinet();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();
};

// Bus = 总线
class Bus : public CompositeEquipment {
public:
    Bus(const char *);
    virtual ~Bus();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();
};

class Card : public Equipment {
public:
    Card(const char *);
    virtual ~Card();

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DicountPrice();
};

#endif