#ifndef WINDOW_H
#define WINDOW_H

#include "view.h"
#include "windowimp.h"

// (Window)类为客户应用程序定义了窗口抽象类
// (Window)维护一个(WindowImp)的引用, (WindowImp)抽象类定义了一个对底层窗口系统的接口

class Window {
public:
    Window(View *contents);

    // request handled by window
    virtual void DrawContents();

    virtual void Open();
    virtual void Close();
    virtual void Iconify();
    virtual void Deiconify();

    // request forwarded to implementation.
    virtual void SetOrigin(const Point &at);
    virtual void SetExtent(const Point &extent);
    virtual void Raise();
    virtual void Lower();

    virtual void DrawLine(const Point &, const Point &);
    virtual void DrawRect(const Point &, const Point &);
    virtual void DrawPolygon(const Point[], int n);
    virtual void Drawtext(const char *, const Point &);

protected:
    // 一个窗口如何获取正确的(WindowImp)实例?
    WindowImp *GetWindowImp();
    View *GetView();

private:
    WindowImp *_imp;
    View *_content; // the window's contents.
};

// (Window)的子类定义了应用程序可能用到的不同类型的窗口, 如: 应用窗口、图标、对话框临时窗口以及工具箱的移动面板等.
// (ApplicationWindow)类将实现(DrawContents)操作以绘制它所存储的View实例
class ApplicationWindow : public Window {
public:
    // ...
    virtual void DrawContents();
};

// (IconWindow)中存储了它所显示的图标对应的位图名称
class IconWindow : public Window {
public:
    // ...
    virtual void DrawContents();

private:
    const char *_bitmapName;
};

#endif