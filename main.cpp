#include <iostream>
#include "Person.hpp"    // Task 1
#include "Fruit.hpp"     // Task 2
// #include "Blackjack.hpp" // Task 3

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    Student S_Gena("Gena", 23, 'M', 110, 3);
    S_Gena.printInfo();
    Student S_Sonya("Sonya", 30, 'W', 55, 1);
    S_Sonya.printInfo();
    Student S_Vadim("Vadim", 50, 'M', 85, 4);
    S_Vadim.printInfo();
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    std::cout << std::endl;
    // ====================

    // Task 3
    // Изучить правила игры в Blackjack.
    // Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
    // Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
    // Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.
    // ====================



    // ====================
    return 0;
}