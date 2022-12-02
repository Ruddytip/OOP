#pragma once
#include <iostream>

// Task 3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод,
// означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField,
// если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
// Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main,
// пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках

// Вспомогательный класс исключений
class ExRobot{
private:
    unsigned int codeErr;
public:
    enum{off_the_field, illigal_comand};
    ExRobot(const unsigned int _err): codeErr(_err){}
    void prinErr(){
        switch (codeErr){
        case off_the_field:  std::cerr << "The robot went out of the field!"                 << std::endl; break;
        case illigal_comand: std::cerr << "The robot was given the wrong direction command!" << std::endl; break;
        default: std::cout << "Errors 0" << std::endl; break;
        }
    }
};

// Исключение выхода за пределы поля
class OffTheField: public ExRobot{
public:
    OffTheField(): ExRobot(off_the_field){}
};

// Исключение неверного направления
class IllegalCommand: public ExRobot{
public:
    IllegalCommand(): ExRobot(illigal_comand){}
};

// Впомогательная структура поля
struct FLD{
    unsigned int sizeX, sizeY;
    FLD(unsigned int x, unsigned int y): sizeX(x), sizeY(y){}
};

class Robot{
private:
    int x, y;
    char dir;
public:
    enum{Up, Left, Down, Right};
    Robot(const int _x, const int _y, FLD& field): dir(Up){
        if(_x < 0 || _x >= field.sizeX) throw OffTheField();
        if(_y < 0 || _y >= field.sizeY) throw OffTheField();
        x = _x;
        y = _y;
    }
    void move(const char newDir, FLD& field){
        if(newDir == Up || newDir == Left || newDir == Down || newDir == Right){
            dir = newDir;
        }else{
            throw IllegalCommand();
        }
        if((newDir == Up)    && (y - 1 < 0))            throw OffTheField();
        if((newDir == Left)  && (x - 1 < 0))            throw OffTheField();
        if((newDir == Down)  && (y + 1 >= field.sizeX)) throw OffTheField();
        if((newDir == Right) && (x + 1 >= field.sizeY)) throw OffTheField();
    }
};