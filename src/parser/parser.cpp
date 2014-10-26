#include "parser.h"

bool in_exp = false;

// c++11 strtok returns a vector
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

// strtok_v but keeps the token
std::vector<std::string> strtok_v_k(std::string o_param, std::string tok) {
    std::vector<std::string> vtok;
    char *duptok = strdup(tok.c_str());
    char *ctok = strtok(strdup(o_param.c_str()), duptok);
    while(ctok != nullptr) {
        vtok.push_back(ctok);
        vtok.push_back(tok);
        ctok = strtok(nullptr, duptok);
    }
    vtok.pop_back();
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
        if(std::find(operations.begin(), operations.end(), expr.at(i)) != operations.end()) {
            Expression *a, *b;
            if(i == expr.size() - 2) {
                in_exp = true;
                a = new Int(parse(expr, i-1)->evaluate());
                in_exp = true;
                b = new Int(parse(expr, i+1)->evaluate());
            } else {
                in_exp = true;
                a = new Int(parse(expr, i-1)->evaluate());
                in_exp = true;
                b = new Int(parse(expr, i+2)->evaluate());
            }
            // TODO: fix order of ops
            if(expr.at(i) == "+")      { return new Add(a, b); }
            else if(expr.at(i) == "-") { return new Sub(a, b); }
            else if(expr.at(i) == "*") { return new Mult(a, b); }
            else if(expr.at(i) == "/") { return new Div(a, b); }
            else if(expr.at(i) == "%") { return new Mod(a, b); }
            else if(expr.at(i) == "&") { return new Bit_AND(a, b); }
            else if(expr.at(i) == "|") { return new Bit_OR(a, b); }
            else if(expr.at(i) == "^") { return new Bit_XOR(a, b); }
            else if(expr.at(i) == "<<") { return new Bit_SHL(a, b); }
            else if(expr.at(i) == ">>") { return new Bit_SHR(a, b); }
        } else if(expr.at(i) == "print") {
            if(expr.size() == 2) {
                in_exp = true;
            } else {
                in_exp = false;
            }
            Print *p = new Print(parse(expr, i+1));
            return p;
        } else if(expr.at(i) == "let") {
            if(expr.size() == 4) {
                in_exp = true;
            } else {
                in_exp = false;
            }
            if(expr.at(i+2) == "=") {
                Let *l = new Let(expr.at(i+1), parse(expr, i+3));
                return l;
            }
        } else if(in_exp) {
            in_exp = false;
            if(variables.find(expr.at(i)) != variables.end()) {
                return new Get(expr.at(i));
            } else if(Int::is_int(expr.at(i))) {
                return new Int(expr.at(i));
            }
        } else {
            for(std::string op : operations) {
                in_exp = true;
                int loc = 0;
                if((loc = expr.at(i).find(op)) != std::string::npos) {
                    std::vector<std::string> split = strtok_v_k(expr.at(i), op);
                    return parse(split, 0);
                }
            }
        }
        return parse(expr, i+1);
    }
    return nullptr;
}

void Parser::start(bool compile) {
    std::vector<std::string> expr;
    AST ast;
    for(std::string &line : file) {
        std::transform(line.begin(), line.end(), line.begin(), tolower);
        expr = strtok_v(line, " ");
        in_exp = false; // reset every line
        ast.add_node(this->parse(expr));
        expr.clear();
    }
    (compile) ? ast.compile() : ast.interpret();
}