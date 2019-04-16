#ifndef INTERPRETE_H_
#define INTERPRETE_H_
#include <string>
#include "modo.h"

class Interprete: public Modo {
    private:
        std::string code;
        std::string filename;
        bool readCode();

    public:
        //recibe el nombre de un archivo que contiene un código brainfuck
        explicit Interprete(std::string _filename);
        ~Interprete();
        //intérprete de brainfuck ​ 
        //que deberá ejecutar scripts del mencionado lenguaje.
        int execute();
};

#endif
