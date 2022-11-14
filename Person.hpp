#pragma once
#include <string>

// Создать класс Person (человек) с полями: имя, возраст, пол и вес.
// Определить методы переназначения имени, изменения возраста и веса.
// Создать производный класс Student (студент), имеющий поле года обучения.
// Определить методы переназначения и увеличения этого значения.
// Создать счетчик количества созданных студентов.
// В функции main() создать несколько (не больше трёх) студентов.
// Вывести информацию о них
class Person{
private:
    std::string name;
    unsigned int age;
    char gender;
    unsigned int weight;
public:
    Person(const std::string& _name, const unsigned int _age, const char _gender, const unsigned int _weight);
    ~Person();
    void setName(const std::string& _name);
    void setAge(const unsigned int _age);
    void setGender(const char _gender);
    void setWeight(const unsigned int _weight);
    void printInfo();
};

class Student : public Person{
private:
    unsigned int year;
    static unsigned int countStudents;
public:
    Student(const std::string& _name, const unsigned int _age, const char _gender, const unsigned int _weight, const unsigned int _year);
    ~Student();
    void setYear(const unsigned _year);
    void increasingYear(const unsigned _number);
    void printInfo();
};