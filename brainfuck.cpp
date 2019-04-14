#include <iostream>
#include "brainfuck.h"

Brainfuck::Brainfuck(std::string& str, std::istream* _in, std::ostream* _out): 
    compiler(str), 
    excecutor(str, _in, _out) {
        std::cout << "RECIEN CREADO: " << '\n';
        excecutor.print_code();
    }

bool Brainfuck::start(){
    bool is_all_ok = true;
    std::cout << "ANTES DE COMPILAR: " << '\n';
    excecutor.print_code();
    is_all_ok = compiler.start();
    if (! is_all_ok) return false;
    std::cout << "HAGO START: " << '\n';
    excecutor.start();
    return true;
}

void Brainfuck::print_code() {
    excecutor.print_code();
}

Brainfuck::~Brainfuck() {
    
}
