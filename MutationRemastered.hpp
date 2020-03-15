#ifndef MUTATIONREMASTERED_HPP_
#define MUTATIONREMASTERED_HPP_

#include "CityWeight.hpp"
#include <queue>


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
    //int arr[];
    

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