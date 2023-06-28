#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "def.h"

// (TextView)由原点、宽度和高度定义

class TextView {
public:
    TextView();
    void GetOrigin(Coord &x, Coord &y) const;
    void GetExtent(Coord &width, Coord &height) const;
    virtual bool IsEmpty() const;
};

#endif