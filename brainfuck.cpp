#include <iostream>
#include <string>
#include "brainfuck.h"


Brainfuck::Brainfuck(std::string& str): 
    compiler(str), 
    executor(str) {
        //std::cout << "RECIEN CREADO: " << '\n';
        //excecutor.print_code();
    }

Brainfuck::Brainfuck(std::string& str, std::string& _in, std::string& _out): 
    compiler(str), 
    executor(str, _in, _out) {
        //std::cout << "RECIEN CREADO: " << '\n';
        //excecutor.print_code();
    }

bool Brainfuck::start(){
    bool is_all_ok = true;
    //std::cout << "ANTES DE COMPILAR: " << '\n';
    //excecutor.print_code();
    is_all_ok = compiler.start();
    if (! is_all_ok) return false;
    //std::cout << "HAGO START: " << '\n';
    executor.start();
    //excecutor.print_code();
    return true;
}
/*
void Brainfuck::print_code() {
    excecutor.print_code();
}
*/
Brainfuck::~Brainfuck() {}
