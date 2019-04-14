#include "bfconsumer.h"

BfConsumer::BfConsumer(bool& _result, std::mutex& _m, std::queue<Brainfuck*>& _produced_bfs, bool& _done, bool& _notified,  std::condition_variable& _cond_var) : 
    result(_result), m(_m), produced_bfs(_produced_bfs), done(_done), notified(_notified), cond_var(_cond_var){
}
        
void BfConsumer::run() {
    std::unique_lock<std::mutex> lock(this->m);
    Brainfuck* bf;
    int i = 0;
    while (!this->done) {
        while (!this->notified) {  // loop to avoid spurious wakeups
            this->cond_var.wait(lock);
        }
        i++;
        std::cout << "ejecuto thread: " << i << '\n';    
        notified = false;
        //std::cout << "consuming " << produced_nums.front() << '\n';
        bf = this->produced_bfs.front();
        this->produced_bfs.pop();
        // UNLOCK    
        this->result = bf->start();  
        delete bf;
    }       
}
