#pragma once

#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{
    class Cowboy : public Character {
    private:
        int numOfBullets; // Number of bullets the Cowboy has

    public:
        // Constructor initializing Cowboy with name, location, and default bullets
        Cowboy(string name, Point location);

        // Shoot function decreases bullet count and applies damage to target
        void shoot(Character *tmp);

        // Check if Cowboy has bullets left
        bool hasboolets();

        // Reload function replenishes Cowboy's bullets
        void reload();

        // Override attack function to implement Cowboy's attack mechanism
        void attack(Character *enemy) override;
    };
}
