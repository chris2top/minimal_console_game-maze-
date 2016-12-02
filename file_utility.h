#ifndef FILE_UTILITY_H_INCLUDED
#define FILE_UTILITY_H_INCLUDED

#include <vector>
#include <string>

std::vector<std::string> file_content(std::string filename);
void write_file(std::vector<std::string> text, std::string filename);
#endif // FILE_UTILITY_H_INCLUDED
