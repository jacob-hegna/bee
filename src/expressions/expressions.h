#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class Expression {
public:
    virtual int evaluate() = 0;
    virtual void compile() = 0;
    virtual void clean() = 0;
};

#endif