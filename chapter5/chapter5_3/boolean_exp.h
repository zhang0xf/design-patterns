#ifndef BOOLEAN_EXP_H
#define BOOLEAN_EXP_H

class VariableExp;

// 类(Context)定义从变量到布尔值的一个映射
class Context {
public:
    bool LookUp(const char *) const;
    void Assign(VariableExp *, bool);
};

// (BooleanExp)为所有定义一个布尔表达式的类定义了一个接口.
class BooleanExp {
public:
    BooleanExp();
    virtual ~BooleanExp();

    virtual bool Evaluate(Context &) = 0;
    virtual BooleanExp *Replace(const char *, BooleanExp &) = 0;
    virtual BooleanExp *Copy() const = 0;
};

// 一个(VariableExp)表示一个有名变量
class VariableExp : public BooleanExp {
public:
    VariableExp(const char *);
    virtual ~VariableExp();

    virtual bool Evaluate(Context &);
    virtual BooleanExp *Replace(const char *, BooleanExp &);
    virtual BooleanExp *Copy() const;

private:
    char *_name;
};

// 两个布尔表达式与操作得到的表达式
class AndExp : public BooleanExp {
public:
    AndExp(BooleanExp *, BooleanExp *);
    virtual ~AndExp();

    virtual bool Evaluate(Context &);
    virtual BooleanExp *Replace(const char *, BooleanExp &);
    virtual BooleanExp *Copy() const;

private:
    BooleanExp *_operand1;
    BooleanExp *_operand2;
};

// 两个布尔表达式或操作得到的表达式
class OrExp : public BooleanExp {
public:
    OrExp(BooleanExp *, BooleanExp *);
    virtual ~OrExp();

    virtual bool Evaluate(Context &);
    virtual BooleanExp *Replace(const char *, BooleanExp &);
    virtual BooleanExp *Copy() const;

private:
    BooleanExp *_operand1;
    BooleanExp *_operand2;
};

// 布尔表达式非操作得到的表达式
class NotExp : public BooleanExp {
public:
    NotExp(BooleanExp *);
    virtual ~NotExp();

    virtual bool Evaluate(Context &);
    virtual BooleanExp *Replace(const char *, BooleanExp &);
    virtual BooleanExp *Copy() const;

private:
    BooleanExp *_operand;
};

class Constant : public BooleanExp {
public:
    Constant(bool);

    virtual bool Evaluate(Context &);
    virtual BooleanExp *Replace(const char *, BooleanExp &);
    virtual BooleanExp *Copy() const;

private:
    bool _b;
};

#endif