#ifndef BFPRIORITY_H_
#define BFPRIORITY_H_
#include <string>
#include "brainfuck.h"


//Clase brainfuck con prioridad
class BfPriority {
    private:
        Brainfuck bf;
        int priority;
    
    public:
        //crea un brainfuck y le asigna su prioridad
        explicit BfPriority(std::string& str,std::string& _in,\
                         std::string& _out, int _i);
        ~BfPriority();

        //inicia el bf
        bool start();

        //sobre carga el operador less than
        bool operator<(BfPriority& other);
    
        int getPriority() const;
};

#endif
