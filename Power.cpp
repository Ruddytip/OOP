#include "Power.hpp"
#include <iostream>
#include <cmath>

Power::Power(){}
Power::~Power(){}

void Power::set(const int f, const int d){
    foundation = f;
    degree = d;
}

void Power::calculate(){
    std::cout << "Pow = ";
    std::cout << std::pow(foundation, degree) << std::endl;
}