#include "equipment.h"

// Equipment ==================================

Equipment::Equipment(const char *name) :
    _name(name) {
}

Equipment::~Equipment() {
}

const char *Equipment::Name() {
    return _name;
}

Watt Equipment::Power() {
    return 0.0;
}

Currency Equipment::NetPrice() {
    return 0;
}

Currency Equipment::DicountPrice() {
    return 0;
}

void Equipment::Add(Equipment *) {
}

void Equipment::Remove(Equipment *) {
}

// 缺省实现:在空集上迭代(由于叶子结点没有集合,与复合节点不同)
cps::Iterator<Equipment *> *Equipment::CreateIterator() {
    return new cps::NullIterator<Equipment *>();
}

// FloppyDisk ==================================

FloppyDisk::FloppyDisk(const char *name) :
    Equipment(name) {
}

FloppyDisk::~FloppyDisk() {
}

Watt FloppyDisk::Power() {
    return 0.0;
}

Currency FloppyDisk::NetPrice() {
    return 0;
}

Currency FloppyDisk::DicountPrice() {
    return 0;
}

// CompositeEquipment ===========================

CompositeEquipment::CompositeEquipment(const char *name) :
    Equipment(name) {
}

CompositeEquipment::~CompositeEquipment() {
}

Watt CompositeEquipment::Power() {
    return 0.0;
}

Currency CompositeEquipment::NetPrice() {
    cps::Iterator<Equipment *> *iter = CreateIterator();

    Currency total = 0;

    for (iter->First(); !iter->IsDone(); iter->Next()) {
        total += iter->CurrentItem()->NetPrice();
    }

    delete iter;
    return total;
}

Currency CompositeEquipment::DicountPrice() {
    return 0;
}

void CompositeEquipment::Add(Equipment *) {
}

void CompositeEquipment::Remove(Equipment *) {
}
// 返回一个List迭代器
cps::Iterator<Equipment *> *CompositeEquipment::CreateIterator() {
    cps::List<Equipment *> *pList = new cps::List<Equipment *>(100); // 简化版本
    return new cps::ListIterator<Equipment *>(pList);
}

// Chassis =======================================

Chassis::Chassis(const char *name) :
    CompositeEquipment(name) {
}

Chassis::~Chassis() {
}

Watt Chassis::Power() {
    return 0.0;
}

Currency Chassis::NetPrice() {
    return 0;
}

Currency Chassis::DicountPrice() {
    return 0;
}

// Cabinet =======================================

Cabinet::Cabinet(const char *name) :
    CompositeEquipment(name) {
}

Cabinet::~Cabinet() {
}

Watt Cabinet::Power() {
    return 0.0;
}

Currency Cabinet::NetPrice() {
    return 0;
}

Currency Cabinet::DicountPrice() {
    return 0;
}

// Bus ===========================================

Bus::Bus(const char *name) :
    CompositeEquipment(name) {
}

Bus::~Bus() {
}

Watt Bus::Power() {
    return 0.0;
}

Currency Bus::NetPrice() {
    return 0;
}

Currency Bus::DicountPrice() {
    return 0;
}

// Card ==========================================

Card::Card(const char *name) :
    Equipment(name) {
}

Card::~Card() {
}

Watt Card::Power() {
    return 0.0;
}

Currency Card::NetPrice() {
    return 0;
}

Currency Card::DicountPrice() {
    return 0;
}
