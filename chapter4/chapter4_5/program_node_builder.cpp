#include "code_generate.h"
#include "program_node_builder.h"

// ProgramNode =======================================

void ProgramNode::Add(ProgramNode *) {
}

void ProgramNode::Remove(ProgramNode *) {
}

void ProgramNode::Traverse(CodeGenerator &) {
}

void ProgramNode::GetSourcePosition(int &line, int &index) {
    UNUSED(line);
    UNUSED(index);
}

// StatementNode ======================================

void StatementNode::Traverse(CodeGenerator &) {
}

// ExpressionNode =====================================

void ExpressionNode::Traverse(CodeGenerator &cg) {
    cg.Visit(this);

    cps::ListIterator<ProgramNode *> i(_children);

    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Traverse(cg);
    }
}

ProgramNodeBuilder::ProgramNodeBuilder() {
}

ProgramNode *ProgramNodeBuilder::NewVariable(const char *variableName) const {
    UNUSED(variableName);
    return _node;
}

ProgramNode *ProgramNodeBuilder::NewAssignment(ProgramNode *variable, ProgramNode *expression) const {
    UNUSED(variable);
    UNUSED(expression);
    return _node;
}

ProgramNode *ProgramNodeBuilder::NewReturnStatement(ProgramNode *value) const {
    UNUSED(value);
    return _node;
}

ProgramNode *ProgramNodeBuilder::NewCondition(ProgramNode *condition, ProgramNode *truePart, ProgramNode *falsePart) const {
    UNUSED(condition);
    UNUSED(truePart);
    UNUSED(falsePart);
    return _node;
}

ProgramNode *ProgramNodeBuilder::GetRootNode() {
    return _node;
}
