#include "boolean_exp.h"

// 定义布尔表达式: (true and x) or (y and (not x))

// 案例说明了解释器的一个重要的特点: 可以使用多种操作来“解释”一个句子.
// (Evaluate)解释一个程序或表达式并返回一个简单的结果.(Replace)也可被视为一个解释器.

int main() {
    BooleanExp *expression;
    Context context;

    VariableExp *x = new VariableExp("x");
    VariableExp *y = new VariableExp("y");

    expression = new OrExp(new AndExp(new Constant(true), x), new AndExp(y, new NotExp(x)));

    context.Assign(x, false);
    context.Assign(y, true);

    bool result = expression->Evaluate(context);

    // 适用一个新表达式替换变量y

    VariableExp *z = new VariableExp("z");
    NotExp not_z(z);

    BooleanExp *replacement = expression->Replace("y", not_z);

    context.Assign(z, true);

    result = replacement->Evaluate(context);

    // use result
    (void)result;

    return 0;
}