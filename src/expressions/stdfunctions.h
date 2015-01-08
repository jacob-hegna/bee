#ifndef STDFUNCTIONS_H_
#define STDFUNCTIONS_H_

#include <iostream>
#include <string>
#include <algorithm>

#include "expressions.h"
#include "../globals.h"

template<class T>
class STD_Function : public Expression<T> {
    virtual void clean() = 0;
    virtual void compile() = 0;
};

template<class T>
class Let : public STD_Function<T> {
public:
    Let(std::string name, Expression<T> *value ) {
        this->name = name;
        this->value = value->evaluate();
        variables[name] = this->value;
    }
    T evaluate() {
        return 0;
    }
    void compile() {
        std::cout << "mvi a, " << value << std::endl;
    }
    void clean() {}
private:
    std::string name;
    T value;
};

class Get : public STD_Function<int> {
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

template<class T>
class Print : public STD_Function<T> {
public:
    Print(Expression<T> *a) {value=a;}
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
    Expression<T> *value;
};

#endif