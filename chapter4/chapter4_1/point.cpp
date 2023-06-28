#include "point.h"

static const Point Zero = Point();

Point::Point(const Coord x, const Coord y) :
    _x(x), _y(y) {
}

Coord Point::X() const {
    return _x;
}

void Point::X(Coord x) {
    _x = x;
}

Coord Point::Y() const {
    return _y;
}

void Point::Y(Coord y) {
    _y = y;
}

Point &Point::operator+=(const Point &other) {
    this->X(this->X() + other.X());
    this->Y(this->Y() + other.Y());
    return *this;
}

Point &Point::operator-=(const Point &other) {
    this->X(this->X() - other.X());
    this->Y(this->Y() - other.Y());
    return *this;
}

Point &Point::operator*=(const Point &other) {
    this->X(this->X() * other.X());
    this->Y(this->Y() * other.Y());
    return *this;
}

Point &Point::operator/=(const Point &other) {
    this->X(this->X() / other.X());
    this->Y(this->Y() / other.Y());
    return *this;
}

Point Point::operator-() {
    return Point(); // TODO ???
}

Point operator+(const Point &p1, const Point &p2) {
    Point ret;
    ret.X(p1.X() + p2.X());
    ret.Y(p1.Y() + p2.Y());
    return ret;
}

Point operator-(const Point &p1, const Point &p2) {
    Point ret;
    ret.X(p1.X() - p2.X());
    ret.Y(p1.Y() - p2.Y());
    return ret;
}

Point operator*(const Point &p1, const Point &p2) {
    Point ret;
    ret.X(p1.X() * p2.X());
    ret.Y(p1.Y() * p2.Y());
    return ret;
}

Point operator/(const Point &p1, const Point &p2) {
    Point ret;
    ret.X(p1.X() / p2.X());
    ret.Y(p1.Y() / p2.Y());
    return ret;
}

bool operator==(const Point &p1, const Point &p2) {
    if (p1.X() == p2.X() && p1.Y() == p2.Y()) {
        return true;
    }
    return false;
}

bool operator!=(const Point &p1, const Point &p2) {
    if (p1.X() != p2.X() || p1.Y() != p2.Y()) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Point p) {
    os << " (" << p.X() << " , " << p.Y() << ") " << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Point &p) {
    is >> p._x;
    is >> p._y;
    return is;
}