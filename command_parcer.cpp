#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>
#include "command_parcer.h"
#include <iostream>

CommandParcer::CommandParcer(std::string& line) {
    std::vector<std::string> container;
	std::string buff{""};
	int i = 0;
    while ( line[i] ) { 
		if(line[i] == ',' && line[i+1] == ' ' && buff != "") { 
            container.push_back(buff); buff = ""; 
            i++;
        } else {
             buff+=line[i];
        }
        i++;
	}
	if (buff != "") container.push_back(buff);

    this->in_filename = container[2];
    this->out_filename = container[3];

    container[0][0] = ' ';
    
    this->code = container[4];
    this->priority= std::atoi(container[1].c_str());
}


BfPriority* CommandParcer::operator()() {
    return new BfPriority(this->code, this->in_filename,\
                         this->out_filename, this->priority);
}
