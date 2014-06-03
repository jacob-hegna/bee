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

    static Expression* parse(std::vector<std::string>, int);
    void start();

private:
    std::vector<std::string> file;
};

#endif