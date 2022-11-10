#include <iostream>
#include "Power.hpp" // Task 1
#include "RGBA.hpp"  // Task 2
#include "Stack.hpp" // Task 3

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    RGBA color1;
    color1.print();
    RGBA color2(100, 100, 100, 100);
    color2.print();
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    Power power;
    power.set(2, 8);
    power.calculate();
    std::cout << std::endl;
    // ====================

    // Task 3
    std::cout << "Task 3:\n";
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    std::cout << std::endl;
    // ====================
    return 0;
}