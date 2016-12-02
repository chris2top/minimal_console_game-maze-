#include <fstream>
#include <vector>
#include <string>
#include "../include/file_utility.h"

std::vector<std::string> file_content(std::string filename)
{
    std::vector<std::string> contents {};
    std::string line;
    std::ifstream myfile(filename.c_str());

    if(!myfile.good()) {
        perror(filename.c_str());
        return contents;
    }

    while(getline(myfile, line)) {
        contents.push_back(line);
    }

    return contents;

}
