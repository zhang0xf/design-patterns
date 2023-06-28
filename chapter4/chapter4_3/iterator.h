#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

// cps = composite

namespace cps {

// (Iterator)定义了一种遍历对象集合的接口的抽象类.

template <class Item>
class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Item CurrentItem() const = 0;

    virtual ~Iterator();

protected:
    Iterator();
};

template <class Item>
Iterator<Item>::Iterator() { // before (ListIterator)
}

template <class Item>
Iterator<Item>::~Iterator() {
}

// 用作缺省: 在空集上迭代
template <class Item>
class NullIterator : public Iterator<Item> {
public:
    NullIterator();

    virtual ~NullIterator();

    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual Item CurrentItem() const;
};

template <class Item>
NullIterator<Item>::NullIterator() {
}

template <class Item>
NullIterator<Item>::~NullIterator() {
}

template <class Item>
void NullIterator<Item>::First() {
}

template <class Item>
void NullIterator<Item>::Next() {
}

template <class Item>
bool NullIterator<Item>::IsDone() const {
    return false;
}

template <class Item>
Item NullIterator<Item>::CurrentItem() const {
    return Item();
}

// (ListIterator)实现了遍历列表的Iterator接口, 它的构造函数以一个待遍历的列表为参数.
template <class Item>
class ListIterator : public Iterator<Item> {
public:
    ListIterator(const List<Item> *aList);

    virtual ~ListIterator();

    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual Item CurrentItem() const;

private:
    const List<Item> *_list;
};

template <class Item>
ListIterator<Item>::ListIterator(const List<Item> *aList) :
    _list(aList) {
}

template <class Item>
ListIterator<Item>::~ListIterator() {
}

template <class Item>
void ListIterator<Item>::First() {
}

template <class Item>
void ListIterator<Item>::Next() {
}

template <class Item>
bool ListIterator<Item>::IsDone() const {
    return false;
}

template <class Item>
Item ListIterator<Item>::CurrentItem() const {
    return Item();
}

} // namespace cps

#endif