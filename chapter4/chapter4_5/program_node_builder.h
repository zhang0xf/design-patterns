#ifndef PROGRAM_NODE_BUILDER_H
#define PROGRAM_NODE_BUILDER_H

#include "iterator.h"

// 语法分析树由(ProgramNode)的子类(如: (StatementNode)和(ExpressionNode))的实例构成.
// (ProgramNode)的层次结构是(Composite)组合模式的一个应用实例.
class CodeGenerator;
class ProgramNode {
public:
    // program node manipulation.
    virtual void GetSourcePosition(int &line, int &index);
    // ...

    // child manipulation.
    virtual void Add(ProgramNode *);
    virtual void Remove(ProgramNode *);
    // ...

    // (Traverse)操作以一个(CodeGenerate)对象为参数, (ProgramNode)子类使用这个对象产生机器代码.
    virtual void Traverse(CodeGenerator &);

protected:
    cps::ListIterator<ProgramNode *> _children; // error: "zsh: segmentation fault" 可能由于这里是null
};

class StatementNode : public ProgramNode {
public:
    virtual void Traverse(CodeGenerator &);
};

class ExpressionNode : public ProgramNode {
public:
    virtual void Traverse(CodeGenerator &);
};

// (Parser)类回调(ProgramNodeBuilder)逐步建立语法分析树, 这些类遵循(Builder)生成器模式进行交互.

class ProgramNodeBuilder {
public:
    ProgramNodeBuilder();

    virtual ProgramNode *NewVariable(const char *variableName) const;
    virtual ProgramNode *NewAssignment(ProgramNode *variable, ProgramNode *expression) const;
    virtual ProgramNode *NewReturnStatement(ProgramNode *value) const;
    virtual ProgramNode *NewCondition(ProgramNode *condition, ProgramNode *truePart, ProgramNode *falsePart) const;

    // ...

    ProgramNode *GetRootNode();

private:
    ProgramNode *_node;
};

#endif