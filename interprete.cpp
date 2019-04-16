#include <sstream>
#include <string>
#include "interprete.h"
#include "brainfuck.h"
    
Interprete::Interprete(std::string _filename) {
    this->filename = _filename;
}
 
bool Interprete::readCode() {
    //abro archivo
    std::ifstream script;
    script.open(this->filename);
    if ( !script.good() ) {
        return false;
    }
    //leo el archivo y guardo en "code"
    std::stringstream buffer;
    buffer << script.rdbuf();
    this->code = buffer.str();
    script.close();
    return true;
}


int Interprete::execute() {
    bool is_all_ok = true;
    is_all_ok = this->readCode();
    if (!is_all_ok) {
        return COMAND_ERROR;
    }

    Brainfuck bf(this->code);
    is_all_ok = bf.start();
    if (!is_all_ok) {
        return CODE_ERROR;
    }
    return OK;
}

Interprete::~Interprete() {}
