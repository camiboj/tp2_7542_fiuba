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
        //Parcea un comando de tipo:
        //(nombre_del_script, prioridad, archivo_entrada,
        // archivo_salida, codigo_brainfuck)
        //
        //Y guarda los últimos cuatro parámetros.
        explicit CommandParcer(std::string& str);

        //crea un brainfuck a partir de los datos obtenidos en la creación.
        BfPriority* operator()();
};

#endif
