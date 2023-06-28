#include <string.h> // strdup
#include "boolean_exp.h"

bool Context::LookUp(const char *) const {
    return false;
}

void Context::Assign(VariableExp *, bool) {
}

BooleanExp::BooleanExp() {
}

BooleanExp::~BooleanExp() {
}

VariableExp::VariableExp(const char *name) {
    _name = strdup(name);
}

VariableExp::~VariableExp() {
}

bool VariableExp::Evaluate(Context &aContext) {
    return aContext.LookUp(_name);
}

// 使用表达式替换一个变量
BooleanExp *VariableExp::Replace(const char *name, BooleanExp &exp) {
    if (strcmp(name, _name) == 0) {
        return exp.Copy();
    } else {
        return new VariableExp(_name);
    }
}

BooleanExp *VariableExp::Copy() const {
    return new VariableExp(_name);
}

AndExp::AndExp(BooleanExp *op1, BooleanExp *op2) {
    _operand1 = op1;
    _operand2 = op2;
}

AndExp::~AndExp() {
}

bool AndExp::Evaluate(Context &aContext) {
    return _operand1->Evaluate(aContext) && _operand2->Evaluate(aContext);
}

BooleanExp *AndExp::Replace(const char *name, BooleanExp &exp) {
    return new AndExp(_operand1->Replace(name, exp), _operand2->Replace(name, exp));
}

BooleanExp *AndExp::Copy() const {
    return new AndExp(_operand1->Copy(), _operand2->Copy());
}

OrExp::OrExp(BooleanExp *op1, BooleanExp *op2) {
    _operand1 = op1;
    _operand2 = op2;
}

OrExp::~OrExp() {
}

bool OrExp::Evaluate(Context &aContext) {
    return _operand1->Evaluate(aContext) || _operand2->Evaluate(aContext);
}

BooleanExp *OrExp::Replace(const char *name, BooleanExp &exp) {
    return new OrExp(_operand1->Replace(name, exp), _operand2->Replace(name, exp));
}

BooleanExp *OrExp::Copy() const {
    return new OrExp(_operand1->Copy(), _operand2->Copy());
}

NotExp::NotExp(BooleanExp *op) {
    _operand = op;
}

NotExp::~NotExp() {
}

bool NotExp::Evaluate(Context &aContext) {
    return !(_operand->Evaluate(aContext));
}

BooleanExp *NotExp::Replace(const char *name, BooleanExp &exp) {
    return new NotExp(_operand->Replace(name, exp));
}

BooleanExp *NotExp::Copy() const {
    return new NotExp(_operand->Copy());
}

Constant::Constant(bool b) :
    _b(b) {
}

bool Constant::Evaluate(Context &) {
    return _b;
}

BooleanExp *Constant::Replace(const char *, BooleanExp &) {
    return new Constant(false); // 简化
}

BooleanExp *Constant::Copy() const {
    return new Constant(false); // 简化
}
