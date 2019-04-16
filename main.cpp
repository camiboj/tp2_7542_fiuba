#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue> 
#include "interprete.h"
#include "producer.h"

#define COMAND_ERROR 2



int main(int argc, char * const argv[]) {
    //Modo modo;
    
    std::string modo1("interprete");
    std::string modo2("thread-pool");
    /*
    for (int i = 1; i<10; i++) {
        std::cout << "diff hello_world_out_0" << i << "_.txt hello_world_out_0" << i << ".txt\n";
    }
    for (int i = 10; i<60; i++) {
        std::cout << "diff hello_world_out_" << i << "_.txt hello_world_out_" << i << ".txt\n";
    }*/ 
    if ( modo1.compare(0, strlen(argv[1]), argv[1]) == 0 ) {  
        //verifico la # de comandos
        if ( argc != 3 ) { 
            return COMAND_ERROR;
        }
        Interprete modo(argv[2]);
        return modo.execute();         
    } else if ( modo2.compare(0, strlen(argv[1]), argv[1]) == 0 ) {
        int thread = (int) *argv[2] - 48;
        Producer modo(thread);
        return modo.execute();
    }
    
    return 1;
}
