#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <string>
#include <vector>
#include "producer.h"
#include "consumer.h"
#include "command_parcer.h"


Producer::Producer(int cant): n(cant) {}

int Producer::execute() {
    std::priority_queue \
        <BfPriority*, std::vector<BfPriority*>, CompareBf> produced_bfs;
    std::mutex m;
    std::condition_variable cond_var;
    bool done = false;
    bool notified = false;
    bool result = true;
    int state = 0;

    std::vector<Thread*> threads;
    

    for (int i = 0; i < this->n; i++) {
        //std::cerr << "i es: " << i;
        Thread* consumer = new Consumer(result, m, produced_bfs, \
                                        done, notified, cond_var, i);
        consumer->start();
        threads.push_back(consumer); 
    }

    std::string line;
    while ( std::getline(std::cin, line, ')') ) {    
        if (std::cin.eof()) { 
            break;
        }
        std::unique_lock<std::mutex> lock(m);
        CommandParcer cp(line);
        BfPriority* bf = cp();
        produced_bfs.push(bf); 
        notified = true; //le digo que se cumple
        cond_var.notify_one(); 
        if (!result){
            state = 1;
            break;
        }
    }
    done = true; //YA hice todo de todo(por si no habia nadie esperando)
    notified = true;
    cond_var.notify_all();

    for (int i = 0; i < this->n; ++i) {
        threads[i]->join();
        delete threads[i];
    }
    //consumer.join();
    return state;
}



Producer::~Producer(){}

