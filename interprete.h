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
        Interprete(std::string _filename);
        ~Interprete();
        int execute();
};





#endif