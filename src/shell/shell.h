#ifndef SHELL_H_
#define SHELL_H_

#include <iostream>
#include <string>

#include "../parser/parser.h"

class Shell {
public:
    Shell();
    ~Shell();

    void start();
};

#endif