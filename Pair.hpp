#pragma once

// Task 1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
// Следующий код:
// int main(){
    // Pair1<int> p1(6, 9);
    // cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    // const Pair1<double> p2(3.4, 7.8);
    // cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    // return 0;
// }
// … должен производить результат:
// Pair: 6 9
// Pair: 3.4 7.8
template<typename T>
class Pair1{
private:
    T data_first, data_second;
public:
    Pair1(const T f, const T s): data_first(f), data_second(s){}
    T first() const { return data_first; }
    T second() const { return data_second; }
};

// Task 2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
// Следующий код:
// int main(){
    // Pair<int, double> p1(6, 7.8);
    // cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    // const Pair<double, int> p2(3.4, 5);
    // cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    // return 0;
// }
// … должен производить следующий результат:
// Pair: 6 7.8
// Pair: 3.4 5
// Подсказка: чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запятой.
template<typename F, typename S>
class Pair{
private:
    F data_first;
    S data_second;
public:
    Pair(const F f, const S s): data_first(f), data_second(s){}
    F first() const { return data_first; }
    S second() const { return data_second; }
};