#include <iostream>
 #include <string>
#include "executor.h"
#define MAX_LEN_CODE_MEMORY 20000
#define MAX_LEN_DATA_MEMORY 200

//&std::cin, &std::cout
Executor::Executor(std::string& str) {
    this->in = std::string("");
    this->out = std::string("");
    this->data_memory.resize(MAX_LEN_DATA_MEMORY);
    this->code_memory = str;   
    std::fill(this->data_memory.begin(), this->data_memory.end(), 0);  
    
    this->data_pos = 0;
    this->code_pos = 0;

    //this->in = std::cin;
    //this->out = std::cout;
}

Executor::Executor(std::string& str, std::string& _in, std::string& _out):\
     in(_in), out(_out) {
    this->data_memory.resize(MAX_LEN_DATA_MEMORY);
    this->code_memory = str;   
    std::fill(this->data_memory.begin(), this->data_memory.end(), 0);  
    
    this->data_pos = 0;
    this->code_pos = 0;
}

//<
void Executor::back() {
    this->data_pos--;
}

//>
void Executor::next() {
    this->data_pos++;
}

//+
void Executor::plus() {
    this->data_memory[this->data_pos]++;
}

//-
void Executor::less() {
    this->data_memory[this->data_pos]--;
}

//.
void Executor::write(std::ostream* file) {
    //std::cout << "Deberia escribir:";
    //(&std::cout)->put(this->data_memory[this->data_pos]);
    //std::cout << '\n';
    *file << this->data_memory[this->data_pos];
    //(&std::cout)->put(this->data_memory[this->data_pos]);
}

//,
void Executor::read(std::istream* file) {
    this->data_memory[this->data_pos] = file->get();
    if (this->data_memory[this->data_pos] == -1) {
        this->data_memory[this->data_pos] = 0;
    }
}

//[
void Executor::loopStart() {
    size_t count = 0;
    bool keep_looking = true;
    if ( this->data_memory[this->data_pos] ) return;
    while ( keep_looking ) {
        this->code_pos++;               
        if (this->code_memory.compare(this->code_pos, 1,"[") == 0) {
            count++;
        }
        if (this->code_memory.compare(this->code_pos, 1,"]") == 0) {
            if (count == 0) {
                keep_looking = false;
            } else {
                count--;
            }
        }
    }    
}     


//]
void Executor::loopEnd() {
    size_t count = 0;
    bool keep_looking = true;
    
    while (keep_looking) {
        this->code_pos--;
        if (this->code_memory.compare(this->code_pos, 1,"]") == 0) {
            count++;
        }
        if (this->code_memory.compare(this->code_pos, 1,"[") == 0) {
            if (count == 0) {
                keep_looking = false;
            } else {
                count--;
            }
        }
    }
    this->code_pos--;
}
void Executor::print_code() {
    std::cout << this->code_memory << '\n';
}

void Executor::start() {
    std::istream* in_file = &std::cin;
    std::ostream* out_file = &std::cout;
    std::ofstream _out_file;
    std::ifstream _in_file;
    
    if (this->in.compare("") != 0 && 
        this->out.compare("") != 0) {
        _in_file.open(this->in);
        _out_file.open(this->out, 
                            std::ofstream::out | std::ofstream::trunc);
        in_file = &_in_file;
        out_file = &_out_file;
    }
    
    //std::cout << "EL CODIGO DEL BF ES: " << '\n';
    //std::cout << this->code_memory << '\n';
    while ( this->code_memory[this->code_pos] ) {
        switch ( this->code_memory[this->code_pos] ) {
            case '<':
                this->back();
                break;
            case '>':
                this->next();
                break;
            case '+':
                this->plus();
                break;
            case '-':
                this->less();
                break;
            case '.':
                this->write(out_file);
                break;
            case ',':
                this->read(in_file);
                break;
            case '[':
                this->loopStart();
                break;
            case ']':
                this-> loopEnd();
                break;
        }
        this->code_pos++;
    }
}

Executor::~Executor() {
    //do nothing
}

