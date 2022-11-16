#pragma once
#include <iostream>

// Создать класс Car (автомобиль) с полями company (компания) и model (модель).
// Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
// От этих классов наследует класс Minivan (минивэн).
// Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
// Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
// Обратить внимание на проблему «алмаз смерти».
// Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
class Car{
private:
    std::string company, model;
public:
    Car(): company(""), model("") { std::cout << "Car, "; }
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(){ std::cout << "PassengerCar, "; }
};

class Bus : virtual public Car{
public:
    Bus(){ std::cout << "Bus, "; }
};

class Minivan: public PassengerCar, public Bus{
public:
    Minivan(){ std::cout << "Minivan, "; }
};