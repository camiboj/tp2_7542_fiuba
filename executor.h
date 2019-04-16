#ifndef EXCECUTOR_H_
#define EXCECUTOR_H_
#include <string>
#include <vector>
#include <fstream>


class Executor {
    private:
        int data_pos;
        int code_pos;
        std::vector<char> data_memory;
        std::string code_memory;
        std::string in;
        std::string out;

        //Mueve el puntero de datos a la izquierda
        void back();
    
        //Mueve el puntero de datos a la derecha
        void next();

        //Incrementa el dato apuntado por el puntero de datos en 1 unidad
        void plus();

        //Decrementa el dato apuntado por el puntero de datos en 1 unidad
        void less();

        //Imprime el caracter apuntado por el puntero de datos
        void write(std::ostream* file);

        //Lee un dato de la entrada y lo coloca en la posición 
        //apuntada por el puntero de datos
        void read(std::istream* file); 
    
        //Si el dato apuntado por el puntero de datos es igual a cero, 
        //salta hasta la instrucción siguiente al siguiente ​ ']'
        void loopStart();

        //Vuelve al ​ '[' ​ anterior
        void loopEnd();

    public:
        void print_code();
        explicit Executor(std::string& str);
        Executor(std::string& str, std::string& _in, std::string& _out);
        ~Executor();
        //void setCode(std::string str);
        void start();
};

#endif
