#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include "threadpool.h"
#include "bfconsumer.h"
#include "brainfuck.h"
#define HELL "[hello_world.bf]++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."
 
ThreadPool::ThreadPool(int cant): n(cant) {}

int ThreadPool::execute() {
    std::queue<Brainfuck*> produced_bfs;
    std::mutex m;
    std::condition_variable cond_var;
    bool done = false;
    bool notified = false;
    bool result = true;

    std::string code(HELL);
    Brainfuck bf(code, &std::cin, &std::cout);
    bf.start();

    BfConsumer consumer(result, m, produced_bfs, done, notified, cond_var);
    consumer.start();

    for (int i = 0; i < 5; ++i) { //while not eof getline
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(m); //es el mismo que pidio el de abajo
                                                //si el de abajo ya lo pidio=> recien en el wait lo deslockea
        std::cout << "\n\n"; //
        std::cout << "producing: " << i << '\n'; //
        
        std::string code("[hello_world.bf]++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
        Brainfuck* bf = new Brainfuck(code, &std::cin, &std::cout);
        produced_bfs.push(bf);   //mete i (primero un 0)
        //Brainfuck* bf1 = produced_bfs.front();
        //bf1->start();
        
        std::cout << "size: " << produced_bfs.size() << '\n';
        notified = true; //le digo que se cumple
        cond_var.notify_one(); //cond var es std::conditiona_variable => si hay alguien esperando se despierta.
    }   
 
    done = true; //YA hice todo de todo(por si no habia nadie esperando)
    cond_var.notify_one();

    //si algun thread guarda false en result deberia hacer aalgooo!!

//la idea es esperar a que se cumpla algo

    consumer.join();
    return 0;
}

ThreadPool::~ThreadPool(){}

