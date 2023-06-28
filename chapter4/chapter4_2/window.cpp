#include "window.h"

Window::Window(View *contents) {
    UNUSED(contents);
}

void Window::DrawContents() {
}

void Window::Open() {
}

void Window::Close() {
}

void Window::Iconify() {
}

void Window::Deiconify() {
}

void Window::SetOrigin(const Point &at) {
    UNUSED(at);
}

void Window::SetExtent(const Point &extent) {
    UNUSED(extent);
}

void Window::Raise() {
}

void Window::Lower() {
}

void Window::DrawLine(const Point &, const Point &) {
}

// 在调用WindowImp操作在窗口中绘制矩形之前, DrawRect必须从它的两个Point参数中提取四个坐标值
void Window::DrawRect(const Point &p1, const Point &p2) {
    WindowImp *imp = GetWindowImp();
    imp->DeviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
}

void Window::DrawPolygon(const Point[], int n) {
    UNUSED(n);
}

void Window::Drawtext(const char *, const Point &) {
}

// 我们假设(Window)类具有获取WindowImp子类的职责,(GetWindowImp)操作负责从一个抽象工厂(Abstract Factory)获取正确的实例
WindowImp *Window::GetWindowImp() {
    if (_imp == 0) {
        // TODO
        // _imp = WindowSystemFactory::Instance()->MakeWindowImp();
    }
    return _imp;
}

View *Window::GetView() {
    return _content;
}

void ApplicationWindow::DrawContents() {
    GetView()->DrawOn(this);
}

void IconWindow::DrawContents() {
    WindowImp *imp = GetWindowImp();
    if (imp != 0) {
        imp->DeviceBitmap(_bitmapName, 0.0, 0.0);
    }
}