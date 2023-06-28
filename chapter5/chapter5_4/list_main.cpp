#include "list.h"

// 列表元素
class Employee {
public:
    // ...

    // 打印信息
    void Print() {
    }
};

// 遍历列表, 打印信息
void PrintEmpolyees(Iterator<Employee *> &i) {
    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Print();
    }
}

// 继承模版类?
class PrintNEmployees : public ListTraverser<Employee *> {
public:
    PrintNEmployees(List<Employee *> *aList, int n) :
        ListTraverser<Employee *>(aList), _total(n), _count(0) {
    }

protected:
    virtual bool ProcessItem(Employee *const &e); // ? 注意: 模版类型->具体类型

private:
    // 子类中存储累计状态
    int _total;
    int _count;
};

// 打印前10个
bool PrintNEmployees::ProcessItem(Employee *const &e) {
    _count++;
    e->Print();
    return _count < _total;
}

int main() {
    // 使用迭代器

    List<Employee *> *employees = 0; // 用作初始化
    // ...

    ListIterator<Employee *> forward(employees);
    PrintEmpolyees(forward);

    // ----------------------------------------

    // (IteratorPtr)简化了打印代码:
    AbstractList<Employee *> *employees2 = 0; // 用作初始化
    // ...

    IteratorPtr<Employee *> pIterator(employees2->CreateIterator());
    PrintEmpolyees(*pIterator);

    // ----------------------------------------

    // 使用(ListTraverser)打印雇员列表中的头10个雇员
    // 必须定义一个(ListTraverser)子类并重定义其(ProcessItem)操作.
    List<Employee *> *employees3 = 0;
    PrintNEmployees pa(employees3, 10);
    pa.Traverse(); // 整个迭代的逻辑是可以复用的!

    return 0;
}