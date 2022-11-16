#include "Blackjack.hpp"

Card::Card(const unsigned short _face, const unsigned char _suit):
face(_face), suit(_suit), dir(false){}

void Card::Flip(){ dir = !dir; }

unsigned short Card::GetValue() const {
    // Я решил использовать свич, так как инчае пришлось бы добовлять лишную переменную в класс карты,
    // чтобы отличать номинал карты, и её стоимость в очках
    switch (face){
        // Согласно правилам:
        // От 2 до 10 считается, как номинал карт.
        // Валет, дама, король – это 10 очков
        case jack:
        case queen:
        case king:
            return 10;
        break;
        // Туз – 1 или 11. Если сумма всех карт не превышает 21, считается как 11. Во всех остальных случаях – 1
        // По ТЗ туз равен 1
        case ace:
            return 1;
        break;
    }

    return 0;
}