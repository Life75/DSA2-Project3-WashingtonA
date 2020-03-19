#ifndef UI_HPP_
#define UI_HPP_

#include "MutationRemastered.hpp"
#include "FileReader.hpp"
#include "BruteForce.hpp"
#include <queue>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

class UI
{
    private:
    CityWeight* cw[20][20];
    int tours=0;
    int size=0;
    double percentageOfMutations=0; 
    int generations=0;
    std::queue<int> eliteOne;
    std::queue<int> eliteTwo;
    MutationRemastered* mute;
    BruteForce* force; 
    
    public:
    UI();
    void GetPrompt();
    void SettingUp();
    void MutationRemasteredData();
    void BruteForceData();
};
#endif