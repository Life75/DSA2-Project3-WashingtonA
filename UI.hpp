#ifndef UI_HPP_
#define UI_HPP_

#include "MutationRemastered.hpp"
#include "FileReader.hpp"
#include "BruteForce.hpp"
#include <queue>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

/**********************************************************************************
Banner Austyn Washington 3/18/20
UI class main purpose is to basically mesh everything together of all the classes: brute force, mutationRemastered, and FileReader.
It combines them and creates an interface for the user to use and this allows for main.cpp not to be cluttered 

GetPrompt(): Gets the prompt data to ask the user on the specification on the values in question for amount of cities and etc about the GA

SettingUp(): Sets up the objects in the 2D array to read from the file and hold them.

MutationRemasteredData(): Inputs the data asked from the GetPrompt() and creates the MutationRemastered object and calculates and displays values

BruteForceData(): Inputs the data asked from the GetPrompt() and creates the BruteForce object and calculates and displays values.
**********************************************************************************/

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