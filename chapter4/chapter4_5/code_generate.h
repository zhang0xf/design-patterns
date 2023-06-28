#ifndef CODE_GENERATE_H
#define CODE_GENERATE_H

#include "bytecode_stream.h"
#include "program_node_builder.h"

// (CodeGenerate)类是一个(Visitor)访问者
class CodeGenerator {
public:
    virtual void Visit(StatementNode *);
    virtual void Visit(ExpressionNode *);
    // ...

protected:
    CodeGenerator(ByteCodeStream &);
};

// (CodeGenerator)类有两个子类, 例如: (StackMachineCodeGenerator)和(RISCCodeGenerator), 分别为不同的硬件体系结构生成机器代码.
class StackMachineCodeGenerator : public CodeGenerator {
public:
};

class RISCCodeGenerator : public CodeGenerator {
public:
    RISCCodeGenerator(ByteCodeStream &);
};

#endif