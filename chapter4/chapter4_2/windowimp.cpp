#include <cmath>
#include <algorithm>
#include "windowimp.h"

// 这些子类用窗口系统的基本操作实现(WindowImp)操作.
void XWindowImp::DeviceRect(Coord x0, Coord y0, Coord x1, Coord y1) {
    int x = round(std::min(x0, x1));
    int y = round(std::min(y0, y1));
    int w = round(std::abs(x0 - x1));
    int h = round(std::abs(y0 - y1));
    XDrawRectangle(_dpy, _winid, _gc, x, y, w, h);
}

// PM的实现部分可能像下面这样:
void PMWindowImp::DeviceRect(Coord x0, Coord y0, Coord x1, Coord y1) {
    Coord left = std::min(x0, x1);
    Coord right = std::max(x0, x1);
    Coord bottom = std::min(x0, x1);
    Coord top = std::max(y0, y1);

    PPOINTL point[4];

    point[0].x = left;
    point[0].y = top;
    point[1].x = right;
    point[1].y = top;
    point[2].x = right;
    point[2].y = bottom;
    point[3].x = left;
    point[3].y = bottom;

    if ((GpiBeginPath(_hps, 1L) == false)
        || (GpiSetCurrentPosition() == false)
        || (GpiPolyLine(_hps, 4L, point) == GPI_ERROR)
        || (GpiEndPath(_hps) == false)) {
        // report error
    } else {
        GpiStokePath(_hps, 1L, 0L);
    }
}