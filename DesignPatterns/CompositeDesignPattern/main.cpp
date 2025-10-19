#include <iostream>
#include "header/arithmeticExpression.h"
#include "header/number.h"
#include "header/expression.h"
#include "header/operationType.h"
using namespace std;

int main() {
    cout << "Composite Design Pattern Example: Arithmetic Expression Evaluation" << endl;

    ArithmeticExpression* two = new Number(2);
    ArithmeticExpression* one = new Number(1);
    ArithmeticExpression* seven = new Number(7);

    ArithmeticExpression* additionExpression = new Expression(one, seven, OperationType::ADD); // (1 + 7)
    ArithmeticExpression* finalExpression = new Expression(two, additionExpression, OperationType::MULTIPLY); // 2 * (1 + 7)

    cout<< "Final Result: " << finalExpression->evaluate() << endl;
}