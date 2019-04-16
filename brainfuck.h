#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_
#include <string>
#include "compiler.h"
#include "executor.h"

class Brainfuck {
    private:
        Compiler compiler;
        Executor executor;

    public:
        Brainfuck(std::string& str, std::string& _in, std::string& _out);
        explicit Brainfuck(std::string& str);
        ~Brainfuck();
        bool start();
};

#endif
