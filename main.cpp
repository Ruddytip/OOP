#include <iostream>
#include "Pair.hpp"            // Task 1, 2
#include "StringValuePair.hpp" // Task 3
#include "Blackjack.hpp"       // Task 4, Реализовать класс Hand

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    Pair<int, double> pt1(6, 7.8);
    std::cout << "Pair: " << pt1.first() << ' ' << pt1.second() << '\n';
    const Pair<double, int> pt2(3.4, 5);
    std::cout << "Pair: " << pt2.first() << ' ' << pt2.second() << '\n';
    std::cout << std::endl;
    // ====================

    // Task 3
    std::cout << "Task 3:\n";
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    std::cout << std::endl;
    // ====================

    return 0;
}