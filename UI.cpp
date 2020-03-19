#include "UI.hpp"
#include <algorithm>
#include <chrono>
using namespace std::chrono;

UI::UI()
{
    SettingUp();
    GetPrompt();
}

void UI::SettingUp()
{
    //setting everything up
    FileReader reader;
    for(int i =0; i < 20; i++)
    {
        for(int j =0; j < 20; j++)
        {
            cw[i][j] = new CityWeight();
        }
    }
    reader.objectMaker("distances.txt", cw);


}

void UI::GetPrompt()
{
    std::cout << "Please enter amount of cites: ";
    std::cin >> size;
    std::cout << "Please enter amount of tours: ";
    std::cin >> tours;
    std::cout << "Please enter amount of generations: ";
    std::cin >> generations;
    std::cout << "Please enter percentage number of the number of mutations: ";
    std::cin >> percentageOfMutations;

    std::cout << "Number of cities: " << size << std::endl;    
    BruteForceData();
    MutationRemasteredData();
    int percent =  mute->getEliteOneWeight()/force->getMostOptimalTime() * 100;
    std::cout << "Percentage of optimal produced by GA elite one: " << percent << "%" << std::endl;

    percent = mute->getEliteTwoWeight()/force->getMostOptimalTime() * 100;
    std::cout << "Percentage of optimal produced by GA elite two: " << percent << "%" << std::endl;
}

void UI::MutationRemasteredData()
{
    mute = new MutationRemastered(tours, generations, percentageOfMutations, size, cw);
    int arr[size];
    for(int i=0; i < size; i++)
        {
            arr[i] = i+1;
        }

    auto start = high_resolution_clock::now();
    mute->Generations(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Cost from GA elite one: "<< mute->getEliteOneWeight() << std::endl;
    std::cout << "Cost from GA elite one: " << mute->getEliteTwoWeight() << std::endl;
    std::cout << "Genetic Algorithim Time: " << duration.count() << " microseconds"<< std::endl;

    
}

void UI::BruteForceData()
{
    force = new BruteForce(cw);
    int arr[size];
    for(int i=0; i < size; i++)
        {
            arr[i] = i+1;
        }
    int factorial = force->factorial(size);
    
    auto start = high_resolution_clock::now();
    force->permutation(factorial, arr , size);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);


    //elite = force->getMostOptimalRoute();
    std::cout << "Brute force optimal cost: " << force->getMostOptimalTime() << std::endl;
    std::cout << "Time taken for brute force: " << duration.count() << " microseconds" << std::endl;
}

