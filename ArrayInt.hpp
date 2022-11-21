#pragma once

// Добавить в контейнерный класс, который был написан в этом уроке, методы:
// • для удаления последнего элемента массива (аналог функции pop_back() в векторах)
// • для удаления первого элемента массива (аналог pop_front() в векторах)
// • для сортировки массива
// • для вывода на экран элементов.
class ArrayInt{
private:
    int m_length;
    int *m_data;
public:
    // Исходный класс из урока
    ArrayInt();
    ArrayInt(int length);
    ~ArrayInt();
    void erase();
    int getLength();
    int& operator[](int index);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void push_back(int value);
    // =========================================================
    // Методы из ДЗ
    // удаление последнего элемента массива
    int pop_back();
    // удаление первого элемента массива
    int pop_front();
    // сортировкa массива
    void sort();
    // вывод элементов на экран
    void print() const;
};