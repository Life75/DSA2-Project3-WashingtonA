#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

#include <iostream>
#include "CityWeight.hpp"
#include <fstream>
#include <queue>

/**********************************************************************************
Banner Austyn Washington 3/18/20
FileReader.hpp
Summary: Simply reads the file and creates the objects for the pass by array 

objectMaker(std::string fileName, CityWeight* arr[][]): Reads the file and takes in the array to place the objects inside the CityWeight 2D array
**********************************************************************************/
class FileReader
{
    private:
  

    public:
    void objectMaker(std::string fileName,CityWeight* arr[20][20]);

};
#endif