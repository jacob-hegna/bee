#include "shell.h"

Shell::Shell() {

}

Shell::~Shell() {

}

void Shell::start() {
    std::cout << "Welcome to the BASIC++ shell!"                                  << std::endl
              << "The shell will evaluate expressions, however will not simulate" << std::endl
              << "a full BASIC++ environment."                                    << std::endl
              << "Input 'quit', 'exit', or 'q' to quit."                          << std::endl;
    std::string input;
    while(true) {
        std::cout << ">>";
        getline(std::cin, input);
        if(input == ":quit" || input == ":exit" || input == ":q") {
            break;
        }
    }
    std::cout << "BASIC++ shell successfully terminated." << std::endl;
}