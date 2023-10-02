#pragma once

#include <string>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel {

    // Player class represents a player in the card game.
    class Player {
    private:
        string name;              // The name of the player.
        vector<Card> packet;     // The player's packet of cards.
        bool isPlay;             // Flag indicating if the player is currently playing.
        int currentCard;         // Index of the current card being played.
        int num_of_cards_taken;  // Number of cards taken by the player.

    public:
        // Default constructor for Player class.
        Player();

        // Parameterized constructor for Player class.
        Player(string playerName);

        // Getter function for player name.
        string getName() { return name; }

        // Getter function for player's packet of cards.
        vector<Card> getPacket() { return packet; }

        // Get the total number of cards taken by the player.
        int cardesTaken();

        // Get the number of cards in the player's packet.
        int stacksize();

        // Check if the player is currently playing.
        bool getIsPlay();

        // Get the index of the current card being played.
        int getCurrentCard();

        // Get the number of cards taken by the player.
        int getNumOfCard();

        // Set whether the player is currently playing.
        void setIsPlay(bool isPlaying);

        // Set the index of the current card being played.
        void setCurrentCard(int current);

        // Set the number of cards taken by the player.
        void setNumOfCards(int numTaken);

        // Set the name of the player.
        void setName(string playerName);

        // Add a card to the player's packet.
        void putCard(Card newCard);

        // Convert Player object to a string representation.
        string to_string();
    };
}
