#include <iostream>
#include <cstring>
#include <string>
#include <array>
#include <unistd.h>

#include "parser/parser.h"
#include "globals.h"

extern int opterr;
extern char* optarg;

int main(int argc, char *argv[]) {
    std::string usage = "Usage: %s -oi <filename> | -h\n";
    if(argc < 2) {
        printf(usage.c_str(), argv[0]);
    } else {
        opterr = 0;
        int c;
        while((c = getopt(argc, argv, "o:i:h")) != -1) {
            if(c == 'o' || c == 'i') {
                std::string optarg_std(optarg);
                Parser parser(optarg_std);
                parser.start(c == 'o');
            } else if(c == 'h') {
                printf(usage.c_str(), argv[0]);
                printf(" -o   compile basic\n");
                printf(" -i   interpret basic\n");
                printf(" -h   print this message\n");
            }
        }
    }
    return 0;
}

// globals.h definitions
std::map<std::string, int> variables;
