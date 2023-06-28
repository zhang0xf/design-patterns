#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include "bytecode_stream.h"

// (Compiler)类是一个(Facade)外观模式, 他将所有部件集中在一起.
// (Compiler)提供了一个简单的接口, 用于为特定的机器编译源代码并生成可执行代码.

class Compiler {
public:
    Compiler();

    virtual void Compile(std::istream &, ByteCodeStream &);
};

#endif