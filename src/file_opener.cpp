#include "file_opener.hpp"

file_opener::file_opener(std::string path){
    file.open(path);
}

std::string file_opener::read_file(){
    std::string line;
    if(file.is_open()){
        while (getline(file, line))
        {
            msg += line;
            msg += " ";
        }
        return msg;
        
    }else{
        return "Unable to open file\n";
    }
}