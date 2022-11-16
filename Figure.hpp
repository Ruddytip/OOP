#pragma once

// Создать абстрактный класс Figure (фигура).
// Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
// Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
// Для всех классов создать конструкторы.
// Для класса Figure добавить чисто виртуальную функцию area() (площадь).
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
class Figure{
public:
    virtual double area() = 0;
};

class Circle : public Figure{
private:
    double radius;
public:
    Circle(const double _radius): radius(_radius){};
    double area() override{
        return 3.1415926535 * radius * radius;
    }
};

class Parallelogram : public Figure{
private:
    double x, y;
public:
    Parallelogram(): x(0.0), y(0.0){};
    Parallelogram(const double _x, const double _y): x(_x), y(_y){};
    double area() override{
        return (x * y);
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(const double _x, const double _y): Parallelogram(_x, _y){};
    double area() override{
        return Parallelogram::area();
    }
};

class Square : public Parallelogram{
private:
    double edge;
public:
    Square(const double _edge): edge(_edge){};
    double area() override{
        return edge * edge;
    }
};

class Rhombus : public Parallelogram{
public:
    Rhombus(const double _x, const double _y): Parallelogram(_x, _y){}
    double area() override{
        return (Parallelogram::area() / 2.0);
    }
};