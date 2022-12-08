#include <iostream>
#include <fstream>
#include <string>

char find_misplaced_item(const std::string rucksack);
int calculate_value_of_char(const char item);
std::string find_common_items(const std::string rucksack0, const std::string rucksack1, const bool expect_one_item);

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

std::string find_common_items(const std::string rucksack0, const std::string rucksack1, const bool expect_one_item = false){
    std::string common_items = "";
    //for every character in rucksack0...
    for(int i = 0; i < rucksack0.length(); ++i){
        //compare it to every character in rucksack1
        for(int j = 0; j < rucksack1.length(); ++j){
            //if a match is found, add it to the list
            if(rucksack0[i] == rucksack1[j]){
                common_items.push_back(rucksack0[i]);

                //will return a single character string if we expect one item
                if (expect_one_item) return common_items;
            }
        }
    }

    //we went through all the possibilities
    //time to return with our list
    return common_items;

}

int main(){
    std::cout << "Hello, world!" << std::endl;

    std::ifstream inputfile;
    inputfile.open("input");

    std::string inputline = "";
    std::string rucksacks [3] = {"", "", ""};
    int running_total = 0;

    if(inputfile.is_open()){
        int counter = 0;
        while (getline(inputfile, inputline)){
            rucksacks[counter] = inputline;
            if(counter >= 2){
                std::string first_common_items = find_common_items(rucksacks[0], rucksacks[1]);
                //badge should always be length 1
                std::string badge = find_common_items(first_common_items, rucksacks[2], true);
                int value_of_item = calculate_value_of_char(badge[0]);
                running_total += value_of_item;
                counter = -1;
            }
            ++counter;
        }
    }

    std::cout << "Answer: " << running_total << std::endl;

    inputfile.close();
    return 0;
}
