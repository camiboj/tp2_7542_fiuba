#include <iostream>
#include "brainfuck.h"

using namespace std;

Brainfuck() {
    data;
    code;
}

//<
void previous() {
    data--;
}

//>
void next() {
    data++;
}

//+
void plus() {
    (*data)++;
}

//-
void less() {
    (*data)--;
}

//.
void out() {
    std::cout << *data;
}

//,
void in() {
    std::cin >> *data;
}

//[
void loop_start() {
    int bal = 1;
    if (*d == '\0') {
        do {
            code++;
            if      (*code == '[') bal++;
            else if (*code == ']') bal--;
        } while ( bal != 0 );
    }
}

//]
void loop_end() {
    int bal = 0;
    do {
    if (*code == '[') bal++;
    else if (*code == ']') bal--;
    code--;
    } while ( bal != 0 );
}

void evaluate() {
    while (*code) {
        switch (*code) {
            case '<':
                previous();
                break;
            case '>':
                next();
                break;
            case '+':
                plus();
                break;
            case '-':
                less();
                break;
            case '.':
                out();
                break;
            case ',':
                in();
                break;
            case '[':
                loop_start();
                break;
            case ']':
                loop_end();
                break;
        }
    code++;
    }
}
