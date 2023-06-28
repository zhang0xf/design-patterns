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

private:
    int _itemID;
};

#endif