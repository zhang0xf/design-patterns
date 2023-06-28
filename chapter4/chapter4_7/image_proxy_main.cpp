#include "image_proxy.h"

int main() {
    TextDocument *text = new TextDocument;
    // ...

    text->Insert(new ImageProxy("filePath"));

    return 0;
}