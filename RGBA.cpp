#include "RGBA.hpp"
#include <iostream>

RGBA::RGBA(){

}

RGBA::RGBA(std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, std::uint8_t _a):
m_red(_r), m_green(_g), m_blue(_b), m_alpha(_a){ 

}

void RGBA::print(){
    std::cout << "Red:   " << int(m_red)   << std::endl;
    std::cout << "Green: " << int(m_green) << std::endl;
    std::cout << "Blue:  " << int(m_blue)  << std::endl;
    std::cout << "Alpha: " << int(m_alpha) << std::endl;
}