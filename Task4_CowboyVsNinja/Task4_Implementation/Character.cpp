#include "Character.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

// Constructor initializing with name, location, and hit count
Character::Character(string name, Point location, int numOfHit)
: name(name), location(location), numOfHit(numOfHit){
    this->setInTeam(false);
}

// Getter for character's name
string Character::getName(){
    return this->name;
}

// Getter for inTeam status
bool Character::getInTeam() {
    return this->inTeam;
}

// Getter for character's location
Point Character::getLocation(){
    return this->location;
}

// Getter for hit count
int Character::getNumOfHit() {
    return this->numOfHit;
}

// Setter for character's name
void Character::setName(string name){
    this->name = name;
}

// Setter for character's location
void Character::setLocation(Point location){
    this->location = location;
}

// Setter for inTeam status
void Character::setInTeam(bool tmp) {
    this->inTeam = tmp;
}

// Function checking if character is alive
bool Character::isAlive() const{
    return (0 < this->numOfHit);
}

// Calculate distance to another character
double Character::distance(Character *element){
    return this->location.distance(element->getLocation());
}

// Reduces hit count by Hit, throws if Hit is non-positive
void Character::hit(int Hit){
    if(Hit <= 0)
        throw invalid_argument("The user hit negative number");
    this->numOfHit = max(0, this->numOfHit - Hit);
}

// Attack function (To be implemented)
void Character::attack(ariel::Character *tmp) {}

// Returns string representation of character
string Character::print(){
    return (0 < this->numOfHit) ? 
           "name: " + this->name + " Hit: " + to_string(this->numOfHit) + " location: " + this->getLocation().print() :
           "name: (" + this->name + ")";
}
