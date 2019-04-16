#include "bf_priority.h"
#include <iostream>
#include <string>

BfPriority::BfPriority(std::string& str,std::string& _in,\
                     std::string& _out, int _i): 
    bf(str, _in, _out), priority(_i) {}

bool BfPriority::start(){
    return this->bf.start();
}
/*
bool BfPriority::compare(BfPriority* other) {
    return other->compare(this->i)
}

bool BfPriority::compare(int j) {
    return j < this->i;
}
*/
bool BfPriority::operator<(BfPriority& other) {
    std::cout << this->priority << "<" << other.priority;
    bool aux = this->priority < other.priority;
    if (aux) {
        std::cout << " TRUE \n";
    } else {
        std::cout << " FALSE \n";
    }
    return aux;
}

int BfPriority::getPriority() const {
    return this->priority;
}

void BfPriority::print_priority() {
    std::cout << "Mi prioridad es: " << this->priority << "\n";
}

BfPriority::~BfPriority() {}
