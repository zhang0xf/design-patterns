#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include "def.h"

// (Scanner)类接受字符流并产生一个标识符流, 一次产生一个(Token)
// (Token)类封装了变成语言中的标识符.

class Scanner {
public:
    Scanner(std::istream &);

    virtual ~Scanner();

    virtual Token &Scan();

private:
    std::istream &_inputStream;
};

#endif