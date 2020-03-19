#ifndef MUTATIONREMASTERED_HPP_
#define MUTATIONREMASTERED_HPP_

#include "CityWeight.hpp"
#include <queue>

/**********************************************************************************
Banner Austyn Washington 3/18/20
MutationRemastered.hpp
Summary: Redo of the Mutation class because I personally didn't like the way it was worked so I resketched a lot of the mistakes and work
to make a better Mutation class. It gets a set amount of tours and generations and percentage amount willing to mutate for this GA. There's generations and a number of tours in those said 
generations the algorithm goes through and selecting the top 2 elite ones. Not only holding the cost of both but the pathways as well. The mutation 
works by picking a random number and just swapping in a loop fashion (ex: Array size = 3, randomNum = 2, and percentage of mutation: 10%, which means only one swap in this case. Loop will start at 0 always and swap placements 0 and 2 of array generating 
new value point so forth)
This class is very similar to the makeup of BruteForce.hpp. 
**********************************************************************************/
class MutationRemastered
{
    private:
    int rows =20;
    int cols =20;
    int tours =0;
    int generations; 
    int size = 0;
    double percentageOfMutations;
    double optimalOne = -1;
    double optimalTwo = -1;
    std::queue<int> eliteOne;
    std::queue<int> eliteTwo;
    CityWeight* cw[20][20];
    

    public:
    MutationRemastered(int tours, int generations, double percentageOfMutations, int size ,CityWeight* cw[][20] );
    void Tours(int arr[]);
    void optimalCheckEliteOne(int arr[]);
    void optimalCheckEliteTwo(int arr[]);
    double optimalCheck(int arr[]);
    void Mutate();
    void Generations(int arr[]);
    int RandomNum();
    double getEliteOneWeight();
    double getEliteTwoWeight();
};
#endif