#pragma once

// Task 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
// Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date.
// Первому присвойте значение сегодняшней даты.
// Для него вызовите по отдельности методы доступа к полям класса Date,
// а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
// Затем переместите ресурс, которым владеет указатель today в указатель date.
// Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
class Date{
private:
    int day, month, year;
public:
    Date(): day(1), month(1), year(1){}
    Date(const int _day, const int _month, const int _year):
    day(_day), month(_month), year(_year){}
    void setDay(const int _day){ day = _day; }
    void setMonth(const int _month){ month = _month; }
    void setYear(const int _year){ year = _year; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    friend std::ostream& operator<<(std::ostream& out, const Date& dat){
        out << dat.getDay() << ' ' << dat.getMonth() << ' ' << dat.getYear();
        return out;
    }
};