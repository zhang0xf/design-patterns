#ifndef LIST_H
#define LIST_H

#include "def.h"

// 列表和迭代器接口

// List接口
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

// 抽象的迭代器类
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
Iterator<Item>::Iterator() {
}

template <class Item>
Iterator<Item>::~Iterator() {
}

// 迭代器子类的实现
// 列表迭代器是迭代器的一个子类
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
    long _current;
};

template <class Item>
ListIterator<Item>::ListIterator(const List<Item> *aList) :
    _list(aList), _current(0) {
}

template <class Item>
ListIterator<Item>::~ListIterator() {
}

template <class Item>
void ListIterator<Item>::First() {
    _current = 0;
}

template <class Item>
void ListIterator<Item>::Next() {
    _current++;
}

template <class Item>
bool ListIterator<Item>::IsDone() const {
    return _current >= _list->Count();
}

template <class Item>
Item ListIterator<Item>::CurrentItem() const {
    if (IsDone()) {
        // throw IteratorOutOfBounds;
    }
    return _list->Get(_current);
}

// (ReverseListIterator)反向列表迭代器同理, 略
// ...

// 思考(List)的一种变体(SkipList)
// 为了支持多态迭代(避免限定于一种特定的列表实现)
// (AbstractList)定义一个(Factory Method), 称为(CreateIterator)
template <class Item>
class AbstractList {
public:
    virtual Iterator<Item> *CreateIterator() const = 0; // 各个列表重定义此方法以返回相应的迭代器.
};

// (List)和(SkipList)都是(AbstractList)的子类
template <typename Item>
class List2 : public AbstractList<Item> {
public:
    List2(long size = DEFAULT_LIST_CAPACITY);
    List2(List2 &);

    ~List2();

    List2 &operator=(const List2 &);

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

    virtual Iterator<Item> *CreateIterator() const;
};

template <typename Item>
List2<Item>::List2(long size) {
    UNUSED(size);
}

template <typename Item>
List2<Item>::List2(List2 &) {
}

template <typename Item>
List2<Item>::~List2() {
}

template <typename Item>
List2<Item> &List2<Item>::operator=(const List2 &list) {
    // 简化版本
    return list;
}

template <typename Item>
long List2<Item>::Count() const {
    return 0;
}

template <typename Item>
Item &List2<Item>::Get(long index) const {
    UNUSED(index);
    Item *p = new Item();
    return *p;
}

template <typename Item>
Item &List2<Item>::First() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
Item &List2<Item>::Last() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
bool List2<Item>::Includes(const Item &) const {
    return false;
}

template <typename Item>
void List2<Item>::Append(const Item &) {
}

template <typename Item>
void List2<Item>::Prepend(const Item &) {
}

template <typename Item>
void List2<Item>::Remove(const Item &) {
}

template <typename Item>
void List2<Item>::RemoveLast() {
}

template <typename Item>
void List2<Item>::RemoveFirst() {
}

template <typename Item>
void List2<Item>::RemoveAll() {
}

template <typename Item>
Item &List2<Item>::Top() const {
    Item *p = new Item();
    return *p;
}

template <typename Item>
void List2<Item>::Push(const Item &) {
}

template <typename Item>
Item &List2<Item>::Pop() {
    Item *p = new Item();
    return *p;
}
template <typename Item>
Iterator<Item> *List2<Item>::CreateIterator() const {
    // (List2)重定义(CreateIterator)返回一个(ListIterator)对象
    return new ListIterator<Item>(this);
}

// 保证迭代器被删除(CreateIterator)返回的是一个动态分配的迭代器对象, 在使用完毕后必须删除这个迭代器
// 为方便客户, 我们提供一个(IteratorPtr)作为迭代器的代理
// (IteratorPtr)总是在栈上分配, C++自动调用它的析构器, 而该析构器将删除真正的迭代器
// (IteratorPtr)重载了操作符(->)和(*), 使得可将(IteratorPtr)对象用作一个指向迭代器的指针
template <typename Item>
class IteratorPtr {
public:
    IteratorPtr(Iterator<Item> *it) :
        _it(it) {
    }

    ~IteratorPtr() {
        delete _it;
    }

    Iterator<Item> *operator->() {
        return _it;
    }

    Iterator<Item> &operator*() {
        return *_it;
    }

private:
    // disallow copy and assignment to avoid multiple deletions of _it
    IteratorPtr(const IteratorPtr &);
    IteratorPtr &operator=(const IteratorPtr &);

private:
    Iterator<Item> *_it;
};

// 内部的(ListIterator)
// 此时由迭代器控制迭代, 并对列表中的每一个元素施行同一个操作
template <class Item>
class ListTraverser {
public:
    ListTraverser(List<Item> *aList);
    bool Traverse(); // (Traverse)启动遍历, 并对每一个元素调用(ProcessItem)

protected:
    // 内部迭代器可在某次(ProcessItem)返回(false)时提前终止本次遍历.
    virtual bool ProcessItem(const Item &) = 0;

private:
    ListIterator<Item> _iterator; // 使用一个外部的(ListIterator)进行遍历
};

template <class Item>
ListTraverser<Item>::ListTraverser(List<Item> *aList) :
    _iterator(aList) {
}

template <class Item>
bool ListTraverser<Item>::Traverse() {
    bool result = false;
    for (_iterator.First(); !_iterator.IsDone(); _iterator.Next()) {
        result = ProcessItem(_iterator.CurrentItem());
        if (result == false) {
            break;
        }
    }
    return result;
}

// 与外部迭代器相比要复杂一些, 但是可以封装不同类型的迭代, 如:(FilteringListTraverser)
template <class Item>
class FilteringListTraverser {
public:
    FilteringListTraverser(List<Item> *aList);
    bool Traverse();

protected:
    virtual bool ProcessItem(const Item &) = 0;
    virtual bool TestItem(const Item &) = 0; // 子类重定义(TestItem)以指定所需的测试

private:
    ListIterator<Item> _iterator;
};

template <class Item>
bool FilteringListTraverser<Item>::Traverse() {
    bool result = false;
    for (_iterator.First(); !_iterator.IsDone(); _iterator.Next()) {
        if (TestItem(_iterator.CurrentItem())) { // 多了测试
            result = ProcessItem(_iterator.CurrentItem());
            if (result == false) {
                break;
            }
        }
    }
    return result;
}

#endif