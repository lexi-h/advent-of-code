#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

const int NUM_STACKS = 9;

int main(){
    std::cout << "On the matter of rearranging stacks of boxes with cranes:\n";

    std::ifstream inputfile("input");

    if (inputfile.is_open()){
        std::string line = "";
        std::vector<std::string *> rows_of_boxes;


        //process input
        //process the stacks of boxes first
        while(getline(inputfile, line)){
            //get out once we're done setting up the arena
            if(line[1] == '1'){
                break;
            }

            rows_of_boxes.push_back(new std::string(line));
        }

        //set up the stacks of boxes
        std::vector< std::stack<char> > stacks(NUM_STACKS);
        //process each row of input
        for(int i = rows_of_boxes.size() - 1; i >= 0; --i){
            std::cout << *rows_of_boxes[i] << std::endl;

            for(int j = 0; j < NUM_STACKS; ++j){
                char target = rows_of_boxes[i]->at(4 * j + 1);
                //only add the character if it's not empty
                if(target != ' '){
                    stacks[j].push(target);
                }
            }
        }
        

        //delete contents of rows_of_boxes
        for(int i = 0; i < rows_of_boxes.size(); ++i){
            delete rows_of_boxes[i];
        }

        //debug to ensure stacks work
        for(int i = 0; i < NUM_STACKS; ++i){
            std::cout << "stack " << i;
            std::cout << " size: " << stacks[i].size() << " top: " << stacks[i].top();
            std::cout << std::endl;
        }


        //process stack manipulation instructions
        while(getline(inputfile, line)){
        }

        inputfile.close();
    }
    else{
        std::cout << "file cannot be opened\n";
    }


    return 0;
}
