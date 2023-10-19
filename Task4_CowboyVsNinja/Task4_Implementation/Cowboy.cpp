#include "Cowboy.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

// Constructor for the Cowboy object, initializing with a name, location, health (110) and number of bullets (6).
Cowboy::Cowboy(string name, Point location):Character(name, location, 110), numOfBullets(6){}

// Method to attack an enemy character.
void Cowboy::attack(Character *enemy){
    // Check if both the cowboy and the enemy are alive.
    if(!this->isAlive() || !enemy->isAlive())
        return;
    // Check if the cowboy has bullets, if not, reload.
    if(!this->hasboolets())
        this->reload();
    else
        // If cowboy has bullets, shoot the enemy.
        this->shoot(enemy);
}

// Method to shoot an enemy character.
void Cowboy::shoot(Character *enemy){
    // Ensure that the cowboy doesn't shoot himself.
    if(this == enemy)
        throw runtime_error("The user cant shoot himself");
    // Ensure that both cowboy and enemy are alive.
    if(!this->isAlive() || !enemy->isAlive())
        throw runtime_error("Error try to shoot but the cowboy is dead\n");
    // If cowboy has bullets, reduce enemy’s health and decrement bullet count.
    if(this->hasboolets()){
        enemy->hit(10);
        this->numOfBullets -= 1;
    }
}

// Method to check if the cowboy has bullets and is alive.
bool Cowboy::hasboolets(){
    if(0 < this->numOfBullets && this->isAlive()){
        return true;
    }
    return false;
}

// Method to reload the cowboy’s bullets if he's alive.
void Cowboy::reload(){
    if(!this->isAlive())
        throw runtime_error("Error try to reload but the cowboy is dead\n");
    // Reload bullets to the full count (6).
    this->numOfBullets += 6 - this->numOfBullets;
}

