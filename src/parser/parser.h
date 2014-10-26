#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

#include "../expressions/expressions.h"
#include "../expressions/operations.h"
#include "../expressions/variables.h"
#include "../expressions/stdfunctions.h"

std::vector<std::string> strtok_v(std::string o_param, std::string tok);

class Parser {
public:
    Parser(std::string);
    ~Parser();

    static Expression* parse(std::vector<std::string> expr, int i = 0);
    void start(bool compile);

private:
    std::vector<std::string> file;
};

class AST {
public:
    AST() {}
    ~AST() {
        for(Expression* expr : root) {
            expr->clean();
        }
    }

    void add_node(Expression *expr) {
        root.push_back(expr);
    }
    void compile() {
        for(Expression* expr : root) {
            expr->compile();
        }
    }
    void interpret() {
        for(Expression* expr : root) {
            expr->compile();
        }
    }
private:
    std::vector<Expression*> root;
};

#endif