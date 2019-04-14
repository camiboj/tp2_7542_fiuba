#ifndef THREAD_H_
#define THREAD_H_
#include <thread>

class Thread {
    private:
        std::thread thread;
 
    public:
        Thread ();
        void start();
        void join();
        virtual void run() = 0; 
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;
        virtual ~Thread();
        Thread(Thread&& other);
        Thread& operator=(Thread&& other);
};

#endif