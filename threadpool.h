#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <string>
#include "modo.h"

class ThreadPool: public Modo {
    private:
    int n;

    public:
    ThreadPool(int cant);
    ~ThreadPool();
    int execute();
};

#endif