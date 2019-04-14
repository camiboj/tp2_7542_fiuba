#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue> 
#include "interprete.h"
#include "threadpool.h"

#define COMAND_ERROR 2



int main(int argc, char * const argv[]) {
    //Modo modo;
    
    std::string modo1("interprete");
    std::string modo2("thread-pool");


    if ( modo1.compare(0, strlen(argv[1]), argv[1]) == 0 ) {  
        //verifico la # de comandos
        if ( argc != 3 ) { 
            return COMAND_ERROR;
        }
        Interprete modo(argv[2]);
        return modo.execute();         
    } 

    
    
    else if ( modo2.compare(0, strlen(argv[1]), argv[1]) == 0) {
        int thread = (int) *argv[2] - 48;
        ThreadPool modo(thread);
        return modo.execute();

    }
    
    return 1;

    //return modo.execute();
}
