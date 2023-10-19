#include "MagicalContainer.hpp"
#include <cmath>

using namespace ariel;
using namespace std;

// Constructor: No specific initialization is performed other than the default.
MagicalContainer::MagicalContainer()= default;

// Destructor: Clears the container, freeing up memory and ensuring no dangling pointers exist.
MagicalContainer::~MagicalContainer() {
    this->container.clear();
}

// isPrime Function: Checks if a given number is prime.
bool MagicalContainer::isPrime(int number) {
    if (number <= 1) // Handling base case where number is 1 or negative.
        return false;

    int sqrtNumber = sqrt(number); // Getting square root to optimize the loop.
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (number % i == 0) // If any number divides evenly, it is not prime.
            return false;
    }

    return true; // If no divisors are found, it is a prime number.
}

// addElement Function: Adds an element and keeps container sorted. Updates primeContainer.
void MagicalContainer::addElement(int element) {
    this->container.push_back(element); // Adding the element to container.
    std::sort(this->container.begin(), this->container.end()); // Keeping the container sorted.

    // Clearing primeContainer and re-populating it based on updated container.
    this->primeContainer.clear();
    for(auto it = this->container.begin(); it != this->container.end(); ++it){
        if(isPrime(*it)) // If element is prime, its address is stored in primeContainer.
            this->primeContainer.push_back(&(*it));
    }
}

// size Function: Returns the number of elements in the container.
int MagicalContainer::size() {
    return int(this->container.size()); // Cast to int for safety, as size() returns size_t.
}

// removeElement Function: Removes a specific element and updates primeContainer.
void MagicalContainer::removeElement(int element) {
    auto it = std::find(container.begin(), container.end(), element); // Finding the element.

    // If element is not found, throw an exception.
    if(it == this->container.end()) 
        throw runtime_error("The user try access to non element in remove element");
    
    // Erasing element from container and its pointers from primeContainer.
    container.erase(it);
    primeContainer.erase(std::remove(primeContainer.begin(), primeContainer.end(), &(*it)), primeContainer.end());
}
