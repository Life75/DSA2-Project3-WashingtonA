#include "Mutation.hpp"
#include "CityWeight.hpp"


Mutation::Mutation(CityWeight* cw[][19])
{
    optimalOne =-1;
    optimalTwo =-1;
    for(int i =0; i < 19; i++)
        for(int j=0; j < 19; j++)
        {
            this->cw[i][j] = cw[i][j];
        }  
}

int Mutation::RandomNum(int size)
{
    int randomNum = 0;
    srand((unsigned int) time(0));
    randomNum = rand() % size + 1;

    //std::cout << randomNum;
    return randomNum;
    
}

int Mutation::factorial(int num)
{
    int factorial= 1;
    
    for(int i=1; i <= num; ++i)
    factorial *=i;
    return factorial;
}

void Mutation::ModifiedPermutation(int n, int arr[], int size)
{
   int m, k, p, q, i;
    //std::cout << p;
        OptimalCheck(arr,size);
        //have a function within that depends and goes through this code and checks the weights
        //Only goes to half the factorial to get the 
        for (i = 1; i < n/2; i++) {
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
            OptimalCheck(arr ,size);
        }
}

void Mutation::OptimalCheck(int arr[], int size)
{
    double totalWeightHere =0;
    int index =0;
    int indexPlus =0;
    bool counter = false;

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
    
    if(totalWeightHere < optimalTwo || optimalTwo == -1)
    {
        if(!eliteTwo.empty())
            {
                while(!eliteTwo.empty())
                {
                    eliteTwo.pop();
                }
            }
            for(int i=0; i < size; i++)
            {
                eliteTwo.push(arr[i]);
                optimalTwo = totalWeightHere;
            }
            counter = true;  
    }

    if(totalWeightHere < optimalOne || optimalOne == -1)
    {
        if(!counter)
        {
            if(!eliteOne.empty())
            {
                while(!eliteOne.empty())
                {
                    eliteOne.pop();
                }
            }
            for(int i=0; i < size; i++)
            {
                eliteOne.push(arr[i]);
                optimalOne = totalWeightHere;
            }
        }
    }

}

void Mutation::Mutate(int size, int generations)
{
    int eliteOneArr[size];
    int eliteTwoArr[size];

    for(int i=0; i < size; i++)
    {
        eliteOneArr[i] = eliteOne.front();
        eliteOne.pop();
    }

      for(int i=0; i < size; i++)
    {
        eliteTwoArr[i] = eliteTwo.front();
        eliteTwo.pop();
    }

    for(int i=0; i < generations; i++)
    {
        Mutating(eliteOneArr, size);
        Mutating(eliteTwoArr, size);
    }

    optimalOne = getWeightRoutes(eliteOneArr, size);
    optimalTwo = getWeightRoutes(eliteTwoArr, size); 

    while(!eliteOne.empty())
    {
        eliteOne.pop();
    }
    for(int i=0; i < size; i++)
        {
            eliteOne.push(eliteOneArr[i]);
        }

    while(!eliteTwo.empty())
    {
        eliteTwo.pop();
    }
    for(int i=0; i < size; i++)
        {
            eliteTwo.push(eliteTwoArr[i]);
        }
}

std::queue<int> Mutation::getEliteOne()
{
    return eliteOne;
}

std::queue<int> Mutation::getEliteTwo()
{
    return eliteTwo;
}

int Mutation::getEliteOneWeights()
{
    return optimalOne;
}

int Mutation::getEliteTwoWeights()
{
    return optimalTwo;
}

int Mutation::getWeightRoutes(int arr[], int size)
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
    return totalWeightHere; 
}

void Mutation::Mutating(int arr[], int size)
{
      int m, k, p, q, i;
    //std::cout << p;
       // OptimalCheck(arr,size);
        //have a function within that depends and goes through this code and checks the weights
        //Only goes to half the factorial to get the 
        for (i = 1; i < RandomNum(size); i++) {
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
          //  OptimalCheck(arr ,size);
        }
}