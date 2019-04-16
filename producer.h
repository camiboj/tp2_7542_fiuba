#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <string>
#include "modo.h"
#include "bf_priority.h"

class Producer: public Modo {
    private:
        int n;
        //bool compare(BfPriority* a, BfPriority* b);

    public:
        explicit Producer(int cant);
        ~Producer();
        int execute();
};

#endif
