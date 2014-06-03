#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class Expression {
public:
    virtual int evaluate() = 0;
private:
    std::vector<Expression> node;
};

#endif