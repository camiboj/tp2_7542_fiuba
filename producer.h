#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <string>
#include "modo.h"
#include "bf_priority.h"

class Producer: public Modo {
    private:
        int n;

    public:
        explicit Producer(int cant);
        ~Producer();
        //Lee de entrada estandar los parámetros para la creación de branfucks
        //los agrega a una cola de prioridad bloqueante, para que los
        //n threads del pool (Consumidores) los ejecuten 
        //tomando siempre el más prioritario.
        int execute();
};

#endif
