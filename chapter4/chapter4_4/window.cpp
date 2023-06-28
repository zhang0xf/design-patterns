#include "window.h"

Window::Window() {
}

// 需要将一个可视组件放入窗口对象中,假设(Window)类为此已经提供了一个(SetContents)操作
void Window::SetContents(VisualComponent *contents) {
    (void)contents;
    // ...
}