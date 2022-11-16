#pragma once
#include <ostream>

// Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
// математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
// унарный оператор (-)
// логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
// Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
// Продемонстрировать использование перегруженных операторов.
class Fraction{
private:
    int numerator, denominator;
    // Функция сокращения дроби
    void reduction(int dir);
public:
    Fraction(const int n, const int d);
    Fraction operator+(const Fraction& F);
    Fraction operator-(const Fraction& F);
    Fraction operator*(const Fraction& F);
    Fraction operator/(const Fraction& F);
    Fraction operator-() const;
    bool operator==(const Fraction& F) const;
    bool operator!=(const Fraction& F) const;
    bool operator< (const Fraction& F) const;
    bool operator> (const Fraction& F) const;
    bool operator<=(const Fraction& F) const;
    bool operator>=(const Fraction& F) const;
    friend std::ostream& operator<<(std::ostream& output, const Fraction& data){
        output << data.numerator << '/' << data.denominator;
        return output;
    }
};