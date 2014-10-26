#ifndef VARIABLE_H_
#define VARIABLE_H_

class Int : public Expression {
public:
    Int() {}
    Int(int p) {value=p;}
    Int(std::string p) {value=std::stoi(p);}
    int evaluate() {return value;}
    void compile() {}
    void clean() {}
    static bool is_int(std::string s)
    {
        return !s.empty() && std::find_if(s.begin(),
            s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
    }
private:
    int value;
};

#endif