#ifndef MUTATION_HPP_
#define MUTATION_HPP_

#include <iostream>
#include "CityWeight.hpp"
#include <queue>

class Mutation
{
    private:
    CityWeight* cw[19][19];
    std::queue<int> eliteOne;
    std::queue<int> eliteTwo;
    double optimalOne;
    double optimalTwo;


    public:
    Mutation(CityWeight* cw[][19]);
    void ModifiedPermutation(int n, int arr[], int size);
    void OptimalCheck(int arr[], int size);
    int RandomNum(int size);
    int factorial(int num);
    void Mutate(int size, int generations);
    void Mutating(int arr[], int size);
    int getWeightRoutes(int arr[], int size);
    std::queue<int> getEliteOne();
    std::queue<int> getEliteTwo();
    int getEliteOneWeights();
    int getEliteTwoWeights();





};
#endif