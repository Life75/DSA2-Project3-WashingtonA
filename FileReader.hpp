#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

#include <iostream>
#include "CityWeight.hpp"
#include <fstream>
#include <queue>

class FileReader
{
    private:

    public:
    //pass by array ref, read the file and create objects out of all the points
    void objectMaker(std::string fileName,CityWeight* arr[19][19]);

};
#endif