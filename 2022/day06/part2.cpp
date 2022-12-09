#include <iostream>
#include <fstream>
#include <string>

const int MSG_SIZE = 14;

void update_lists(char buffer [MSG_SIZE], bool dupelist [MSG_SIZE], int index, char new_char);
bool is_unique(bool dupelist [MSG_SIZE]);

void update_lists(char buffer [MSG_SIZE], bool dupelist [MSG_SIZE], int index, char new_char){
    buffer[index % MSG_SIZE] = '-';
    dupelist[index % MSG_SIZE] = false;

    for(int i = 0; i < MSG_SIZE; ++i){
        //check for dupes in the whole list
        if(new_char == buffer[i]){
            //uh oh we have a dupe
            dupelist[i] = true;
        }
    }

    buffer[index % MSG_SIZE] = new_char;
}

bool is_unique(bool dupelist [MSG_SIZE]){
    for(int i = 0; i < MSG_SIZE; ++i){
        //if any dupe is found, return false
        if (dupelist[i]){
            return false;
        }
    }
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

    char buffer [MSG_SIZE] = {};
    bool dupelist [MSG_SIZE] = {};

    int winning_index = -1;
    for(int i = 0; i < line.size(); ++i){
        update_lists(buffer, dupelist, i, line[i]);
        if (i > MSG_SIZE - 2){
            if(is_unique(dupelist)){
                winning_index = i + 1;
                break;
            }
        }
    }

    std::cout << "winning index: " << winning_index << std::endl;

    return 0;
}
