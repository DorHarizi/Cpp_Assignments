#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

// PrimeIterator Constructor: Initializes the iterator to point to the first prime element in the MagicalContainer.
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magical_container):
        magical_container(magical_container), current(magical_container.primeContainer.begin()),
        currentIndex(0){}

// PrimeIterator Destructor: No specific cleanup is performed.
MagicalContainer::PrimeIterator::~PrimeIterator() = default;

// begin Function: Resets the iterator to point to the first prime element in the MagicalContainer.
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    this->current = this->magical_container.primeContainer.begin();
    this->currentIndex = 0;
    return *this;
}

// end Function: Sets the iterator to one past the last prime element in the MagicalContainer.
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    this->current = this->magical_container.primeContainer.end();
    this->currentIndex = this->magical_container.primeContainer.size();
    return *this;
}

// Assignment Operator: Ensures that both iterators point to the same MagicalContainer before assigning.
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if(&this->magical_container != &other.magical_container)
    {
        throw runtime_error("The iterators don't pointer on the same MagicalContainer(=)");
    }
    this->current = other.current;
    return *this;
}

// Equality Operator: Compares two iterators for equality, ensuring they point to the same element in the same MagicalContainer.
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other)const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(==)");
    }
    return this->currentIndex == other.currentIndex;
}

// Inequality Operator: Determines if two iterators point to different elements or different MagicalContainers.
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(!=)");
    }
    return !(*this == other);
}

// Less Than Operator: Compares two iterators to see if one points to an element that appears before the other in the MagicalContainer.
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(<)");
    }
    return this->currentIndex < other.currentIndex;
}

// Greater Than Operator: Compares two iterators to see if one points to an element that appears after the other in the MagicalContainer.
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(>)");
    }
    return this->currentIndex > other.currentIndex;
}

// Prefix Increment Operator: Moves the iterator to the next prime element in the MagicalContainer.
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if(this->current == this->magical_container.primeContainer.end())
    {
        throw runtime_error("OutOfRange in MagicalContainer(++)");
    }
    ++this->current;
    ++this->currentIndex;
    return *this;
}

// Dereference Operator: Gives access to the prime element that the iterator currently points to in the MagicalContainer.
int MagicalContainer::PrimeIterator::operator*()const
{
    if(this->current == this->magical_container.primeContainer.end())
    {
        throw out_of_range("OutOfRange in MagicalContainer(++)");
    }
    return *(this->magical_container.primeContainer[size_t(this->currentIndex)]);
}
