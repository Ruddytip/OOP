#pragma once
#include <string>

// Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
// У Fruit есть две переменные-члена: name (имя) и color (цвет).
// Добавить новый класс GrannySmith, который наследует класс Apple.
class Fruit{
private:
    std::string name, color;
public:
    Fruit();
    Fruit(const std::string& _name, const std::string& _color);
    std::string getName();
    std::string getColor();
};

class Apple : public Fruit{
public:
    Apple();
    Apple(const std::string& _color);
    Apple(const std::string& _name, const std::string& _color);
};

class Banana : public Fruit{
public:
    Banana();
};

class GrannySmith : public Apple{
public:
    GrannySmith();
};