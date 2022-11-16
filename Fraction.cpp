#include "Fraction.hpp"

void Fraction::reduction(int dir){
    if(numerator == 1 || denominator == 1) return;
    if(dir > numerator || dir > denominator) return;
    if((numerator % dir == 0) && (denominator % dir == 0)){
        numerator/=dir;
        denominator/=dir;
        dir = 2;
    }
    reduction(dir + 1);
}

Fraction::Fraction(const int n, const int d):
numerator(n), denominator(d){ denominator = (denominator == 0 ? 1 : denominator); reduction(2);}

Fraction Fraction::operator+(const Fraction& F) {
    int n = (numerator * F.denominator) + (F.numerator * denominator);
    int d = denominator * F.denominator;
    numerator = n;
    denominator = d;
    reduction(2);
    return *this;
}

Fraction Fraction::operator-(const Fraction& F){
    int n = (numerator * F.denominator) - (F.numerator * denominator);
    int d = denominator * F.denominator;
    numerator = n;
    denominator = d;
    reduction(2);
    return *this;
}

Fraction Fraction::operator*(const Fraction& F){
    int n = numerator * F.numerator;
    int d = denominator * F.denominator;
    numerator = n;
    denominator = d;
    reduction(2);
    return *this;
}

Fraction Fraction::operator/(const Fraction& F){
    int n = numerator * F.denominator;
    int d = denominator * F.numerator;
    numerator = n;
    denominator = d;
    reduction(2);
    return *this;
}

Fraction Fraction::operator-() const{
    return Fraction(-numerator, denominator);
}

bool Fraction::operator==(const Fraction& F) const{
    if(numerator == F.numerator && denominator == F.denominator) return true;
        else return false;
}

bool Fraction::operator!=(const Fraction& F) const{
    return !(*this == F);
}

bool Fraction::operator< (const Fraction& F) const{
    int n1 = (numerator * F.denominator);
    int n2 = (F.numerator * denominator);
    return (n1 < n2);
}

bool Fraction::operator> (const Fraction& F) const{
    int n1 = (numerator * F.denominator);
    int n2 = (F.numerator * denominator);
    return (n1 > n2);
}

bool Fraction::operator<=(const Fraction& F) const{
    return !(*this > F);
}

bool Fraction::operator>=(const Fraction& F) const{
    return !(*this < F);
}
