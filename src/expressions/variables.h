#ifndef VARIABLE_H_
#define VARIABLE_H_

class Int : public Expression {
public:
    Int() {}
    Int(int p) {value=p;}
    Int(std::string p) {value=std::stoi(p);}
    int evaluate() {return value;}
private:
    int value;
};

#endif