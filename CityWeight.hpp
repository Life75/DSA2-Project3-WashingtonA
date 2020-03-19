#ifndef CITYWEIGHT_HPP_
#define CITYWEIGHT_HPP_

#include <iostream>
#include <sstream>

/**********************************************************************************
Banner Austyn Washington 3/18/20
CityWeight.hpp
Summary: Simply a holding variable for the 2D array that this will make up for the file

CityWeight(double cityWeight): Takes in the double values from file.

getCityWeight(): Returns the city weight that the object is holding.

setCityWeight(double cityWeight) Sets the city weight.
**********************************************************************************/
class CityWeight
{
    private:
    double cityWeight =-1;

    public:
    CityWeight();
    CityWeight(double cityWeight);
    double getCityWeight();
    void setCityWeight(double cityWeight);
    

};
#endif