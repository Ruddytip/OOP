#include "Stack.hpp"
#include <iostream>

Stack::Stack(){
    arr = new int[TASK_SIZE];
    reset();
}

Stack::~Stack(){
    delete[] arr;
}

void Stack::reset(){
    size = 0;
    for(unsigned int i = 0; i < TASK_SIZE; ++i)
        arr[i] = 0;
}

void Stack::print(){
    std::cout << "( ";
    for(unsigned int i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << ")\n";
}

void Stack::push(const int data){
    arr[size++] = data;
}

int Stack::pop(){
    if(size == 0){
        std::cerr << "Empty for pop!!!\n";
        return -1;
    }
    return arr[size--];
}