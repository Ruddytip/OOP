#include "Fruit.hpp"

Fruit::Fruit(): name("None"), color("None"){}

Fruit::Fruit(const std::string& _name, const std::string& _color):
name(_name), color(_color){}

std::string Fruit::getName(){return name;}

std::string Fruit::getColor(){return color;}

Apple::Apple(): Fruit("apple", "red"){}

Apple::Apple(const std::string& _color): Fruit("apple", _color){}

Apple::Apple(const std::string& _name, const std::string& _color):
Fruit(_name, _color){}

Banana::Banana(): Fruit("banana", "yellow"){}

GrannySmith::GrannySmith(): Apple("Granny Smith apple", "green"){}