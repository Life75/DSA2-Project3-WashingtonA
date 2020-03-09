#include "BruteForce.hpp"
#include "CityWeight.hpp"
#include <queue>

BruteForce::BruteForce(CityWeight* cw[][19])
{
    for(int i =0; i < 19; i++)
        for(int j=0; j < 19; j++)
        {
            this->cw[i][j] = cw[i][j];
        }
        //std::cout << cw[3][3]->getCityWeight();
}

int BruteForce::factorial(int num)
{
    int factorial= 1;
    
    for(int i=1; i <= num; ++i)
    factorial *=i;
    return factorial;
}

void BruteForce::permutation(int n, int arr[], int size)
{
    int m, k, p, q, i;
    //std::cout << p;
        optimalCheck(arr,size);
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
            optimalCheck(arr ,size);
        }
}

void BruteForce::optimalCheck(int arr[],int size)
{
    double totalWeightHere =0;
    int index =0;
    int indexPlus =0;

    for(int i=0; i < size; i++)
    {
        index = arr[i];
        indexPlus = arr[i+1];
        if(i == 0)
        {
            
            totalWeightHere += this->cw[0][index]->getCityWeight();
           // std::cout << 0 << "," << index << " | "; 
        }
        else 
        {
            if(i != size-1 )
            {
                totalWeightHere += cw[index][indexPlus]->getCityWeight();
               // std::cout << index << "," << indexPlus << " | "; 
            }

            else 
            {
               totalWeightHere += cw[index][0]->getCityWeight();
               //std::cout << index << "," << 0; 
            }
        }   
    }
        //std::cout << totalWeightHere << "\n";

    if(totalWeightHere < optimal || optimal == -1)
    {
        if(!elite.empty())
        {
            while(!elite.empty())
            {
                elite.pop();
            }
        }
        for(int i=0; i < size; i++)
        {
            elite.push(arr[i]);
            optimal = totalWeightHere;
        }
    }
   
}

std::queue<int> BruteForce::getMostOptimalRoute()
{
    return elite;
}

double BruteForce::getMostOptimalTime()
{
    return optimal;
}



