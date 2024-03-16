#include <iostream>
#include <string>
#include <fstream>

class file_opener
{
private:
    std::string msg;
    std::fstream file;
public:
    file_opener(std::string path);
    std::string read_file();
};
