#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

const int NUM_STACKS = 9;

std::vector<int> parse_instruction(const std::string & input);
void process_instruction(std::vector< std::stack<char> > & stacks, const std::vector<int> & instruction);

//instruction format: "move X from Y to Z"
std::vector<int> parse_instruction(const std::string & input){
    int index_of_from = input.find("from");
    int index_of_to = input.find("to");
    
    std::vector<int> result;

    //the first number, X
    result.push_back(std::stoi(input.substr(5, index_of_from - 6)));

    //second number, Y. technically this should always be 1 digit number but i am futureproofing
    result.push_back(std::stoi(input.substr(index_of_from + 5, index_of_to - index_of_from - 6)));

    //third number, Z
    result.push_back(std::stoi(input.substr(index_of_to + 3)));

    return result;
}


//instruction format: move X crates from stack Y to stack Z
void process_instruction(std::vector< std::stack<char> > & stacks, const std::vector<int> & instruction){
    int num_crates_to_move = instruction[0];
    int origin_stack = instruction[1] - 1;
    int destination_stack = instruction[2] - 1;
    //move crates
    for(int i = 0; i < num_crates_to_move; ++i){
        //from stack Y
        char crate = stacks[origin_stack].top();
        stacks[origin_stack].pop();
        //to stack Z
        stacks[destination_stack].push(crate);

        //debug print
        /*
        std::cout << "moved " << crate << " from stack " << origin_stack << " to stack " 
                    << destination_stack << std::endl;
        */
    }

    return;
}

int main(){
    std::cout << "On the matter of rearranging stacks of crates with cranes:\n";

    std::ifstream inputfile("input");

    if (inputfile.is_open()){
        std::string line = "";
        std::vector<std::string *> rows_of_crates;


        //process input
        //process the stacks of crates first
        while(getline(inputfile, line)){
            //get out once we're done setting up the arena
            if(line[1] == '1'){
                break;
            }

            rows_of_crates.push_back(new std::string(line));
        }

        //set up the stacks of crates
        std::vector< std::stack<char> > stacks(NUM_STACKS);
        //process each row of input
        for(int i = rows_of_crates.size() - 1; i >= 0; --i){
            std::cout << *rows_of_crates[i] << std::endl;

            for(int j = 0; j < NUM_STACKS; ++j){
                char target = rows_of_crates[i]->at(4 * j + 1);
                //only add the character if it's not empty
                if(target != ' '){
                    stacks[j].push(target);
                }
            }
        }
        

        //delete contents of rows_of_crates
        for(int i = 0; i < rows_of_crates.size(); ++i){
            delete rows_of_crates[i];
        }

        //debug to ensure stacks work
        for(int i = 0; i < NUM_STACKS; ++i){
            std::cout << "stack " << i;
            std::cout << " size: " << stacks[i].size() << " top: " << stacks[i].top();
            std::cout << std::endl;
        }


        //process stack manipulation instructions
        while(getline(inputfile, line)){
            if(line[0] == 'm'){
                //std::cout << "processing instruction " << line << std::endl;
                std::vector<int> instruction_numbers = parse_instruction(line);
                process_instruction(stacks, instruction_numbers);
            }
        }

        inputfile.close();
        //debug to ensure stacks work
        std::cout << "FINAL STATE OF STACKS\n";
        for(int i = 0; i < NUM_STACKS; ++i){
            std::cout << "stack " << i;
            std::cout << " size: " << stacks[i].size() << " top: " << stacks[i].top();
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "file cannot be opened\n";
    }


    return 0;
}
