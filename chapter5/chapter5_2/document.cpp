#include "document.h"

Document::Document() {
    _name = 0;
}

Document::Document(const char *name) {
    _name = name;
}

bool Document::Open() {
    return false;
}

bool Document::Paste() {
    return false;
}
