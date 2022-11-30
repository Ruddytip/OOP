#include "Blackjack.hpp"
#include <algorithm>

// Card ===============================================================================================
Card::Card(const unsigned short _face, const unsigned char _suit):
face(_face), suit(_suit), dir(true){}
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
bool Card::getDir() const{ return dir; }
// Card ===============================================================================================

// Hand ===============================================================================================
void Hand::add(const Card _card){ cards.push_back(_card); }
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

// GenericPlayer ======================================================================================
GenericPlayer::GenericPlayer(const std::string _name): name(_name){}
bool GenericPlayer::IsBoosted() const{ return (Hand::GetValue() > 21 ? true : false); }
void GenericPlayer::Bust() const{ std::cout << "The player " << name << " has too many points!" << std::endl; }
// GenericPlayer ======================================================================================

// Player =============================================================================================
Player::Player(const std::string _name): GenericPlayer(_name){}
bool Player::IsHitting() const{
    std::cout << "Do you want to take another card?(y/n)";
    while(true){
        std::string str = "";
        std::getline(std::cin, str);
        if(str.length() == 1 && (str[0] == 'y' || str[0] == 'n')){
            return ((str[0] == 'y') ? true : false);
        } else{
            std::cerr << "Error input!!!" << std::endl;
            std::cout << "Try again: ";
        }
    }
}
void Player::Win() const{ std::cout << "The player " << name << " won!" << std::endl; }
void Player::Lose() const{ std::cout << "The player " << name << " lost!" << std::endl; }
void Player::Push() const{ std::cout << "The player " << name << " drew!" << std::endl; }
// Player =============================================================================================

// House ==============================================================================================
House::House(const std::string _name): GenericPlayer(_name){}
bool House::IsHitting() const{ return ((Hand::GetValue() < 16) ? true : false); }
void House::FlipFirstCard(){
    // 1. Если всегда переворачивается только первая карта
    // cards[0].Flip();
    // 2. Если переворачивается первая неперевёрнутая карта
    for(unsigned int i = 0; i < cards.size(); ++i){
        if(!(cards[i].getDir())){
            cards[i].Flip();
            break;
        }
    }
}
// House ==============================================================================================

// Deck ===============================================================================================
Deck::Deck(){ Populate(); Shuffle(); }
void Deck::Populate(){
    for(unsigned j = 0; j < 4; ++j)
        for(unsigned int i = 1; i <= 13; ++i){
            Card c(i, j);
            cards.push_back(c);
        }
}
void Deck::Shuffle(){ std::random_shuffle(cards.begin(), cards.end()); }
void Deck::Deal(Hand& aHand){
    aHand.add(*cards.end());
    cards.pop_back();
}
void Deck::AddltionalCards(GenericPlayer& aGenerlcPlayer){
    while(!aGenerlcPlayer.IsBoosted() && aGenerlcPlayer.IsHitting()) Deal(aGenerlcPlayer);
    if(aGenerlcPlayer.GetValue() > 21) aGenerlcPlayer.Bust();    
}
// Deck ===============================================================================================

// Game ===============================================================================================
Game::Game(std::vector<std::string> names){
    for(unsigned int i = 0; i < names.size(); ++i){
        players.push_back(Player(names[i]));
    }
}
Game::~Game(){ players.clear(); }
// В этом методе раздаются каждому игроку по две стартовые карты,
// а первая карта дилера прячется. Далее выводится на экран информация о картах каждого игра, в т.ч. и для дилера.
// Затем раздаются игрокам дополнительные карты. Потом показывается первая карта дилера и дилер набирает карты, если ему надо.
// После этого выводится сообщение, кто победил, а кто проиграл. В конце руки всех игроков очищаются
void Game::play(){
    House house("Crup");
    deck.Deal(house);
    deck.Deal(house);
    house.FlipFirstCard();
    std::cout << house << std::endl;

    for(unsigned int i = 0; i < players.size(); ++i){
        deck.Deal(players[i]);
        deck.Deal(players[i]);
        std::cout << players[i] << std::endl;
    }

    for(unsigned int i = 0; i < players.size(); ++i)
        deck.AddltionalCards(players[i]);

    house.FlipFirstCard();
    deck.AddltionalCards(house);

    std::cout << house << std::endl;
    for(unsigned int i = 0; i < players.size(); ++i){
        std::cout << players[i];
        if(players[i].GetValue() == 21){
                players[i].Win();
        }else if(players[i].IsBoosted()){
            players[i].Lose();
        }else if(players[i].GetValue() > house.GetValue()){
            players[i].Win();
        }else{
            players[i].Lose();
        }
        std::cout << std::endl;
    }
}
// Game ===============================================================================================