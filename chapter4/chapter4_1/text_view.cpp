#include "text_view.h"

TextView::TextView() {
}

void TextView::GetOrigin(Coord &x, Coord &y) const {
    (void)x;
    (void)y;
}

void TextView::GetExtent(Coord &width, Coord &height) const {
    (void)width;
    (void)height;
}

bool TextView::IsEmpty() const {
    return true;
}