#ifndef COMPILER_H_
#define COMPILER_H_
#include <string>

class Compiler {
    private:
    std::string code;

    public:
    //Recibe un código brainfuck
    explicit Compiler(std::string& str);

    ~Compiler();
    //Parcea el cógigo brainfuck y verifica el correcto uso
    //de los corcetes ('[' y ']')
    bool start();
};

#endif
