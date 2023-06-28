#ifndef HELP_HANDLER_H
#define HELP_HANDLER_H

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

// (HelpHandler)类定义了处理帮助请求的接口, 它维护一个帮助主题(默认值为空), 并保持对帮助处理对象链中它的后继者的引用.

class HelpHandler {
public:
    HelpHandler(HelpHandler * = 0, Topic = NO_HELP_TOPIC);
    virtual bool HasHelp();
    virtual void SetHandler(HelpHandler *, Topic);
    virtual void HandleHelp();

private:
    HelpHandler *_successor;
    Topic _topic;
};

// 所有的窗口组件都是(Widget)抽象类的子类
// (Widget)类是(HelpHandler)的子类, 因为所有的用户界面元素都可有相关的帮助

class Widget : public HelpHandler {
protected:
    Widget(Widget *parent, Topic t = NO_HELP_TOPIC);

private:
    Widget *_parent;
};

// 在我们的例子中, 按钮(Button)是链上的第一个处理者

class Button : public Widget {
public:
    Button(Widget *d, Topic t = NO_HELP_TOPIC); // 两个参数: 对包含它的窗口组件的引用和其自身的帮助主题

    virtual void HandleHelp();
    // widget operations that Button overrides ...
};

// (Dialog)实现了一个类似的策略, 只不过它的后继者不是一个窗口组件而是任意的帮助请求处理对象

class Dialog : public Widget {
public:
    Dialog(HelpHandler *h, Topic t = NO_HELP_TOPIC);
    virtual void HandleHelp();

    // widget operations that Button overrides ...
    // ...
};

// 在链的末端是一个(Application)的实例
class Application : public HelpHandler {
public:
    Application(Topic t);
    virtual void HandleHelp();
    // application-specific  operations...
};

#endif