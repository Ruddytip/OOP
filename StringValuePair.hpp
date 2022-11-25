#pragma once
#include <string>
#include "Pair.hpp"

// 3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
// Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
// Следующий код:
// int main(){
    // StringValuePair<int> svp("Amazing", 7);
    // std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    // return 0;
// }
// … должен производить следующий результат:
// Pair: Amazing 7
// Подсказка: при вызове конструктора класса **Pair* из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair. *
template<typename T>
class StringValuePair : public Pair<std::string, T>{
private:
public:
    StringValuePair(std::string str, T data): Pair<std::string, T>(str, data){}
    std::string first(){ return Pair<std::string, T>::first(); }
    T second(){ return Pair<std::string, T>::second(); }
};