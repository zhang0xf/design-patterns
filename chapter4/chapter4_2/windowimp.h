#ifndef WINDOWIMP_H
#define WINDOWIMP_H

#include "point.h"
#include "x_window.h"
#include "pm_window.h"

// (Window)的操作由(WindowImp)的接口定义,如:(Window::DrawRect)

class WindowImp {
public:
    virtual void ImpTop() = 0;
    virtual void ImpBottom() = 0;
    virtual void ImpSetExtent(const Point &) = 0;
    virtual void ImpSetOrigin(const Point &) = 0;

    virtual void DeviceRect(Coord, Coord, Coord, Coord) = 0;
    virtual void DeviceText(const char *, Coord, Coord) = 0;
    virtual void DeviceBitmap(const char *, Coord, Coord) = 0;

    // lots more functions for drawing on windows ...

protected:
    WindowImp();
};

// (WindowImp)子类可支持不同的窗口系统, (XWindowImp)子类支持X Window系统
class XWindowImp : public WindowImp {
public:
    XWindowImp();

    virtual void DeviceRect(Coord, Coord, Coord, Coord);

    // reminder of public interface ...

private:
    // lots of X window system-specific state, including:
    Display *_dpy;
    Drawable _winid;
    GC _gc;
};

// 对于Presentation Manager(PM), 我们定义(PMWindowImp)类
class PMWindowImp : public WindowImp {
public:
    PMWindowImp();
    virtual void DeviceRect(Coord, Coord, Coord, Coord);

    // reminder of public interface ...

private:
    // lots of PM window system-specific state, including:
    HPS _hps;
};

#endif