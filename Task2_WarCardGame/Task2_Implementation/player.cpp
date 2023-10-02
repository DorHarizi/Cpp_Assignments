#include "player.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace ariel;

namespace ariel{

    Player::Player(){
                name = "";
                num_of_cards_taken = 0;
                isPlay = false;
                currentCard = 0;
    }

    Player::Player(string newName) {
        name = newName;
        num_of_cards_taken = 0;
        isPlay = false;
        currentCard = 0;
    }

    void Player::setName(string newName) {
        name = newName;
    }

    int Player::cardesTaken(){
        return num_of_cards_taken;
    }

    int Player::stacksize(){
        return num_of_cards_taken;
    }

    bool Player::getIsPlay(){
        return isPlay;
        }
    int Player::getCurrentCard(){return currentCard;}
    int Player::getNumOfCard(){return num_of_cards_taken;}
    void Player::setIsPlay(bool p){
        isPlay = p;
    }
    void Player::setCurrentCard(int p){
        currentCard = p;
    }
    void Player::setNumOfCards(int p){
        num_of_cards_taken = p;
    }
    void Player::putCard(Card c){
        packet.push_back(c);
        setNumOfCards(getNumOfCard()+1);
    }
    string Player::to_string() {
        // [player: ("dor")]
        return "[Player: ("+name+")]";
    }
}