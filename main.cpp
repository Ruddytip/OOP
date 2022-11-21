#include <iostream>
#include "ArrayInt.hpp"  // Task 1
#include <vector>        // Для выполнения Task 2
#include "Blackjack.hpp" // Task 3, Реализовать класс Hand
#include <ctime>         // Для srand

struct Node{
    int key;   // Значение числа
    int count; // Кол-во повторений
};

// Подсчитывает уникальные целые числа
std::vector<Node> CountVectorNumber(const std::vector<int>& in){
    std::vector<Node> out;
    for(unsigned int i = 0; i < in.size(); ++i){
        bool flag = false;
        for(unsigned int j = 0; j < out.size(); ++j){
            if(out[j].key == in[i]){
                flag = true;
                out[j].count++;
            }
        }
        if(!flag){
            Node data;
            data.key = in[i];
            data.count = 1;
            out.push_back(data);
        }
    }
    return out;
}

int main(){
    // Task 1
    std::cout << "Task 1:\n";
    ArrayInt arr;
    arr.push_back(14);
    arr.push_back(5);
    arr.push_back(40);
    arr.push_back(22);
    arr.push_back(9);
    arr.print();
    arr.sort();
    arr.print();
    std::cout << "Pop first: " << arr.pop_front() << std::endl;
    std::cout << "Pop last:  " << arr.pop_back() << std::endl;
    arr.print();
    std::cout << std::endl;
    // ====================

    // Task 2
    // Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
    std::cout << "Task 2:\n";
    const int SIZE = 15;
    std::vector<int> data;
    srand(time(0));
    std::cout << "Vector: ";
    for(unsigned int i = 0; i < SIZE; ++i){
        data.push_back(rand() % 10);
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    std::vector<Node> out = CountVectorNumber(data);

    std::cout << "Info vector:\n";
    for(unsigned int i = 0; i < out.size(); ++i)
        std::cout << "Key: " << out[i].key << " - " << out[i].count << "counts\n";
    std::cout << std::endl;
    // ====================

    return 0;
}