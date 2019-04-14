#include <iostream>
 #include <string>
#include "executor.h"
#define MAX_LEN_CODE_MEMORY 20000
#define MAX_LEN_DATA_MEMORY 200


Excecutor::Excecutor(std::string& str, std::istream* _in, std::ostream* _out) {
    //std::cout << "EL CODIGO DEL BF DEBERIA SER: " << '\n';
    //std::cout << str << '\n';
    this->data_memory.resize(MAX_LEN_DATA_MEMORY);
    this->code_memory = str;   
    std::fill(this->data_memory.begin(), this->data_memory.end(), 0);  
    
    this->data_pos = 0;
    this->code_pos = 0;

    this->in = _in;
    this->out = _out;
    //std::cout << "EL CODIGO DEL BF ES: " << '\n';
    //std::cout << this->code_memory << '\n';
}

//<
void Excecutor::back() {
    this->data_pos--;
}

//>
void Excecutor::next() {
    this->data_pos++;
}

//+
void Excecutor::plus() {
    this->data_memory[this->data_pos]++;
}

//-
void Excecutor::less() {
    this->data_memory[this->data_pos]--;
}

//.
void Excecutor::write() {
    *this->out << this->data_memory[this->data_pos];
    //std::cout << "Imprimo " << '\n';
}

//,
void Excecutor::read() {
    this->data_memory[this->data_pos] = this->in->get();
    if (this->data_memory[this->data_pos] == -1) {
        this->data_memory[this->data_pos] = 0;
    }
}

//[
void Excecutor::loopStart() {
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
void Excecutor::loopEnd() {
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
void Excecutor::print_code() {
    std::cout << this->code_memory << '\n';
}

void Excecutor::start() {
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
                this->write();
                break;
            case ',':
                this->read();
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

Excecutor::~Excecutor() {
    //do nothing
}

