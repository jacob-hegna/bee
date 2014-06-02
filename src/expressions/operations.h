#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "expressions.h"

class Operation : public Expression {
public:
    Operation() {}
    Operation(Expression *a, Expression *b) {
        LOperand = a;
        ROperand = b;
    }
protected:
    Expression *LOperand, 
               *ROperand;
};

class Add : public Operation {
public:
    Add(Expression *a, Expression *b) : Operation(a, b) {}
    int evaluate() {return LOperand->evaluate() + ROperand->evaluate();}
};

class Sub : public Operation {
public:
    Sub(Expression *a, Expression *b) : Operation(a, b) {}
    int evaluate() {return LOperand->evaluate() - ROperand->evaluate();}
};

class Div : public Operation {
public:
    Div(Expression *a, Expression *b) : Operation(a, b) {}
    int evaluate() {return LOperand->evaluate() / ROperand->evaluate();}
};

class Mult : public Operation {
public:
    Mult(Expression *a, Expression *b) : Operation(a, b) {}
    int evaluate() {return LOperand->evaluate() * ROperand->evaluate();}
};

class Mod : public Operation {
public:
    Mod(Expression *a, Expression *b) : Operation(a, b) {}
    int evaluate() {return LOperand->evaluate() % ROperand->evaluate();}
};

#endif