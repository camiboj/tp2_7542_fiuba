#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Brainfuck {
    private:

    int data_pos;
    int code_pos;
    std::vector<char> data_memory;
    string code_memory;

    public:
    
    Brainfuck();
    ~Brainfuck();

    //Mueve el puntero de datos a la izquierda
    void back();
    
    //Mueve el puntero de datos a la derecha
    void next();
    
    //Incrementa el dato apuntado por el puntero de datos en 1 unidad
    void plus();
    
    //Decrementa el dato apuntado por el puntero de datos en 1 unidad
    void less();

    //Imprime el caracter apuntado por el puntero de datos
    void out();

    //Lee un dato de la entrada y lo coloca en la posición 
    //apuntada por el puntero de datos
    void in(); 
    
    //Si el dato apuntado por el puntero de datos es igual a cero, 
    //salta hasta la instrucción siguiente al siguiente ​ ']'
    void loopStart();

    //Vuelve al ​ '[' ​ anterior
    void loopEnd();

    void setCode(std::string str);

    void ex();
};

#endif
