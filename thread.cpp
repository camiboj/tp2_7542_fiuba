#include "thread.h"
/*
   [1]
   Ejemplo de como ejecutar una funcion/functor en
   un hilo separado en C++
  
   Esta vez, en vez de usar composicion usaremos 
   herencia.
   Para ello crearemos una objeto Thread que 
   ejecutara un metodo virtual en su  propio hilo 
   definido por las clases hijas que hereden de 
   Thread
  
   Cuando el objeto functor encapsula dentro de él
   el concepto de hilo se dice que el objeto es un
   "objeto activo".
  
   Compilar con 
   g++ -std=c++11 -pedantic -Wall                \
     -o 03_is_prime_parallel_by_inheritance.exe  \
     03_is_prime_parallel_by_inheritance.cpp     \
     -pthread
  
*/


Thread::Thread () {}

void Thread::start() {
    this->thread = std::thread( &Thread::run, this);
}
            /* [2] Lanzamos el thread que correra 
               siempre la misma funcion (Thread::run)
               
               Como Thread::run es un **metodo** 
               sin parametros y std::thread espera
               a una **funcion** podemos ver a 
               Thread::run como una funcion que 
               recibe como primer argumento al 
               objeto this (tal como en los TDA de C!)
              
               std::thread soporta correr una 
               funcion con argumentos con la llamada:
                  std::thread( funcion, arg1, arg2, ...)
              
               Por lo tanto
                    std::thread( metodo, this )
               es equivalante a correr el metodo 
               sin argumentos en un thread.
              
               Por ser polimorfico el metodo 
               Thread::run de cada objeto ejecutara 
               un codigo particular en el thread.
              
               Objetos distintos podran correr en 
               sus propios threads con esta unica 
               implementacion de Thread mientras
               hereden de Thread y creen sus propias 
               versiones del metodo run.
            */
            

void Thread::join() {
   this->thread.join();
}

        /* [3] Virtual puro para forzar una
           definicion en las clases hijas
        */

 

        /* [4] Destructor virtual: sSiempre hacerlo 
           virtual si pensamos en usar herencia.
        */ 
 Thread::~Thread() {} 
                             
                             

        /* [5] No tiene sentido copiar hilos, asi 
           que forzamos a que no se puedan copiar.
        */

        
        /* [6] Pero si tiene sentido que un hilo 
           pueda moverse asi que implementamos su 
           constructor y operador asigancion por 
           movimiento
        */
Thread::Thread(Thread&& other) {
            /*
               [7] Explicitamente decimos: 
                    "move el hilo other.thread 
                    hacia this->thread pero no 
                    copies"
            */
this->thread = std::move(other.thread);
}


//Thread& operator=(Thread&& other) {
 //           this->thread = std::move(other.thread);
 //           return *this;
//}
