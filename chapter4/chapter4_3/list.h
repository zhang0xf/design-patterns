#ifndef LIST_H
#define LIST_H

#include "def.h"

// cps = composite

namespace cps {

template <typename Item>
class List {
public:
    List(long size = DEFAULT_LIST_CAPACITY);
    List(List &);

    ~List();

    List &operator=(const List &);

    long Count() const;
    Item &Get(long index) const;
    Item &First() const;
    Item &Last() const;
    bool Includes(const Item &) const;

    void Append(const Item &);
    void Prepend(const Item &);

    void Remove(const Item &);
    void RemoveLast();
    void RemoveFirst();
    void RemoveAll();

    Item &Top() const;
    void Push(const Item &);
    Item &Pop();
};

// 全部省略实现!

template <typename Item>
List<Item>::List(long size) {
    UNUSED(size);
}

template <typename Item>
List<Item>::List(List &) {
}

template <typename Item>
List<Item>::~List() {
}

template <typename Item>
List<Item> &List<Item>::operator=(const List &list) {
    // 简化版本
    return list;
}

template <typename Item>
long List<Item>::Count() const {
    return 0;
}

template <typename Item>
Item &List<Item>::Get(long index) const {
    UNUSED(index);
    Item *p = new Item();
    return *p;
}

template <typename Item>
Item &List<Item>::First() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
Item &List<Item>::Last() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
bool List<Item>::Includes(const Item &) const {
    return false;
}

template <typename Item>
void List<Item>::Append(const Item &) {
}

template <typename Item>
void List<Item>::Prepend(const Item &) {
}

template <typename Item>
void List<Item>::Remove(const Item &) {
}

template <typename Item>
void List<Item>::RemoveLast() {
}

template <typename Item>
void List<Item>::RemoveFirst() {
}

template <typename Item>
void List<Item>::RemoveAll() {
}

template <typename Item>
Item &List<Item>::Top() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
void List<Item>::Push(const Item &) {
}

template <typename Item>
Item &List<Item>::Pop() {
    Item *p = new Item();
    return *p;
}

} // namespace cps

#endif