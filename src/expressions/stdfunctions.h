#ifndef STDFUNCTIONS_H_
#define STDFUNCTIONS_H_

#include <iostream>
#include <string>
#include <algorithm>

#include "expressions.h"
#include "../globals.h"

class STD_Function : public Expression {
    virtual void clean() = 0;
    virtual void compile() = 0;
};

class Let : public STD_Function {
public:
    Let(std::string name, Expression *value ) {
        this->name = name;
        this->value = value->evaluate();
        variables[name] = this->value;
    }
    int evaluate() {
        return 0;
    }
    void compile() {
        std::cout << "mvi a, " << value << std::endl;
    }
    void clean() {}
private:
    std::string name;
    int value;
};

class Get : public STD_Function {
public:
    Get(std::string name) {
        this->name = name;
    }
    int evaluate() {
        return variables[name];
    }
    void compile() {

    }
    void clean() {}
private:
    std::string name;
};

class Print : public STD_Function {
public:
    Print(Expression *a) {value=a;}
    int evaluate() {
        std::cout << value->evaluate() << std::endl;
        return 0;
    }
    void compile() {
        
    }
    void clean() {
        value->clean();
        delete value;
    }
private:
    Expression *value;
};

#endif