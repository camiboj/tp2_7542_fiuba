#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include "brainfuck.h"

using namespace std;

int main(int argc, char * const argv[]) {
    std::string modo1 ("interprete");
    if ( modo1.compare(0, strlen(argv[1]), argv[1]) == 0 ) {
        if ( argc != 3 ) {
            return 2;
        }
        std::ifstream script;
        script.open(argv[2]);
        if( !script.good() ) {
            std::cout << script.rdstate();
            return 2;
        }
        //string aux;
        //string line;
        //while ( getline (script,line) ) {
        //    aux << line;
        //}
        //std::cout << "aca1\n"; 
        
        
        //script >> aux;
        
        std::stringstream buffer;
        buffer << script.rdbuf();
        string line = buffer.str();
        
        //std::cout << "aca2\n"; 
        Brainfuck bf;
        bf.setCode(line); 
        //std::cout << "aca3\n"; 
        bf.ex();
        //std::cout << "aca4\n"; 
        script.close();
        //std::cout << "aca5\n";

        //std::cout << "\n";  
    }
    
    return 0;
}