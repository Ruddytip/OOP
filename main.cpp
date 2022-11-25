#include <iostream>
#include <iomanip>
#include "Mymanip.hpp"   // Task 2
#include "Blackjack.hpp" // Task 3, Реализовать класс Player
                         // Task 4, Реализовать класс House
                         // Task 5. Написать перегрузку оператора вывода для класса Card.
                         // Также для класса GenericPlayer написать перегрузку оператора вывода,
                         // который должен отображать имя игрока и его карты, а также общую сумму очков его карт

int main(){
    // Task 1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
    // если пользователь вводит что-то кроме одного целочисленного значения,
    // нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк:
    // rbtrb
    // nj34njkn
    // 1n
    std::cout << "Task 1:\n";
    while(true){
        std::string str = "";
        std::getline(std::cin, str);
        bool flag = true;
        for(unsigned int i = 0; i < str.length(); ++i){
            if(str[i] < '0' || str[i] > '9'){
                flag = false;
                break;
            }
        }
        if(!flag){
            std::cerr << "Error input!!!" << std::endl;
            std::cout << "Try again: ";
        } else{
            break;
        }
    }
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    std::cout << "Begin:" << endll << "End:";
    std::cout << std::endl;
    // ====================

    return 0;
}