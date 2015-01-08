#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <array>

#include "expressions.h"

// Used to check what the expression is the the parser
const std::array<std::string, 10> operations = {
    "+",
    "-",
    "/",
    "*",
    "%",
    "&",
    "|",
    "^",
    "<<",
    ">>"
};

class Operation : public Expression<int> {
public:
    Operation() {}
    Operation(Expression<int> *a, Expression<int> *b) {
        LOperand = a;
        ROperand = b;
    }
    void compile() {

    }
    void clean() {
        LOperand->clean();
        ROperand->clean();
        delete LOperand;
        delete ROperand;
    }
protected:
    Expression<int> *LOperand,
                  *ROperand;
};

// This saves so much code
// I'm so sorry
#define OPERATION(name, op)                                                   \
    class name : public Operation {                                        \
    public:                                                                   \
        name (Expression<int> *a, Expression<int> *b) : Operation(a, b) {}     \
        int evaluate() {return LOperand->evaluate() op ROperand->evaluate();}   \
    };

OPERATION(Add,      +)
OPERATION(Sub,      -)
OPERATION(Div,      /)
OPERATION(Mult,     *)
OPERATION(Mod,      %)
OPERATION(Bit_AND,  &)
OPERATION(Bit_OR,   |)
OPERATION(Bit_XOR,  ^)
OPERATION(Bit_SHL, <<)
OPERATION(Bit_SHR, >>)

#endif