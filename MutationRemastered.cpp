#include "MutationRemastered.hpp"

MutationRemastered::MutationRemastered(int tours, int generations, double percentageOfMutations, int size ,CityWeight* cw[][20])
{
    this->tours = tours;
    this->generations = generations;
    this->percentageOfMutations = percentageOfMutations /100; 
    this->size = size;

    optimalOne =-1;
    optimalTwo =-1;
    for(int i =0; i < rows; i++)
        for(int j=0; j < cols; j++)
        {
            this->cw[i][j] = cw[i][j];
        } 
}

int MutationRemastered::RandomNum()
{
    int sizeR = size -1;
    int randomNum = 0;
    srand((unsigned int) time(0));
    randomNum = rand() % sizeR + 1;

    //std::cout << randomNum;
    return randomNum;
    
}

void MutationRemastered::Tours(int arr[])
{
    int m, k, p, q, i;
    //std::cout << p;
        //optimalCheck(arr,size);
        //have a function within that depends and goes through this code and checks the weights
        for (i = 1; i < tours * generations; i++) {
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
            if(i % 2 ==0) optimalCheckEliteOne(arr);
            else optimalCheckEliteTwo(arr);
        }
}

void MutationRemastered::optimalCheckEliteOne(int arr[])
{
    double totalWeightHere = optimalCheck(arr);
    //std::cout << "ho";
    if(totalWeightHere < optimalOne || optimalOne == -1)
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
        }
        optimalOne = totalWeightHere;
    }
}

void MutationRemastered::optimalCheckEliteTwo(int arr[])
{
    double totalWeightHere = optimalCheck(arr);
    //std::cout << "hey";
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
        }
        optimalTwo = totalWeightHere;
    }
}

double MutationRemastered::optimalCheck(int arr[])
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

void MutationRemastered::Mutate()
{
    int eliteOneArr[size];
    int eliteTwoArr[size];
    double mutationWeightOne =0;
    double mutationWeightTwo =0;
    //factors in the certain percentage of the mutation(s)
    int mutations = percentageOfMutations * size;

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

    for(int i=0; i < mutations; i++)
    {
        std::swap(eliteOneArr[RandomNum()], eliteOneArr[i]);
        std::swap(eliteTwoArr[RandomNum()], eliteTwoArr[i]);
    }


    mutationWeightOne = optimalCheck(eliteOneArr);
    mutationWeightTwo = optimalCheck(eliteTwoArr);


    for(int i=0; i < size; i++)
    {
        eliteOne.push(eliteOneArr[i]);
        eliteTwo.push(eliteTwoArr[i]);
    }

    optimalOne = mutationWeightOne;
    optimalTwo = mutationWeightTwo;

    

}

void MutationRemastered::Generations(int arr[])
{
    if(optimalOne == -1 && optimalTwo == -1)
    {
        optimalCheckEliteOne(arr);
        optimalCheckEliteTwo(arr);     
    }
//get a seg fault when putting tours intom the generations pool so I will mutate with the elites.
    Tours(arr);
    for(int i=0; i < generations; i++)
    {
        Mutate();
    }

}

double MutationRemastered::getEliteOneWeight()
{
    return optimalOne;
}

double MutationRemastered::getEliteTwoWeight()
{
    return optimalTwo;
}