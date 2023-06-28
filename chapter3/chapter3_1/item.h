#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item(int id) :
        _itemID(id) {
    }

    int GetId() const {
        return _itemID;
    }

    // ...
    // 主角是抽象工厂

private:
    int _itemID;
};

#endif