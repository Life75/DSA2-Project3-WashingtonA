#ifndef CITYWEIGHT_HPP_
#define CITYWEIGHT_HPP_

#include <iostream>
#include <sstream>

class CityWeight
{
    private:
    double cityWeight =-1;

    public:
    double getCityWeight() {return cityWeight;}
    void setCityWeight(double cityWeight) {this->cityWeight = cityWeight;}
    

};
#endif