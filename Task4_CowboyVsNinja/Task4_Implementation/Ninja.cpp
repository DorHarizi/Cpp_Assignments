#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include <string>
#include <stdexcept>

using namespace ariel;
using namespace std;

// Constructor initializing the Ninja with a name, location, number of hits, and speed.
Ninja::Ninja(string name, Point location, int numHit, int speed):Character(name, location,numHit),speed(speed){}

// Method to move the Ninja towards an enemy character.
void Ninja::move(Character *enemy){
    // Ensuring both Ninja and enemy are alive before moving.
    if(!this->isAlive() && !enemy->isAlive())
        throw invalid_argument("The player or the enemy is dead");
    // Moving the Ninja closer to the enemy by a distance equal to the Ninja's speed.
    if((this->getLocation().getX() != enemy->getLocation().getX()) && (this->getLocation().getY() != enemy->getLocation().getY())){
        Point new_location = ariel::Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
        this->setLocation(new_location);
    }
}

// Method for the Ninja to attack an enemy character.
void Ninja::attack(Character *enemy){
    // Ensuring both Ninja and enemy are alive.
    if(!this->isAlive() || !enemy->isAlive())
        return;
    // If the Ninja is close enough (distance < 1), slash the enemy, otherwise move closer.
    if(this->distance(enemy) < 1)
        this->slash(enemy);
    else
        this->move(enemy);
}

// Method for the Ninja to slash an enemy when close enough.
bool Ninja::slash(Character *enemy) {
    // Prevent the Ninja from slashing itself.
    if(this == enemy)
        throw runtime_error("The user cant slash himself");
    // Ensure the Ninja is alive.
    if(!this->isAlive())
        throw runtime_error("The user is dead already dead");
    // Ensure the enemy is alive.
    if(!enemy->isAlive())
        throw runtime_error("The enemy is already dead");
    // If the Ninja is close enough to the enemy (distance < 1), reduce the enemy's health by 40.
    double distance = this->distance(enemy);
    if(distance < 1){
        enemy->hit(40);
        return true;
    }
    return false;
}
