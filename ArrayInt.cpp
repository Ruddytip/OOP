#include "ArrayInt.hpp"
#include <cassert> // для assert()
#include <algorithm>
#include <iostream>

ArrayInt::ArrayInt(): m_length(0), m_data(nullptr){}

ArrayInt::ArrayInt(int length): m_length(length){
    assert(length >= 0);
    if (length > 0)
    m_data = new int[length];
    else
    m_data = nullptr;
}

ArrayInt::~ArrayInt(){ delete[] m_data; }

void ArrayInt::erase(){
    delete[] m_data;
    // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
    m_data = nullptr;
    m_length = 0;
}

int ArrayInt::getLength() { return m_length; }

int& ArrayInt::operator[](int index){
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
void ArrayInt::resize(int newLength){
    // Если массив уже нужной длины — return
    if (newLength == m_length) return;
    // Если нужно сделать массив пустым — делаем это и затем return
    if (newLength <= 0){
        erase();
        return;
    }
    // Теперь знаем, что newLength >0
    // Выделяем новый массив
    int *data = new int[newLength];
    // Затем нужно разобраться с количеством копируемых элементов в новый массив
    // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
    if (m_length > 0){
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;
        // Поочередно копируем элементы
        for (int index=0; index < elementsToCopy ; ++index)
        data[index] = m_data[index];
    }
    // Удаляем старый массив, так как он нам уже не нужен
    delete[] m_data;
    // И используем вместо старого массива новый! Обратите внимание, m_data указывает
    // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
    // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
    m_data = data;
    m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index){
    // Проверка корректности передаваемого индекса
    assert(index >= 0 && index <= m_length);
    // Создаем новый массив на один элемент больше старого массива
    int *data = new int[m_length+1];
    // Копируем все элементы до index-а
    for (int before=0; before < index; ++before)
    data[before] = m_data[before];
    // Вставляем новый элемент в новый массив
    data [index] = value;
    // Копируем все значения после вставляемого элемента
    for (int after=index; after < m_length; ++after)
    data[after+1] = m_data[after];
    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::push_back(int value) { insertBefore(value, m_length); }

// Методы из ДЗ
// ==============================================================================

int ArrayInt::pop_back(){
    if(m_length == 0) return -1;
    int out = m_data[m_length - 1];
    if(m_length == 1){
        erase();
    }else{
        int newLength = m_length - 1;
        int* newPtr = new int[newLength];
        for(unsigned int i = 0; i < newLength; ++i)
            newPtr[i] = m_data[i];
        delete[] m_data;
        m_data = newPtr;
        m_length = newLength;
    }
    return out;
}

int ArrayInt::pop_front(){
    if(m_length == 0) return -1;
    int out = m_data[0];
        if(m_length == 1){
        erase();
    }else{
        int newLength = m_length - 1;
        int* newPtr = new int[newLength];
        for(unsigned int i = 0; i < newLength; ++i)
            newPtr[i] = m_data[i + 1];
        delete[] m_data;
        m_data = newPtr;
        m_length = newLength;
    }
    return out;
}

void ArrayInt::sort(){
    // Вроде как не запрещалось использовать std::sort
    std::sort(&(m_data[0]), &(m_data[m_length]));
}

void ArrayInt::print() const{
    std::cout << "Array: ";
    for(unsigned int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << ' ';
    std::cout << std::endl;
}