#include <vector>
#include "consumer.h"

Consumer::Consumer(bool& _result, std::mutex& _m, std::priority_queue \
            <BfPriority*, std::vector<BfPriority*>, CompareBf> \
            & _produced_bfs, \
            bool& _done, bool& _notified,  \
            std::condition_variable& _cond_var, int _i) : 
    result(_result), \
    m(_m), \
    produced_bfs(_produced_bfs), \
    done(_done), notified(_notified), \
    cond_var(_cond_var), i(_i) \
    {}
        
void Consumer::run() {
    std::unique_lock<std::mutex> lock(this->m);
    BfPriority* bf;
    //int j = 0;
    while (true) {
        while (!this->notified) {  // loop to avoid spurious wakeups
            if (this->done) break; //to evoid neverending wait
            this->cond_var.wait(lock);
        }

        if (this->done && produced_bfs.empty()) break; //same shit

        bf = this->produced_bfs.top();
        this->produced_bfs.pop(); 
        
        //lock.unlock();  
        
        this->result = bf->start();
        delete bf;
        notified = false;
    }       
}
