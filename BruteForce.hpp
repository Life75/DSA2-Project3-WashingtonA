#ifndef BRUTEFORCE_HPP_
#define BRUTEFORCE_HPP_

#include <iostream>
#include "CityWeight.hpp"
#include <queue>
/**********************************************************************************
Banner Austyn Washington 3/18/20
BruteForce.hpp
Summary: Brute Force class goes through the algorithm of checking every and each indiviual city value and 
calculating the most optimal cost.

BruteForce(CityWeight* cw[][20]): Takes in the 2D array and copies the data over from file given.

factorial(int num): Gets the factorial number and the param is for the amount of cities and returns the int 

permutation(int n, int arr[], int size): Goes through each individual city and permutates through 

optimalCheck(int arr[], int size): Takes in the specific array through the permutation including it's size and calculates the optimal cost during the loop process of permutation()

getMostOptimalTime(): Nested within optimal check it does a check to see if whatever data given in the array calculated is less than the optimal cost if so then replace and store the optimal path as well

**********************************************************************************/
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