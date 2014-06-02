#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <vector>
#include <string>
#include <iostream>

class Expression {
public:
    virtual int evaluate() = 0;
private:
    std::vector<Expression> node;
};

class Print : public Expression {
public:
    Print(Expression *a) {value=a;}
    int evaluate() {
        std::cout << value->evaluate() << std::endl;
        return 0;
    }
private:
    Expression *value;
};

#endif