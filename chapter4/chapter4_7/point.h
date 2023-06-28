#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    friend std::istream &operator>>(std::istream &, Point &);
    friend std::ostream &operator<<(std::ostream &, const Point &);
    friend bool operator==(const Point &, const Point &);

public:
    static Point Zero;
};

inline std::istream &operator>>(std::istream &is, Point &) {
    return is;
}

inline std::ostream &operator<<(std::ostream &os, const Point &) {
    return os;
}

inline bool operator==(const Point &, const Point &) {
    return false;
}

#endif