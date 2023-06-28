#ifndef PM_WINDOW_H
#define PM_WINDOW_H

// pm window system-specific state.

class HPS {
};

struct PPOINTL {
    double x;
    double y;
};

enum GPI_STATE {
    GPI_ERROR,
};

bool GpiBeginPath(HPS, long);
bool GpiSetCurrentPosition();
GPI_STATE GpiPolyLine(HPS, long, PPOINTL[]);
bool GpiEndPath(HPS);
void GpiStokePath(HPS, long, long);

#endif