#define CATCH_CONFIG_MAIN

#include <sstream>

#include <cstdlib>

#include <queue>

#include "catch/catch.hpp"

#include "../CityWeight.hpp"

#include "../FileReader.hpp"

#include "../BruteForce.hpp"

#include "../Mutation.hpp"

class TestClass {
    void permutation(int n, int arr[], int size) {
        int m, k, p, q, i;
        //printS(arr, size);
        //have a function within that depends and goes through this code and checks the weights
        for (i = 1; i < n; i++) {
            m = size - 2;

            while (arr[m] > arr[m + 1]) {
                m = m - 1;
            }

            k = size - 1;
            while (arr[m] > arr[k]) {
                k = k - 1;
            }

            std::swap(arr[m], arr[k]);
            p = m + 1;
            q = size - 1;
            while (p < q) {
                std::swap(arr[p], arr[q]);
                p++;
                q--;
            }
            //printS(arr, size);
        }
    }

};

TEST_CASE("CityWeight Class") {
    CityWeight cw;
    cw.setCityWeight(.45355);
    REQUIRE(cw.getCityWeight() == .45355);
}

TEST_CASE("FileReader Class")
{
    FileReader reader;
    CityWeight* cw[19][19];
    for(int i =0; i < 19; i++)
    {
        for(int j =0; j < 19; j++)
        {
            cw[i][j] = new CityWeight();
        }
    }

    reader.objectMaker("distances.txt",cw);
    REQUIRE(cw[0][0]->getCityWeight() == 0);
    REQUIRE(cw[0][1]->getCityWeight() == 25.410000);
}

TEST_CASE("BruteForce Class")
{
    
    FileReader reader;
    std::queue<int> elite;
    CityWeight* cw[19][19];
    for(int i =0; i < 19; i++)
    {
        for(int j =0; j < 19; j++)
        {
            cw[i][j] = new CityWeight();
        }
    }

    reader.objectMaker("distances.txt",cw);
    BruteForce* force = new BruteForce(cw);
    int size = 10;
    int factorial =0;
    int arr[]  = {1, 2, 3,4,5,6,7,8,9,10};
    
    factorial = force->factorial(size);
    //REQUIRE(factorial == 3628800);

    force->permutation(factorial, arr , size);
    elite = force->getMostOptimalRoute();
    std::cout << force->getMostOptimalTime() << std::endl;
/*   
    while(!elite.empty())
    {
        std::cout << elite.front() << " ";
        elite.pop();
    }

    int size2=4;
    int arr2[] = {1, 2, 3, 4};
    factorial = force->factorial(size);
    force->permutation(factorial, arr2, size2);
    elite = force->getMostOptimalRoute();
    while(!elite.empty())
    {
        std::cout << elite.front() << " ";
        elite.pop();
    }*/
}


TEST_CASE("Mutation Class")
{
    FileReader reader;
    //std::queue<int> eliteOne;
   // std::queue<int> eliteTwo;
    CityWeight* cityW[19][19];
    for(int i =0; i < 19; i++)
    {
        for(int j =0; j < 19; j++)
        {
            cityW[i][j] = new CityWeight();
        }
    }
    Mutation* mute = new Mutation(cityW);
    reader.objectMaker("distances.txt",cityW);

    int size = 10;
    int randomNum =0;
    int arr[]  = {1, 2, 3, 4,5,6,7,8,9,10};
    
  
    int factorial = mute->factorial(size);
    mute->ModifiedPermutation(factorial, arr, size);
    mute->Mutate(size, 3);
    std::cout << mute->getEliteOneWeights() << std::endl;
    std::cout << mute->getEliteTwoWeights() << std::endl;
    


}