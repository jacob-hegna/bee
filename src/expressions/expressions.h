#ifndef EXPRESSION_H_
#define EXPRESSION_H_

template<class T>
class Expression {
public:
    virtual T evaluate() = 0;
    virtual void compile() = 0;
    virtual void clean() = 0;
};

#endif