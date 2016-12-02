#include <iostream>
#include <vector>
#include <string>
#include "field_generator.h"

std::vector<std::string> create_field(int size){
    std::vector<std::string> field;
    std::string line{};
    //pair<int, int>  starting_point = (rand()%size, rand()%size);
    for(int i=0; i<size;i++){ 
        //if(i==starting_point) line += "P";
        line+="*";
    }
    for(int j=0; j<size;j++) field.push_back(line);
    return field;
}

