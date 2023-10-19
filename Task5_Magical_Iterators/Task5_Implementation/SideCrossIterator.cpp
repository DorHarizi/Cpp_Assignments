#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

// Constructor: Initializes the SideCrossIterator, setting the direction to forward and indexes accordingly.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magical_container)
        : magical_container(magical_container), current(magical_container.container.begin()),
          forwardDirection(false), backwardIndex(1), forwardIndex(1), currentIndex(0) {}

// Destructor: No specific cleanup is performed.
MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

// begin Function: Resets the iterator to the start of the MagicalContainer.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    this->current = this->magical_container.container.begin();
    this->currentIndex = 0;
    return *this;
}

// end Function: Sets the iterator to one past the last element in the MagicalContainer.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    this->current = this->magical_container.container.end();
    this->currentIndex = this->magical_container.size();
    return *this;
}

// Assignment Operator: Ensures that both iterators point to the same MagicalContainer before assigning.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (&this->magical_container != &other.magical_container) {
        throw runtime_error("The iterators don't point to the same MagicalContainer (=)");
    }
    this->current = other.current;
    this->forwardDirection = other.forwardDirection;
    this->backwardIndex = other.backwardIndex;
    this->forwardIndex = other.forwardIndex;
    this->currentIndex = other.currentIndex;
    return *this;
}

// Equality Operator: Compares two iterators for equality, ensuring they point to the same element in the same MagicalContainer.
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (==)");
    }
    return this->currentIndex == other.currentIndex;
}

// Inequality Operator: Determines if two iterators point to different elements or different MagicalContainers.
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (!=)");
    }
    return this->currentIndex != other.currentIndex;
}

// Less Than Operator: Compares two iterators to see if one points to an element that appears before the other in the MagicalContainer.
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (<)");
    }
    return this->currentIndex < other.currentIndex;
}

// Greater Than Operator: Compares two iterators to see if one points to an element that appears after the other in the MagicalContainer.
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (>)");
    }
    return this->currentIndex > other.currentIndex;
}

// Prefix Increment Operator: Moves the iterator in a zig-zag manner (forward and backward) through the MagicalContainer.
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(this->current == this->magical_container.container.end())
    {
        throw runtime_error("OutOfRange in MagicalContainer(++)");
    }
    if((this->forwardIndex + this->backwardIndex) <= this->magical_container.size()){
        if(this->forwardDirection){
            this->current = this->magical_container.container.begin() + this->forwardIndex;
            this->currentIndex = this->forwardIndex;
            this->forwardIndex += 1;
            this->forwardDirection = false;
            return *this;
        }
        else
        {
            this->current = this->magical_container.container.end() - this->backwardIndex;
            this->currentIndex = this->magical_container.size() - this->backwardIndex;
            this->backwardIndex += 1;
            this->forwardDirection = true;
            return *this;
        }
    }
    this->current = this->magical_container.container.end();
    this->currentIndex = this->magical_container.size();
    this->forwardIndex = 1;
    this->backwardIndex = 1;
    this->forwardDirection = false;
    return *this;
}

// Dereference Operator: Gives access to the element that the iterator currently points to in the MagicalContainer.
int MagicalContainer::SideCrossIterator::operator*() const {
    return *this->current;
}
