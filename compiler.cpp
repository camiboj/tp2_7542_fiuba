#include <iostream>
#include <string>
#include "compiler.h"
#define ERROR_CODE 2
#define OK_CODE 0


Compiler::Compiler(std::string& str) {
    this->code = str;
}



Compiler::~Compiler() {
    //do nothing
}

bool Compiler::start() {
    char current = this->code[0]; 
    size_t pos = 0;
    
    while ( current ) {
        if ( current == '[' ) {
            this->my_stack.push(current);
        }
        if ( current == ']' ) {
            if (this->my_stack.empty()) {
                return false;
            }
            this->my_stack.pop();
        }
        pos ++;
        current = this->code[pos];
    }
    
    if ( !this->my_stack.empty() ) {
        return false;
    }
    return true;
}
