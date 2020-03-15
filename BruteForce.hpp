#ifndef BRUTEFORCE_HPP_
#define BRUTEFORCE_HPP_

#include <iostream>
#include "CityWeight.hpp"
#include <queue>
class BruteForce
{
    private:
    double optimal = -1;  
    CityWeight* cw[20][20];  
    std::queue<int> elite;
   

    public:
    BruteForce(CityWeight* cw[][20]);
    int factorial(int num);
    void permutation(int n, int arr[], int size);
    void optimalCheck(int arr[], int size);
    double getMostOptimalTime();
    std::queue<int> getMostOptimalRoute();
    

};
#endif