#include <iostream>
#include <fstream>
#include <vector>
#include "tree_files.h"

int main(){
    std::cout << "On the matter of traversing the elves' file system and locating files to destroy:\n";

    std::ifstream inputfile("input");

    if(!inputfile.is_open()){
        std::cout << "could not open file :(\n";
        return 1;
    }

    /*
     * TreeNode t("hello from a tree");

    std::cout << t.get_name() << std::endl;

    t.set_name("hello from an oak tree!");

    std::cout << t.get_name() << std::endl;
    */






    inputfile.close();
    return 0;


}

