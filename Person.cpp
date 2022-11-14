#include "Person.hpp"
#include <iostream>

unsigned int Student::countStudents = 0;

Person::Person(const std::string& _name, const unsigned int _age, const char _gender, const unsigned int _weight):
name(_name), age(_age), gender(_gender), weight(_weight){}

Person::~Person(){}

void Person::setName(const std::string& _name){name = _name;}

void Person::setAge(const unsigned int _age){age = _age;}

void Person::setGender(const char _gender){gender = _gender;}

void Person::setWeight(const unsigned int _weight){weight = _weight;}

void Person::printInfo(){
    std::cout << "Name - "   << name   << std::endl;
    std::cout << "Age - "    << age    << std::endl;
    std::cout << "Gender - " << gender << std::endl;
    std::cout << "Weight - " << weight << std::endl;
}

Student::Student(const std::string& _name, const unsigned int _age, const char _gender, const unsigned int _weight, const unsigned int _year):
Person(_name, _age, _gender, _weight), year(_year){
    countStudents++;
}

Student::~Student(){
    countStudents--;
}

void Student::setYear(const unsigned _year){year = _year;}

void Student::increasingYear(const unsigned _number){year+=_number;}

void Student::printInfo(){
    Person::printInfo();
    std::cout << "Year - " << year << std::endl;
    std::cout << "Counts students - " << countStudents << std::endl;
    std::cout << std::endl;
}