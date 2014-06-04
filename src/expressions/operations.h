#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "expressions.h"

// This saves so much code
// I'm so sorry
#define OPERATION(name, op) \
                        class name : public Operation { \
                        public: \
                            name (Expression *a, Expression *b) : Operation(a, b) {} \
                            int evaluate() {return LOperand->evaluate() op ROperand->evaluate();} \
                        };

// Used to check what the expression is the the parser
const std::string operations[] = {
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

/* I'm not sure how I thought this was a good idea
 * Email me at jacobhegna@gmail.com when this is on
 * either stackoverflow or r/shittyprogramming
 * Ninja edit: confirmed was sober
 */
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