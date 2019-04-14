#ifndef BFCONSUMER_H_
#define BFCONSUMER_H_
#include <string>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include "thread.h"
#include "brainfuck.h"

class BfConsumer : public Thread { 
    private:
    bool& result;
    std::mutex& m;
    std::queue<Brainfuck*>& produced_bfs;
    bool& done;
    bool& notified;
    std::condition_variable& cond_var;
    
    public:
        BfConsumer(bool& _result, std::mutex& _m, std::queue<Brainfuck* >& _produced_bfs, bool& _done, bool& _notified,  std::condition_variable& _cond_var);
        virtual void run() override;
};

#endif