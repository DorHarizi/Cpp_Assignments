#include "MagicalContainer.hpp"
#include <cmath>

using namespace ariel;
using namespace std;


MagicalContainer::MagicalContainer()= default;

MagicalContainer::~MagicalContainer() {
    this->container.clear();
}

bool MagicalContainer::isPrime(int number) {
    if (number <= 1)
        return false;

    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (number % i == 0)
            return false;
    }

    return true;
}


void MagicalContainer::addElement(int element) {
    this->container.push_back(element);
    std::sort(this->container.begin(), this->container.end());
    this->primeContainer.clear();
    for(auto it = this->container.begin(); it != this->container.end(); ++it){
        if(isPrime(*it))
            this->primeContainer.push_back(&(*it));
    }
}

int MagicalContainer::size() {
    return int(this->container.size());
}

void MagicalContainer::removeElement(int element) {
    auto it = std::find(container.begin(), container.end(), element);
    if(it == this->container.end())
        throw runtime_error("The user try access to non element in remove element");
    container.erase(it);
    primeContainer.erase(std::remove(primeContainer.begin(), primeContainer.end(), &(*it)), primeContainer.end());
}



