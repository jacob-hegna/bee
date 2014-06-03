#ifndef STDFUNCTIONS_H_
#define STDFUNCTIONS_H_

#include <iostream>
#include <string>
#include <algorithm>

#include "expressions.h"
#include "../globals.h"

class Let : public Expression {
public:
    Let(std::string name, Expression *value ) {
        variables[name] = value->evaluate();
    }
    int evaluate() {
        return 0;
    }
};

class Get : public Expression {
public:
    Get(std::string name) {
        this->name = name;
    }
    int evaluate() {
        return variables[name];
    }
private:
    std::string name;
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