#pragma once
#include <string>

// Изучить правила игры в Blackjack.
// Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
// Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
// Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.

// Игровая карта
class Card{
private:
    // Название карты
    std::string name;
    // Значение в виде очков
    unsigned short faceValue;
    // Масть карты
    unsigned char suit;
public:
};

// Колода карт
class Deck{
private:
    // Размер текущей колоды
    unsigned int size;
    // Сама колода карт, скорее всего реализую в виде стека
    Card* cards;
public:
    // Выдаёт карту из колоды
    Card IssueCard();
    // Перетасовка колоды
    void Shuffle();
    // Заполняет колоду картами
    void recoil();
};

// Карты в руке (по сути мини-колода)
class Hand : public Deck{
private:

public:
    // Добавляет карту
    void addCard(const Card _card);
    // Очищает руку
    void clear();
};

class Player{
private:
    // Текущее кол-во денег
    unsigned int money;
    // Текущая ставка
    unsigned int betOnTable;
    Hand hand;
public:
    // Возвращает значение ставки игрока
    unsigned int getBet();
    // Награждает игрока кол-вом денег, равную ставке умноженной на коэффициент
    void win(const int cof);
    // Изымает у игрока кол-во денег, равную его ставке
    void loss();
    // Решение брать или не брать карту
    void askCard();
};

class Table{
private:
    // Крупье
    Player crup;
    // Колода
    Deck deck;
    // Кол-во игроков
    unsigned int countPlayers;
    // Игроки
    Player* players;

public:
    // Выполнение цикла игры
    void makeMove();
    // Проверка каждого игрока на победу или проигрыш
    void Check();
};