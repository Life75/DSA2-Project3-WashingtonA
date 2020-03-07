#include "CityWeight.hpp"

CityWeight::CityWeight()
{
    cityWeight =-1;
}

CityWeight::CityWeight(double cityWeight)
{
    this->cityWeight = cityWeight;
}
double CityWeight::getCityWeight() {return cityWeight;}

void CityWeight::setCityWeight(double cityWeight) {this->cityWeight = cityWeight;}
