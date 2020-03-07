#ifndef CITYWEIGHT_HPP_
#define CITYWEIGHT_HPP_

#include <iostream>
#include <sstream>

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