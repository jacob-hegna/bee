#include <iostream>
#include <cstring>
#include <string>
#include <array>

#include "shell/shell.h"
#include "parser/parser.h"
#include "globals.h"

int main(int argc, char *argv[]) {
    std::string usage = "Usage: basic++ [-h | --help] [filename]";
    if(argc < 2) {
        Shell shell;
        shell.start();
    } else {
        if(argv[1] == "-h" || argv[1] == "--help") {
            std::cout << usage << std::endl;
        } else {
            Parser parser(argv[1]);
            parser.start();
        }
    }
}

// globals.h definitions
std::map<std::string, int> variables;
