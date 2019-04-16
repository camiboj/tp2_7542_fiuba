#ifndef BFPRIORITY_H_
#define BFPRIORITY_H_
#include <string>
#include "brainfuck.h"

class BfPriority {
    private:
        Brainfuck bf;
        int priority;
    
    public:
        explicit BfPriority(std::string& str,std::string& _in,\
                         std::string& _out, int _i);
        ~BfPriority();
        bool start();
        //bool compare(BfPriority* other);
        bool operator<(BfPriority& other);
        void print_priority();
        int getPriority() const;
        //bool compare(int j);
};

#endif
