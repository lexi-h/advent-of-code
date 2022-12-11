#include <iostream>
#include <fstream>
#include <vector>
#include "tree_files.h"

void process_instruction(std::string line, TreeNode * & root, TreeNode * & current_location, std::ifstream & inputfile);
void process_cd(const std::string target_location, TreeNode * & root, TreeNode * & current_location);
void process_ls(TreeNode * & current_location, std::ifstream & inputfile);

void process_instruction(std::string line, TreeNode * & root, TreeNode * & current_location, std::ifstream & inputfile){
    if(line[0] != '$'){
        //something has gone wrong
        std::cout << "something is bad, " << line << " is not a command\n";
        return;
    }

    //now it must be an instruction
    std::string command = line.substr(2, 2);

    if(command == "cd"){
        std::string target_location = line.substr(line.find_last_of(' ') + 1);
        process_cd(target_location, root, current_location);
        return;
    }
    if(command == "ls"){
        process_ls(current_location, inputfile);
        return;
    }
}

void process_cd(const std::string target_location, TreeNode * & root, TreeNode * & current_location){
    //check if it is root
    if(target_location == "/"){
        current_location = root;
        std::cout << "changed directory to /\n";
        return;
    }
    if(target_location == ".."){
        current_location = current_location->get_parent();
        std::cout << "changed directory to ..\n";
        return;
    }

    //check through all children
    for(int i = 0; i < (current_location->get_children()).size(); ++i){
        //see if name matches
        TreeNode * current_child = (current_location->get_children())[i];
        if(current_child->is_dir() && target_location == current_child->get_name()){
            current_location = current_child;
            std::cout << "changed directory to " << current_location->get_name() << std::endl;
            return;
        }
    }

    //i don't think we need to cd into a directory if it hasn't been ls'd yet
    std::cout << "something has gone wrong. could not find directory named " << target_location << std::endl;
    return;
}

void process_ls(TreeNode * & current_location, std::ifstream & inputfile){
    while(inputfile.good()){
        //we are done once we reach the next command
        if(inputfile.peek() == '$') return;

        std::string line = "";
        //get the line
        getline(inputfile, line);
        if(line == "") return;

        int space_location = line.find(' ');
        std::string firsthalf = line.substr(0, space_location);
        std::string secondhalf = line.substr(space_location + 1);

        //create a dir
        if(firsthalf == "dir"){
            current_location->add_child(new TreeNode(secondhalf, false, 0, current_location));
            std::cout << "added directory " << secondhalf << " to " << current_location->get_name() << std::endl;
        }
        //create a file
        else{
            int filesize = std::stoi(firsthalf);
            current_location->add_child(new TreeNode(secondhalf, true, filesize, current_location));
            std::cout << "added file " << secondhalf << " to " << current_location->get_name() << std::endl;
        }
    }
}

int main(){
    std::cout << "On the matter of traversing the elves' file system and locating files to destroy:\n";

    std::ifstream inputfile("shortinput");

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

    TreeNode * root = new TreeNode("/", false, 0, NULL);
    TreeNode * current_position = root;

    while(inputfile.good()){
        std::string line = "";
        getline(inputfile, line);
        if(line == "") break;
        process_instruction(line, root, current_position, inputfile);
    }


    std::cout << "complete.\n";

    std::cout << "size of / " << root->get_children().size() << std::endl;

    inputfile.close();
    return 0;


}

