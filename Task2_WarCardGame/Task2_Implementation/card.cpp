#include "card.hpp"
#include <string>
#include<iostream>

using namespace std;
using namespace ariel;

namespace ariel {

    // Default constructor for Card class.
    Card::Card() {
        value = 0;
        type = "";
        name = "";
    }

    // Parameterized constructor for Card class.
    Card::Card(int newValue, string newType, string newName) {
        value = newValue;
        type = newType;
        name = newName;
    }

    // Getter function for card value.
    int Card::getValue() { return value; }

    // Getter function for card type.
    string Card::getType() { return type; }

    // Getter function for card name.
    string Card::getName() { return name; }

    // Setter function for card value.
    void Card::setValue(int newValue) {
        value = newValue;
    }

    // Setter function for card type.
    void Card::setType(string newType) {
        type = newType;
    }

    // Setter function for card name.
    void Card::setName(string newName) {
        name = newName;
    }

    // Less than operator for Card comparison.
    bool Card::operator<(const Card& Card2) { return this->value < Card2.value; }

    // Equality operator for Card comparison.
    bool Card::operator==(const Card& Card2) { return this->value == Card2.value; }

    // Convert Card object to a string representation.
    string Card::to_string() {
        string str = std::to_string(value);
        // Example: [Card: ("Queen", Diamonds, 12)]
        return "[Card: (" + name + "," + type + "," + str + ")]";
    }
}
