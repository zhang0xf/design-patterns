#include "pm_window.h"

bool GpiBeginPath(HPS, long) {
    return false;
}

bool GpiSetCurrentPosition() {
    return false;
}

GPI_STATE GpiPolyLine(HPS, long, PPOINTL[]) {
    return GPI_ERROR;
}

bool GpiEndPath(HPS) {
    return false;
}

void GpiStokePath(HPS, long, long) {
}