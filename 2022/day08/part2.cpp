#include <iostream>
#include <fstream>
#include <vector>

void updatevisibilitymap(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore);
void checkfromwest(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore);
void checkfromeast(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore);
void checkfromnorth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore);
void checkfromsouth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore);
int countvisibletrees(const std::vector < std::vector<int> > & visibilityscore);
int gethighestvisibilityscore(const std::vector < std::vector<int> > & visibilityscore);

void updatevisibilitymap(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore){
    checkfromwest(treeheight, visibilityscore);
    checkfromeast(treeheight, visibilityscore);
    checkfromnorth(treeheight, visibilityscore);
    checkfromsouth(treeheight, visibilityscore);
}

void checkfromwest(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore){
    //for each row of trees
    for(int i = 0; i < treeheight.size(); ++i){
        //keeps track of the index where we saw each tree height most recently
        int indexlastseen [10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        //for each tree in the row
        for(int j = 0; j < treeheight[i].size(); ++j){

            //find the nearest obstruction by looking at the nearest tree of each height
            int nearestobstructionindex = 0;
            //only consider trees of equal or taller height
            for(int k = treeheight[i][j]; k < 10; ++k){
                //if we find a close tall tree, remember the index
                if(indexlastseen[k] > nearestobstructionindex){
                    nearestobstructionindex = indexlastseen[k];
                }
            }
            //determine the score multiplier
            int scoremultiplier = j - nearestobstructionindex;
            
            //apple the score multiplier
            visibilityscore[i][j] *= scoremultiplier;

            //update the index tracker
            indexlastseen[treeheight[i][j]] = j;
        }
    }
}
void checkfromeast(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore){
    //for each row of trees
    for(int i = 0; i < treeheight.size(); ++i){
        //keeps track of the index where we saw each tree height most recently
        int n = treeheight.size() - 1; //should be 98
        int indexlastseen [10] = { n, n, n, n, n, n, n, n, n, n };
        //for each tree in the row
        for(int j = treeheight[i].size() - 1; j >= 0; --j){

            //find the nearest obstruction by looking at the nearest tree of each height
            int nearestobstructionindex = 0;
            //only consider trees of equal or taller height
            for(int k = treeheight[i][j]; k < 10; ++k){
                //if we find a close tall tree, remember the index
                if(indexlastseen[k] < nearestobstructionindex){
                    nearestobstructionindex = indexlastseen[k];
                }
            }
            //determine the score multiplier
            int scoremultiplier = nearestobstructionindex - j;
            
            //apple the score multiplier
            visibilityscore[i][j] *= scoremultiplier;

            //update the index tracker
            indexlastseen[treeheight[i][j]] = j;
        }
    }
}

void checkfromnorth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore){
    //for each column of trees
    for(int i = 0; i < treeheight[0].size(); ++i){
        //keeps track of the index where we saw each tree height most recently
        int indexlastseen [10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        //for each tree in the column
        for(int j = 0; j < treeheight.size(); ++j){

            //find the nearest obstruction by looking at the nearest tree of each height
            int nearestobstructionindex = 0;
            //only consider trees of equal or taller height
            for(int k = treeheight[j][i]; k < 10; ++k){
                //if we find a close tall tree, remember the index
                if(indexlastseen[k] > nearestobstructionindex){
                    nearestobstructionindex = indexlastseen[k];
                }
            }
            //determine the score multiplier
            int scoremultiplier = j - nearestobstructionindex;
            
            //apple the score multiplier
            visibilityscore[j][i] *= scoremultiplier;

            //update the index tracker
            indexlastseen[treeheight[j][i]] = j;
        }
    }
}

void checkfromsouth(const std::vector < std::vector<int> > & treeheight, std::vector < std::vector<int> > & visibilityscore){
    //for each column of trees
    for(int i = 0; i < treeheight[0].size(); ++i){
        //keeps track of the index where we saw each tree height most recently
        int indexlastseen [10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        //for each tree in the column
        for(int j = treeheight.size() - 1; j >= 0; --j){

            //find the nearest obstruction by looking at the nearest tree of each height
            int nearestobstructionindex = 0;
            //only consider trees of equal or taller height
            for(int k = treeheight[j][i]; k < 10; ++k){
                //if we find a close tall tree, remember the index
                if(indexlastseen[k] < nearestobstructionindex){
                    nearestobstructionindex = indexlastseen[k];
                }
            }
            //determine the score multiplier
            int scoremultiplier = nearestobstructionindex - j;
            
            //apple the score multiplier
            visibilityscore[j][i] *= scoremultiplier;

            //update the index tracker
            indexlastseen[treeheight[j][i]] = j;
        }
    }
}

int countvisibletrees(const std::vector < std::vector<int> > & visibilityscore){
    int treecounter = 0;
    for(int i = 0; i < visibilityscore.size(); ++i){
        for(int j = 0; j < visibilityscore[i].size(); ++j){
            if(visibilityscore[i][j]) ++treecounter;
        }
    }
    return treecounter;
}

int gethighestvisibilityscore(const std::vector < std::vector<int> > & visibilityscore){
    int bestscore = 0;
    for(int i = 0; i < visibilityscore.size(); ++i){
        for(int j = 0; j < visibilityscore[i].size(); ++j){
            if(visibilityscore[i][j] > bestscore){
                bestscore = visibilityscore[i][j];
                std::cout << "FOUND HIGH SCORE at " << i << "," << j << ": " << bestscore << std::endl;
            }
        }
    }
    return bestscore;
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
    std::vector < std::vector < int > > visibilityscore;
    while( getline(inputfile, line)){
        std::vector <int> rowoftrees;
        std::vector <int> rowofvisibility;
        for(int i = 0; i < line.length(); ++i){
            rowoftrees.push_back(line[i] - '0');
            rowofvisibility.push_back(1);
        }

        treeheight.push_back(rowoftrees);
        visibilityscore.push_back(rowofvisibility);

    }
    inputfile.close();

    std::cout << treeheight.size() << std::endl;
    updatevisibilitymap(treeheight, visibilityscore);
    std::cout << "HIGHEST VISIBILITY SCORE: " << gethighestvisibilityscore(visibilityscore) << std::endl;




    return 0;
}
