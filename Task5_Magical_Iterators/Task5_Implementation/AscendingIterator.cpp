#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

// AscendingIterator Constructor: Initializes iterator to point at the beginning of the MagicalContainer.
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magical_container):
        magical_container(magical_container), current(magical_container.container.begin()), currentIndex(0){}

// AscendingIterator Destructor: No specific cleanup is performed.
MagicalContainer::AscendingIterator::~AscendingIterator() = default;

// begin Function: Resets the iterator to the start of the MagicalContainer.
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    this->current = this->magical_container.container.begin();
    this->currentIndex = 0;
    return *this;
}

// end Function: Sets the iterator to one past the last element in the MagicalContainer.
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    this->current = this->magical_container.container.end();
    this->currentIndex = this->magical_container.size();
    return *this;
}

// Assignment Operator: Assigns one iterator's state to another, ensuring they point to the same MagicalContainer.
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if(&this->magical_container != &other.magical_container)
    {
        throw runtime_error("The iterators don't pointer on the same MagicalContainer(=)");
    }
    this->current = other.current;
    this->currentIndex = other.currentIndex;
    return *this;
}

// Equality Operator: Checks whether two iterators are at the same position in the same MagicalContainer.
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other)const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(==)");
    }
    return this->current == other.current;
}

// Inequality Operator: Checks whether two iterators are at different positions or in different MagicalContainers.
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(!=)");
    }
    return !(*this == other);
}

// Less Than Operator: Compares positions of two iterators in the same MagicalContainer.
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(<)");
    }
    return this->current < other.current;
}

// Greater Than Operator: Compares positions of two iterators in the same MagicalContainer.
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(>)");
    }
    return this->current > other.current;
}

// Prefix Increment Operator: Moves the iterator one position forward in the MagicalContainer.
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(this->current == this->magical_container.container.end())
    {
        throw runtime_error("OutOfRange in MagicalContainer(++)");
    }
    this->currentIndex += 1;
    ++this->current;
    return *this;
}

// Dereference Operator: Gives access to the element the iterator currently points to.
int MagicalContainer::AscendingIterator::operator*()const
{
    if(this->current == this->magical_container.container.end())
    {
        throw runtime_error("OutOfRange in MagicalContainer *()");
    }
    return this->magical_container.container[size_t(this->currentIndex)];
}

