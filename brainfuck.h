#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_
#include <string>
#include "compiler.h"
#include "executor.h"

class Brainfuck {
    private:
    Compiler compiler;
    Excecutor excecutor;

    public:
    explicit Brainfuck(std::string& str, std::istream* _in, std::ostream* _out);
    ~Brainfuck();
    void print_code();

    bool start();
};


#endif