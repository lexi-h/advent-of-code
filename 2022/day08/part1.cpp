#include <iostream>
#include <fstream>
#include <vector>

void updatevisibilitymap(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible);
void checkfromwest(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible);
void checkfromeast(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible);
void checkfromnorth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible);
void checkfromsouth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible);
int countvisibletrees(const std::vector < std::vector<bool> > & isvisible);

void updatevisibilitymap(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible){
    checkfromwest(treeheight, isvisible);
    checkfromeast(treeheight, isvisible);
    checkfromnorth(treeheight, isvisible);
    checkfromsouth(treeheight, isvisible);
}

void checkfromwest(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible){
    for(int i = 0; i < treeheight.size(); ++i){
        int biggesttreesofar = -1;
        for(int j = 0; j < treeheight[i].size(); ++j){
            if(treeheight[i][j] > biggesttreesofar){
                biggesttreesofar = treeheight[i][j];
                isvisible[i][j] = true;
            }
        }
    }
}
void checkfromeast(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible){
    for(int i = 0; i < treeheight.size(); ++i){
        int biggesttreesofar = -1;
        for(int j = treeheight[i].size() - 1; j >= 0; --j){
            if(treeheight[i][j] > biggesttreesofar){
                biggesttreesofar = treeheight[i][j];
                isvisible[i][j] = true;
            }
        }
    }
}

void checkfromnorth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible){
    for(int i = 0; i < treeheight[0].size(); ++i){
        int biggesttreesofar = -1;
        for(int j = 0; j < treeheight.size(); ++j){
            if(treeheight[j][i] > biggesttreesofar){
                biggesttreesofar = treeheight[j][i];
                isvisible[j][i] = true;
            }
        }
    }
}

void checkfromsouth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<bool> > & isvisible){
    for(int i = 0; i < treeheight[0].size(); ++i){
        int biggesttreesofar = -1;
        for(int j = treeheight.size() - 1; j >= 0; --j){
            if(treeheight[j][i] > biggesttreesofar){
                biggesttreesofar = treeheight[j][i];
                isvisible[j][i] = true;
            }
        }
    }
}

int countvisibletrees(const std::vector < std::vector<bool> > & isvisible){
    int treecounter = 0;
    for(int i = 0; i < isvisible.size(); ++i){
        for(int j = 0; j < isvisible[i].size(); ++j){
            if(isvisible[i][j]) ++treecounter;
        }
    }
    return treecounter;
}

int main(){
    std::cout << "On the matter of counting visible trees from the outside of the forest:\n";

    std::ifstream inputfile("input");

    if(!inputfile.is_open()){
        std::cout << "file could not be read :(\n";
        return 1;
    }

    std::string line = "";
    std::vector < std::vector < int > > treeheight;
    std::vector < std::vector < bool > > isvisible;
    while( getline(inputfile, line)){
        std::vector <int> rowoftrees;
        std::vector <bool> rowofvisibility;
        for(int i = 0; i < line.length(); ++i){
            rowoftrees.push_back(line[i] - '0');
            rowofvisibility.push_back(false);
        }

        treeheight.push_back(rowoftrees);
        isvisible.push_back(rowofvisibility);

    }
    inputfile.close();

    std::cout << treeheight.size() << std::endl;
    updatevisibilitymap(treeheight, isvisible);
    std::cout << "NUMBER OF VISIBLE TREES: " << countvisibletrees(isvisible) << std::endl;




    return 0;
}
