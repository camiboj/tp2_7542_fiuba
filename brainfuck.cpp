#include <iostream>
#include "brainfuck.h"
#define MAX_LEN_CODE_MEMORY 20000
#define MAX_LEN_DATA_MEMORY 200



Brainfuck::Brainfuck() {
    this->data_memory.resize(MAX_LEN_DATA_MEMORY);
    std::fill(this->data_memory.begin(), this->data_memory.end(), 0);  
    this->data_pos = 0;

    this->code_pos = 0;
}

//<
void Brainfuck::back() {
    this->data_pos--;
}

//>
void Brainfuck::next() {
    this->data_pos++;
}

//+
void Brainfuck::plus() {
    this->data_memory[this->data_pos]++;
}

//-
void Brainfuck::less() {
    this->data_memory[this->data_pos]--;
}

//.
void Brainfuck::out() {
    std::cout << this->data_memory[this->data_pos];

}

//,
void Brainfuck::in() {
    this->data_memory[this->data_pos] = std::cin.get();
    if (this->data_memory[this->data_pos] == -1) {
        this->data_memory[this->data_pos] = 0;
    }
}

//[
void Brainfuck::loopStart() {
    size_t count = 0;
    bool keep_looking = true;
    if ( !this->data_memory[this->data_pos] ) {
        while ( keep_looking ) {
            this->code_pos++;
            
            if ((this->code_pos < 90) & (this->data_pos > -4)) {
                /*
                cout << "- ACA   --\n";
                cout << "POS: " << this->code_pos; 
                cout << "\n";
                cout << "INSTRUC: " << this->code_memory[this->code_pos];
                cout << "\n";
                cout << "count: " << count;
                cout << "\n";
                */
            }
            
            if (this->code_memory.compare(this->code_pos, 1,"[") == 0) {
                count++;
            }
            if (this->code_memory.compare(this->code_pos, 1,"]") == 0) {
                if (count == 0) {
                    keep_looking = false;
                }
                else {
                    count--;
                }
            }

        }    
        //this->code_pos++;
    }     
}

//]
void Brainfuck::loopEnd() {
    size_t count = 0;
    bool keep_looking = true;
    
    while (keep_looking) {
        this->code_pos--;
        if (this->code_memory.compare(this->code_pos, 1,"]") == 0) {
            count++;
            /*
            cout << "--   ACA   --\n";
            cout << "POS: " << this->code_pos; 
            cout << "\n";
            cout << "INSTRUC: " << this->code_memory[this->code_pos];
            cout << "\n";
            
            cout << "count: " << count;
            cout << "\n";
        */
        }
        if (this->code_memory.compare(this->code_pos, 1,"[") == 0) {
            
            if (count == 0) {
                keep_looking = false;
            }
            else {
                count--;
            }
        }
    }
    this->code_pos--;

}

void Brainfuck::ex() {
    while ( this->code_memory[this->code_pos] ) {
        /*
        if ((this->code_pos < 90) & (this->data_pos >= 0)) {
        cout << "--   ITERO   -- \n";
        cout << "" << this->code_memory[this->code_pos];
        cout << "\n";
        }   else break;
        */
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
                this->out();
                break;
            case ',':
                this->in();
                break;
            case '[':
                /*
                cout << "pos instuccion actual: " << this->code_pos; 
                cout << "\n";
                cout << "pos dato ctual: " << this->data_pos;
                cout << "\n";
                cout << "dato actual: " << this->data_memory[this->data_pos];
                cout << "\n";
                */
                this->loopStart();

                break;
            case ']':
                /*
                cout << "pos instuccion actual: " << this->code_pos; 
                cout << "\n";
                cout << "pos dato ctual: " << this->data_pos;
                cout << "\n";
                cout << "dato actual: " << this->data_memory[this->data_pos];
                cout << "\n";
                */
                this-> loopEnd();
                break;
        }
        this->code_pos++;
    /*
        if ((this->code_pos < 90) & (this->data_pos > -4)) {
            cout << "prox_instruc: " << this->code_pos; 
            cout << "\n";
            cout << "prox_instruc: " << this->code_memory[this->code_pos];
            cout << "\n";
            cout << "DATA_POS: " << this->data_pos; 
            cout << "\n";
            cout << "DATA: " << this->data_memory[this->data_pos];
            cout << "\n";
        }
    */
    }
    /*
    for (std::vector<char>::const_iterator i = this->data_memory.begin(); i != this->data_memory.end(); ++i)
    std::cout << *i << ' ';
    cout << "\n";
    */
}

Brainfuck::~Brainfuck() {
    //delete this->data_memory;
    //delete this->code_memory;
}


void Brainfuck::setCode(std::string str) {
    //cout << str;
    //cout << "\n";
    this->code_memory.append(str);
}