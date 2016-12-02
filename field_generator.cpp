#include <iostream>
#include <vector>
#include <string>
#include "field_generator.h"

std::vector<std::string> create_field(int size){
    std::vector<std::string> field;
    std::string line{};
    for(int i=0; i<size;i++) line+="*";
    for(int j=0; j<size;j++) field.push_back(line);
    return field;
}

std::vector<std::pair<int,int>> create_maze(std::vector<std::string> level, std::string filename){
    std::vector<std::pair<int,int>> maze;
    int x=0,y=0;
    for(auto c:level){
        x++;
        for(auto d:c){
            y++;
            y%=3+1;
            maze.push_back(std::make_pair(x, d));
            std::cout << x << y << std::endl;
        } 
    }
    return maze;
}

//beide funktionen ersetzen durch einen grossen vektor!!!
