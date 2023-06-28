#ifndef DEF_H
#define DEF_H

namespace MAP {

enum Direction {
    North,
    South,
    East,
    West
}; // enum Direction

}; // namespace MAP

#define UNUSED(x) (void)(x) // fix error: unused parameter 'room' [-Werror,-Wunused-parameter]

#endif