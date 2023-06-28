#include "component.h"
#include "window.h"
#include "text_view.h"

int main() {
    // 创建一个文本视图以及放入这个文本视图的窗口
    Window *window = new Window();
    TextView *textView = new TextView();

    // textView放入窗口
    window->SetContents(textView);

    // 但是我们想要一个有边界和可以滚动的TextView, 因此我们将它放入窗口之前对其进行装饰
    window->SetContents(
        new BorderDecorator(
            new ScrollDecorator(textView), 1));

    return 0;
}