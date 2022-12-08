#include <iostream>
#include <fstream>
#include <string>

char find_misplaced_item(const std::string rucksack);
int calculate_value_of_char(const char item);

char find_misplaced_item(const std::string rucksack){
    //find problem item
    for(int i = 0; i < rucksack.size()/2; ++i){
        //grab an item from the first half
        for(int j = 0; j < rucksack.size()/2; ++j){
            //compare it to every item in the second half
            if(rucksack[i] == rucksack[rucksack.size()/2+j]){
                //we found the misplaced item
                return rucksack[i];
            }
        }
    }

    //we didn't find any duplicate characters (this should never happen)
    return '-';

}

int calculate_value_of_char(char item){
    //'a' is 97, 97-96 = 1
    //this solves lowercase letters
    item -= ('a' - 1);

    //uppercase letters will be negative at this point
    //'A' is 65, 65-96 = -31, 'A' should be valued as 27
    //-31 + 58 = 27
    if (item < 0){
        item += 58;
    }

    return int(item);
}

int main(){
    std::cout << "Hello, world!" << std::endl;

    std::ifstream inputfile;
    inputfile.open("input");

    std::string rucksack = "";
    int running_total = 0;

    if(inputfile.is_open()){
        while (getline(inputfile, rucksack)){
            char misplaced_item = find_misplaced_item(rucksack);
            int value_of_item = calculate_value_of_char(misplaced_item);
            running_total += value_of_item;
        }
    }

    std::cout << "Answer: " << running_total << std::endl;

    inputfile.close();
    return 0;
}
