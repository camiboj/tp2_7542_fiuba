#ifndef BFCONSUMER_H_
#define BFCONSUMER_H_
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <vector>
#include "thread.h"
#include "bf_priority.h"
//#include "compare_bf.h"

class CompareBf {
    public:
        bool operator()(const BfPriority* a, const BfPriority* b) {
            return a->getPriority() < b->getPriority();
            //queria hacer a<b pero no funciona el operador
        }
};


class Consumer : public Thread { 
    private:
        bool& result; 
        std::mutex& m;
        std::priority_queue \
            <BfPriority*, std::vector<BfPriority*>,CompareBf> \
            &produced_bfs;
        bool& done;
        bool& notified;
        std::condition_variable& cond_var;
        int i;
    
    public:
        //Recibe una cola bloqueante 
        //para ejecutar siempre el bf de mayor prioridad
        Consumer(bool& _result, std::mutex& _m, std::priority_queue \
                    <BfPriority*, std::vector <BfPriority*>, CompareBf> \
                    & _produced_bfs, \
                     bool& _done, bool& _notified,  \
                     std::condition_variable& _cond_var, int _i);
        
        //Espera la notificación de que hay brainfucks para ejecutar
        //y los ejecuta.
        virtual void run() override;
};



#endif
