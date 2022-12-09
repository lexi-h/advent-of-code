#include <iostream>
#include <fstream>
#include <string>

bool is_unique(int buffer [4]);

bool is_unique(int buffer [4]){
    if(buffer[0] == buffer[1] ||
            buffer[0] == buffer[2] ||
            buffer[0] == buffer[3] ||
            buffer[1] == buffer[2] ||
            buffer[1] == buffer[3] ||
            buffer[2] == buffer[3]) return false;
    return true;
}

int main(){
    std::cout << "Concerning the malfunctioning communication device supplied to me by the elves:\n";

    std::ifstream inputfile("input");

    if(!inputfile.is_open()){
        std::cout << "could not open file :(\n";
    }

    std::string line = "";
    getline(inputfile, line);
    //std::cout << line;

    int buffer [4] = {};

    int winning_index = -1;
    for(int i = 0; i < line.size(); ++i){
        buffer[i%4] = line[i];
        if (i > 2){
            if(is_unique(buffer)){
                winning_index = i + 1;
                break;
            }
        }
    }

    std::cout << "winning index: " << winning_index << std::endl;

    return 0;
}
