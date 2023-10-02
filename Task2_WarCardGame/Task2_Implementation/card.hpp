#pragma once

#include <string>
#include<iostream>
using namespace std;

namespace ariel {

    // Card class represents a playing card.
    class Card {
    private:
        int value;    // The numeric value of the card (e.g., 2, 3, 4).
        string type;  // The type or suit of the card (e.g., Hearts, Diamonds).
        string name;  // The name of the card (e.g., Ace, King, Queen).

    public:
        // Default constructor for Card class.
        Card();

        // Parameterized constructor for Card class.
        Card(int newValue, string newType, string newName);

        // Getter function for card value.
        int getValue();

        // Getter function for card type.
        string getType();

        // Getter function for card name.
        string getName();

        // Setter function for card value.
        void setValue(int newValue);

        // Setter function for card type.
        void setType(string newType);

        // Setter function for card name.
        void setName(string newName);

        // Less than operator for Card comparison.
        bool operator<(const Card& Card2);

        // Equality operator for Card comparison.
        bool operator==(const Card& Card2);

        // Convert Card object to a string representation.
        string to_string();
    };
}
