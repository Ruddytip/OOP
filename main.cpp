#include <iostream>
#include "SmartPTR.hpp"  // Умные указатели
#include "Date.hpp"      // Task 1
#include "Blackjack.hpp" // Task 3, Создать класс Deck
                         // Task 4, Реализовать класс Game

// Task 2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
// • Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и
// сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
// • Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
// Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
SmartPTR<Date>& returnLateDate(SmartPTR<Date>& date1, SmartPTR<Date>& date2){
    // Проверка годов
    if(date2->getYear() > date1->getYear())  return date2;
    if(date2->getYear() < date1->getYear())  return date1;
    // Проверка месяцев
    if(date2->getMonth() > date1->getMonth())  return date2;
    if(date2->getMonth() < date1->getMonth())  return date1;
    // Проверка дней
    if(date2->getDay() > date1->getDay())  return date2;
    if(date2->getDay() < date1->getDay())  return date1;
    // Возвращает первый указатель, если даты одинаковы
    return date1;
}

void swapDate(SmartPTR<Date>& date1, SmartPTR<Date>& date2){
    // Если нет неоюбходимости сохранять адреса
    // std::swap(date1, date2);

    // Елси необходимо поменять значения, но сохранить адреса
    Date dir = *date1;
    date1->setDay(date2->getDay());
    date1->setMonth(date2->getMonth());
    date1->setYear(date2->getYear());
    date2->setDay(dir.getDay());
    date2->setMonth(dir.getMonth());
    date2->setYear(dir.getYear());
}

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    SmartPTR<Date> today = new Date;
    today->setDay(30);
    today->setMonth(11);
    today->setYear(2022);
    std::cout << "Today: " << *today << std::endl;
    SmartPTR<Date> date = today;
    std::cout << "Adress date:  " << &(*date) << std::endl;
    std::cout << "Adress today: " << &(*today) << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 2
    std::cout << "Task 2:\n";
    SmartPTR<Date> d1(new Date(11, 12, 2000));
    SmartPTR<Date> d2(new Date(1, 2, 2019));
    std::cout << "Last date: " << *returnLateDate(d1, d2) << std::endl;

    std::cout << "Before swap:\n";
    std::cout << "Date 1: " << *d1 << " Adress: " << &(*d1) << std::endl;
    std::cout << "Date 2: " << *d2 << " Adress: " << &(*d2) << std::endl;
    swapDate(d1, d2);
    std::cout << "After swap:\n";
    std::cout << "Date 1: " << *d1 << " Adress: " << &(*d1) << std::endl;
    std::cout << "Date 2: " << *d2 << " Adress: " << &(*d2) << std::endl;
    std::cout << std::endl;
    // ====================

    // Task 5. Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков.
    // Создается объект класса Game и запускается игровой процесс. Предусмотреть возможность повторной игры.
    const unsigned int count_players = 3;
    while(true){
        std::string str("");
        std::vector<std::string> names;
        for(unsigned int i = 0; i < count_players; ++i){
            std::cout << "Enter name: ";
            std::cin >> str;
            names.push_back(str);
        }
        Game game1(names);
        game1.play();
        std::cout << "Do you want to play again?(y/n)";
        std::cin >> str;
        if(str == "n") break;
    }

    return 0;
}