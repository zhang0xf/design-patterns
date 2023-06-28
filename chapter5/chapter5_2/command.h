#ifndef COMMAND_H
#define COMMAND_H

#include "list.h"
#include "application.h"

// 定义抽象的(Command)类
class Command {
public:
    virtual ~Command();

    virtual void Execute() = 0;

protected:
    Command();
};

// (OpenCommand)打开一个名字由用户指定的文档
class OpenCommand : public Command {
public:
    OpenCommand(Application *);

    virtual void Execute();

protected:
    virtual const char *AskUser(); // 提示用户输入要打开的文档名

private:
    Application *_application;
    char *_response;
};

class PasteCommand : public Command {
public:
    PasteCommand(Document *);

    virtual void Execute();

private:
    Document *_document;
};

class Action {
};

// 对于不需要撤销和不需要参数的简单命令, 可以使用一个类模版来参数化该命令的接受者.
// 维护一个接收者对象和一个动作之间的绑定, 而这一动作是用指向一个成员函数的指针存储的.
template <class Receiver>
class SimpleCommand : public Command {
public:
    typedef void (Receiver::*Action)(); // ???

    SimpleCommand(Receiver *r, Action a) :
        _receiver(r), _action(a) {
    }

    virtual void Execute();

private:
    Action _action;
    Receiver *_receiver;
};

template <class Receiver>
void SimpleCommand<Receiver>::Execute() {
    (_receiver->*_action)(); // ???
}

// (MacroCommand)管理一个子命令序列, 它提供了增加和删除子命令的操作.
// 这里不需要显示的接受者, 因为这些子命令已经定义了它们各自的接受者.
class MacroCommand : public Command {
public:
    MacroCommand();
    virtual ~MacroCommand();

    virtual void Add(Command *);
    virtual void Remove(Command *);

    virtual void Execute();

private:
    cps::List<Command *> *_cmds;
};

#endif