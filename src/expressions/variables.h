#ifndef VARIABLE_H_
#define VARIABLE_H_

template<class T>
class Variable : public Expression<T> {
public:
    Variable() {}
    ~Variable() {}
    T evaluate() {return value;}
    void clean() {}
    virtual void compile() = 0;
protected:
    T value;
};

class Float : public Variable<float> {
public:
    Float() {}
    Float(float p) {value = p;}
    Float(std::string p) {value = std::stof(p);}
    void compile() {}
    static bool is_float(std::string s) {
        return !s.empty() && std::find_if(s.begin(),
            s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
    }
};

class Int : public Variable<int> {
public:
    Int() {}
    Int(int p) {value=p;}
    Int(std::string p) {value=std::stoi(p);}
    int evaluate() {return value;}
    void compile() {}
    static bool is_int(std::string s) {
        return !s.empty() && std::find_if(s.begin(),
            s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
    }
};

#endif