#include "FileReader.hpp"

void FileReader::objectMaker(std::string fileName,CityWeight* arr[20][20])
{
    std::fstream file;
    std::queue<double> holder;
    file.open(fileName.c_str());
    double weight =-1;
    int row =20;
    int col =20;
    if(fileName == "distances.txt")
    {
        while(file >> weight)
        {
            //holds data in a queue for extraction for 2D array
            holder.push(weight);
        }

        for(int i=0; i < row; i++)
            for(int j=0; j < col; j++)
            {
                if(i != j)
                {
                    arr[i][j]->setCityWeight(holder.front()); 
                    holder.pop();
                }
                else arr[i][j]->setCityWeight(0);
            }
    }
}