#include "player.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace ariel;

namespace ariel {

    // Default constructor for Player class.
    Player::Player() {
        name = "";
        num_of_cards_taken = 0;
        isPlay = false;
        currentCard = 0;
    }

    // Parameterized constructor for Player class.
    Player::Player(string newName) {
        name = newName;
        num_of_cards_taken = 0;
        isPlay = false;
        currentCard = 0;
    }

    // Set the name of the player.
    void Player::setName(string newName) {
        name = newName;
    }

    // Get the total number of cards taken by the player.
    int Player::cardesTaken() {
        return num_of_cards_taken;
    }

    // Get the number of cards in the player's packet.
    int Player::stacksize() {
        return packet.size();
    }

    // Check if the player is currently playing.
    bool Player::getIsPlay() {
        return isPlay;
    }

    // Get the index of the current card being played.
    int Player::getCurrentCard() {
        return currentCard;
    }

    // Get the number of cards taken by the player.
    int Player::getNumOfCard() {
        return num_of_cards_taken;
    }

    // Set whether the player is currently playing.
    void Player::setIsPlay(bool p) {
        isPlay = p;
    }

    // Set the index of the current card being played.
    void Player::setCurrentCard(int p) {
        currentCard = p;
    }

    // Set the number of cards taken by the player.
    void Player::setNumOfCards(int p) {
        num_of_cards_taken = p;
    }

    // Add a card to the player's packet.
    void Player::putCard(Card c) {
        packet.push_back(c);
        setNumOfCards(getNumOfCard() + 1);
    }

    // Convert Player object to a string representation.
    string Player::to_string() {
        return "[Player: (" + name + ")]";
    }
}
