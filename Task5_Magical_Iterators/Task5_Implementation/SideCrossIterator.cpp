#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magical_container)
        : magical_container(magical_container), current(magical_container.container.begin()),
          forwardDirection(false), backwardIndex(1), forwardIndex(1), currentIndex(0) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    this->current = this->magical_container.container.begin();
    this->currentIndex = 0;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    this->current = this->magical_container.container.end();
    this->currentIndex = this->magical_container.size();
    return *this;
}

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


bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (==)");
    }
    return this->currentIndex == other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (!=)");
    }
    return this->currentIndex != other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (<)");
    }
    return this->currentIndex < other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't point to the same MagicalContainer (>)");
    }
    return this->currentIndex > other.currentIndex;
}

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

int MagicalContainer::SideCrossIterator::operator*() const {
    return *this->current;
}