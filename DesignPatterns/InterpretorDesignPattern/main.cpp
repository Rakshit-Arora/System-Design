#include <iostream>
#include <memory>
#include "context.h"
#include "addNonTerminalExpression.h"
#include "multiplyNonTerminalExpression.h"
#include "binaryNonTerminalExpression.h"
#include "numberTerminalExpression.h"
using namespace std;

int main() {
    cout << "##### Interpreter Design Pattern #####" << endl;

    // Context
    Context context;
    context.setVariable("a", 12);
    context.setVariable("b", 5);
    context.setVariable("c", 3);
    context.setVariable("d", 9);
    cout << "Context: "; 
    context.Print();

    // Expression: a + b
    unique_ptr<AbstractExpression> expression1 =
        make_unique<AddNonTerminalExpression>(
            new NumberTerminalExpressoin("a"),
            new NumberTerminalExpressoin("b")
        );
    cout << "Expression: (a+b) = " << expression1->interpret(context) << endl; // Output: 17

    // Expression: a * b
    unique_ptr<AbstractExpression> expression2 =
        make_unique<MultiplyNonTerminalExpression>(
            new NumberTerminalExpressoin("a"),
            new NumberTerminalExpressoin("b")
        );
    cout << "Expression: (a*b) = " << expression2->interpret(context) << endl; // Output: 60

    // Complex Expression: (a + b) * c
    unique_ptr<AbstractExpression> expression3 =
        make_unique<MultiplyNonTerminalExpression>(
            new AddNonTerminalExpression(
                new NumberTerminalExpressoin("a"),
                new NumberTerminalExpressoin("b")
            ),
            new NumberTerminalExpressoin("c")
        );
    cout << "Expression: ((a+b)*c) = " << expression3->interpret(context) << endl; // Output: 51

    // Expression: ((a*b) + (c*d))
    unique_ptr<AbstractExpression> expression4 =
        make_unique<BinaryNonTerminalExpression>(
            new BinaryNonTerminalExpression(
                new NumberTerminalExpressoin("a"),
                new NumberTerminalExpressoin("b"),
                '*'),
            new BinaryNonTerminalExpression(
                new NumberTerminalExpressoin("c"),
                new NumberTerminalExpressoin("d"),
                '*'),
            '+');
    cout << "Expression: ((a*b) + (c*d)) = " << expression4->interpret(context) << endl;

    return 0;
}
