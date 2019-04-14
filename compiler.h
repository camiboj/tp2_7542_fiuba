#ifndef COMPILER_H_
#define COMPILER_H_
#include <stack> 
#include <string>

class Compiler {
    private:
    std::string code;
    std::stack<char> my_stack;

    public:
    explicit Compiler(std::string& str);

    ~Compiler();
    
    bool start();
};

#endif
