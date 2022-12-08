#include <iostream>
#include <fstream>
#include <string>

char evaluate_rps_match(const std::string p1throw, const std::string p2throw);
int points_for_own_throw(const std::string mythrow);
int points_for_match_outcome(const char outcome);
int get_rps_score(const std::string p1throw, const std::string p2throw);

char evaluate_rps_match(const std::string p1throw, const std::string p2throw){
    //from p2 pov
    if (p1throw == p2throw){
        return 'T';
    }

    //p2 wins
    if ( (p1throw == "rock" && p2throw == "paper") ||
            (p1throw == "paper" && p2throw == "scissors") ||
            (p1throw == "scissors" && p2throw == "rock")){
        return 'W';
    }

    //if it's not a tie or a win, it's a loss
    return 'L';
}

int points_for_own_throw(const std::string mythrow){
    int points = 1;
    if (mythrow == "paper") points = 2;
    if (mythrow == "scissors") points = 3;

    return points;
}

int points_for_match_outcome(const char outcome){
    int points = 0;
    if (outcome == 'T') points = 3;
    if (outcome == 'W') points = 6;

    return points;
}

int get_rps_score(const std::string p1throw, const std::string p2throw){
    if (p1throw == "error" || p2throw == "error"){
        std::cout << "there was an error\n";
        return 0;
    }
    char match_outcome = evaluate_rps_match(p1throw, p2throw);
    int my_score = points_for_match_outcome(match_outcome) + points_for_own_throw(p2throw);

    return my_score;
}

int main(){
    std::cout << "Hello world!" << std::endl;

    std::ifstream inputfile("input");

    std::string inputdata;
    int my_total_points = 0;
    if (inputfile.is_open()){
        std::cout << "yay\n";
        while (inputfile.good()){
            std::getline(inputfile, inputdata);
            std::string p1throw = "";
            std::string p2throw = "";
            switch (inputdata[0]){
                case 'A': p1throw = "rock"; break;
                case 'B': p1throw = "paper"; break;
                case 'C': p1throw = "scissors"; break;
                default: p1throw = "error"; break;
            }
            switch (inputdata[2]){
                case 'X': p2throw = "rock"; break;
                case 'Y': p2throw = "paper"; break;
                case 'Z': p2throw = "scissors"; break;
                default: p2throw = "error"; break;
            }

            int points_this_match = get_rps_score(p1throw, p2throw);


            std::cout << inputdata << p1throw << p2throw << points_this_match << std::endl;
            my_total_points += points_this_match;
        }
    }

    inputfile.close();
    std::cout << "My total points: " << my_total_points << std::endl;
    std::cout << "ending program" << std::endl;




    return 0;
}
