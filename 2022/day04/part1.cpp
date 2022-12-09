#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool is_encapsulated(int lowerbound0, int upperbound0, int lowerbound1, int upperbound1);
std::vector<int> parse_elf_duties(const std::string elf_duties);

bool is_encapsulated(int lowerbound0, int upperbound0, int lowerbound1, int upperbound1){
    //test if elf0 encapsulates elf1
    if(lowerbound0 <= lowerbound1){
        if(upperbound0 >= upperbound1){
            //yes, elf0 encapsulates elf1
            return true;
        }
    }

    //test if elf1 encapsulates elf0
    if(lowerbound1 <= lowerbound0){
        if(upperbound1 >= upperbound0){
            //yes, elf1 encapsulates elf0
            return true;
        }
    }

    //no encapsulation
    return false;
}

std::vector<int> parse_elf_duties(const std::string elf_duties){
    std::vector<int> result = {};

    int first_hyphen = elf_duties.find('-');
    int comma = elf_duties.find(',');
    int last_hyphen = elf_duties.rfind('-');

    int first_number = std::stoi(elf_duties.substr(0, first_hyphen));
    int second_number = std::stoi(elf_duties.substr(first_hyphen + 1, comma - first_hyphen + 1));
    int third_number = std::stoi(elf_duties.substr(comma + 1, last_hyphen - comma + 1));
    int fourth_number = std::stoi(elf_duties.substr(last_hyphen + 1)); //don't need to specify length

    result.push_back(first_number);
    result.push_back(second_number);
    result.push_back(third_number);
    result.push_back(fourth_number);

    return result;
}

int main(){
    std::cout << "On the matter of the division of labour between elves for camp cleanup:\n";

    std::ifstream inputfile("input");
    std::string elfduties = "";

    int running_total = 0;

    if(inputfile.is_open()){
        while(getline(inputfile, elfduties)){
            std::vector<int> elf_assignments = parse_elf_duties(elfduties);
            bool encapsulation_check = is_encapsulated(elf_assignments[0], 
                                            elf_assignments[1], 
                                            elf_assignments[2], 
                                            elf_assignments[3]);

            running_total += encapsulation_check;


        }
        inputfile.close();
    }
    else{
        std::cout << "unable to open file\n";
    }

    std::cout << "Number of elves encapsulated: " << running_total << std::endl;


    return 0;
}
