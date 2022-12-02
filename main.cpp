#include <iostream>
#include "MyException.hpp" // Task 2, Написать класс Ex
#include "Robot.hpp"       // Task 3, Написать класс «робот»

// Task 1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и
// запускать исключение DivisionByZero, если второй параметр равен 0.
// В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
template<typename T, typename S>
double div(const T first, const S second){
    if(second == 0) throw "DivisionByZero";
    return static_cast<double>(first) / static_cast<double>(second);
}                       

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    try{
        std::cout << "4 / 3 = " << div<double, double>(4, 3) << std::endl;
        std::cout << "4 / 0 = " << div<int, int>(4, 0) << std::endl;
    }
    catch(const char* err){
        std::cerr << err << std::endl;
    }
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    Bar bar;
    while(true){
        int n = 0;
        std::cout << "Enter number: ";
        std::cin >> n;
        if(n == 0) break;
        try{
            bar.set(n);
        }
        catch(Ex& ex){
            std::cerr << ex.getData() << std::endl;
        }
    }
    std::cout << std::endl;
    // ====================

    // Task 3
    std::cout << "Task 3:\n";
    FLD field(10, 10);
    try{
        Robot r(5, -5, field);
        // Robot r(5, -5, field);
        r.move(Robot::Up, field);
        // r.move('r', field);
    }
    catch(ExRobot& ex){
        ex.prinErr();
    }
    std::cout << std::endl;
    // ====================

    return 0;
}