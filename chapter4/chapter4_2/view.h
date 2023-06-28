#ifndef VIEW_H
#define VIEW_H

// 避免与(Window.h)互相包含
class Window;

class View {
public:
    void DrawOn(Window *);
};

#endif