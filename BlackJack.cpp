#include "Blackjack.hpp"
// Card ===============================================================================================
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

    return face;
}

// Card ===============================================================================================

// Hand ===============================================================================================

void Hand::add(const Card _card){
    cards.push_back(_card);
}

void Hand::clear(){
    if(cards.size() == 0) return;
    cards.clear();
}

int Hand::GetValue() const{
    int out = 0;
    for(unsigned int i = 0; i < cards.size(); ++i){
        int dir = cards[i].GetValue();
        // 1  - стандартное значение карты туз
        // 21 - если сумма очковкарт в руке меньше 21, то значение карты туз равно 11
        if(dir == 1 && out < 21) dir = 11;
        out+=dir;
    }
    return out;
}

// Hand ===============================================================================================