#include "parser.h"

std::vector<std::string> strtok_v(std::string o_param, std::string tok) {
    std::vector<std::string> vtok;
    char *duptok = strdup(tok.c_str());
    char *ctok = strtok(strdup(o_param.c_str()), duptok);
    while(ctok != nullptr) {
        vtok.push_back(ctok);
        ctok = strtok(nullptr, duptok);
    }
    free(duptok);
    return vtok;
}

Parser::Parser(std::string filename) {
    std::ifstream temp_file(filename);
    if(!temp_file.is_open()) {
        std::cout << "Failed to open '" << filename << "'!" << std::endl;
        exit(-1);
    } else {
        std::string line;
        while(std::getline(temp_file, line)) {
            file.push_back(line);
        }
    }
}

Parser::~Parser() {

}

Expression* Parser::parse(std::vector<std::string> expr, int i) {
    if(i <= expr.size()) {
        if(expr.at(i) == "+") {
            return new Add(new Int(expr.at(i-1)), new Int(expr.at(i+1)));
        } else if(expr.at(i) == "-") {
            return new Sub(new Int(expr.at(i-1)), new Int(expr.at(i+1)));
        } else if(expr.at(i) == "*") {
            return new Mult(new Int(expr.at(i-1)), new Int(expr.at(i+1)));
        } else if(expr.at(i) == "/") {
            return new Div(new Int(expr.at(i-1)), new Int(expr.at(i+1)));
        } else if(expr.at(i) == "%") {
            return new Mod(new Int(expr.at(i-1)), new Int(expr.at(i+1)));
        } else if(expr.at(i) == "print") {
            Print p(this->parse(expr, i+1));
            p.evaluate();
            return nullptr;
        }
        return this->parse(expr, i+1);
    }
}

void Parser::start() {
    for(std::string &line : file) {
        std::transform(line.begin(), line.end(), line.begin(), tolower);
        std::vector<std::string> expr = strtok_v(line, " ");
        this->parse(expr, 0);
        expr.clear();
    }
}