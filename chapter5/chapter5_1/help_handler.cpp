#include "help_handler.h"

HelpHandler::HelpHandler(HelpHandler *h, Topic t) :
    _successor(h), _topic(t) {
}

bool HelpHandler::HasHelp() {
    return _topic != NO_HELP_TOPIC;
}

void HelpHandler::SetHandler(HelpHandler *h, Topic t) {
    _successor = h;
    _topic = t;
}

void HelpHandler::HandleHelp() {
    if (_successor != 0) {
        _successor->HandleHelp();
    }
}

Widget::Widget(Widget *parent, Topic t) :
    HelpHandler(parent, t) {
    _parent = parent;
}

Button::Button(Widget *d, Topic t) :
    Widget(d, t) {
}

void Button::HandleHelp() {
    if (HasHelp()) {
        // offer help on the button
        // ...
    } else {
        HelpHandler::HandleHelp(); // 没有帮助主题, (HandleHelp)操作将该请求转发给它的后继者.
    }
}

Dialog::Dialog(HelpHandler *h, Topic t) :
    Widget(0) {
    SetHandler(h, t);
}

void Dialog::HandleHelp() {
    if (HasHelp()) {
        // offer help on the dialog
    } else {
        HelpHandler::HandleHelp();
    }
}

Application::Application(Topic t) :
    HelpHandler(0, t) {
}

void Application::HandleHelp() {
    // show a list of help topics.
}