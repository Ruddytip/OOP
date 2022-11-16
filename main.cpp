#include <iostream>
#include "Figure.hpp"    // Task 1
#include "Car.hpp"       // Task 2
#include "Fraction.hpp"  // Task 3
#include "Blackjack.hpp" // Task 4

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    Circle c(15);            std::cout << "Circle -------- " << c.area() << std::endl;
    Parallelogram p(10, 20); std::cout << "Parallelogram - " << p.area() << std::endl;
    Rectangle r(15, 45);     std::cout << "Rectangle ----- " << r.area() << std::endl;
    Square s(25);            std::cout << "Square -------- " << s.area() << std::endl;
    Rhombus h(40, 30);       std::cout << "Rhombus ------- " << h.area() << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    std::cout << "Only Car: ";          Car cCar;          std::cout << std::endl;
    std::cout << "Only PassengerCar: "; PassengerCar pCar; std::cout << std::endl;
    std::cout << "Only Bus: ";          Bus bCar;          std::cout << std::endl;
    std::cout << "Only Minivan: ";      Minivan mCar;      std::cout << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 3
    std::cout << "Task 3:\n";
    Fraction f1(5, 3);
    Fraction f2(4, 9);
    std::cout << f1 << ' ' << f2 << std::endl;
    std::cout << f1 + f2 << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 4
    std::cout << "Task 4:\n";
    Card cardKing(king, heart);
    std::cout << "Card`s value is: " << cardKing.GetValue()    << std::endl;
    Card cardDiamond(ace, diamond);
    std::cout << "Card`s value is: " << cardDiamond.GetValue() << std::endl;
    std::cout << std::endl;
    // ====================
    return 0;
}