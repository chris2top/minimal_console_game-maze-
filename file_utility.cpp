#include <fstream>
#include <vector>
#include <string>
#include "file_utility.h"

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


void write_file(std::vector<std::string> text, std::string filename){
    std::ofstream infile;
    infile.open(filename+".lvl");
    if(infile.fail()) perror(filename.c_str());
    for(auto t:text) infile << t << std::endl;
    infile.close();
}
