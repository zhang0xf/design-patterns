#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "def.h"

class Point {
public:
    static const Point Zero; // 静态成员(Zero)代表(Point(0, 0))

    Point(const Coord x = 0.0, const Coord y = 0.0);

    Coord X() const;
    void X(Coord x);

    Coord Y() const;
    void Y(Coord y);

    friend Point operator+(const Point &, const Point &);
    friend Point operator-(const Point &, const Point &);
    friend Point operator*(const Point &, const Point &);
    friend Point operator/(const Point &, const Point &);

    Point &operator+=(const Point &);
    Point &operator-=(const Point &);
    Point &operator*=(const Point &);
    Point &operator/=(const Point &);

    Point operator-();

    friend bool operator==(const Point &, const Point &);
    friend bool operator!=(const Point &, const Point &);

    friend std::ostream &operator<<(std::ostream &, const Point);
    friend std::istream &operator>>(std::istream &, Point &);

private:
    Coord _x;
    Coord _y;
};

Point operator+(const Point &, const Point &);
Point operator-(const Point &, const Point &);
Point operator*(const Point &, const Point &);
Point operator/(const Point &, const Point &);

bool operator==(const Point &, const Point &);
bool operator!=(const Point &, const Point &);

std::ostream &operator<<(std::ostream &, const Point);
std::istream &operator>>(std::istream &, Point &);

#endif