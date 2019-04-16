#ifndef COMMANPARCER_H_
#define COMMANPARCER_H_
#include <string>
#include "bf_priority.h"

class CommandParcer {
    private:
        std::string in_filename;
        std::string out_filename;
        std::string code;
        int priority;
    public:
        explicit CommandParcer(std::string& str);
        BfPriority* operator()();
};

#endif
