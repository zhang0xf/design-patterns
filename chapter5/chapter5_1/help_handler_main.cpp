#include "help_handler.h"

int main() {
    // 此处的对话框涉及打印, 因此这些对象被赋给与打印相关的主题.

    const Topic PRINT_TOPIC = 1;
    const Topic PARSER_OPERATION_TOPIC = 2;
    const Topic APPLICATION_TOPIC = 3;

    Application *application = new Application(APPLICATION_TOPIC);
    Dialog *dialog = new Dialog(application, PRINT_TOPIC);
    Button *button = new Button(dialog, PARSER_OPERATION_TOPIC);

    // 我们可对链上的任意对象调用(HandleHelp)以触发相应的帮助请求, 要从按钮对象开始搜索, 只需要对它调用(HandleHelp)
    button->HandleHelp();

    // 注意任何(HelpHandler)类都可以作为(Dialog)的后继者, 此外它的后继者可以被动态的改变.

    return 0;
}