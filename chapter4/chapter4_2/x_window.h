#ifndef X_WINDOW_H
#define X_WINDOW_H

// x window system-specific state.

class Display {
};

class Drawable {
};

class GC {
};

void XDrawRectangle(Display *, Drawable, GC, double, double, double, double);

#endif