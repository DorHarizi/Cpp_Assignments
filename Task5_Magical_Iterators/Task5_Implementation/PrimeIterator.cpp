#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magical_container):
        magical_container(magical_container), current(magical_container.primeContainer.begin()),
        currentIndex(0){}

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    this->current = this->magical_container.primeContainer.begin();
    this->currentIndex = 0;
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    this->current = this->magical_container.primeContainer.end();
    this->currentIndex = this->magical_container.primeContainer.size();
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if(&this->magical_container != &other.magical_container)
    {
        throw runtime_error("The iterators don't pointer on the same MagicalContainer(=)");
    }
    this->current = other.current;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other)const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(==)");
    }
    return this->currentIndex == other.currentIndex;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(!=)");
    }
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(<)");
    }
    return this->currentIndex < other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(>)");
    }
    return this->currentIndex > other.currentIndex;
}

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

int MagicalContainer::PrimeIterator::operator*()const
{
    if(this->current == this->magical_container.primeContainer.end())
    {
        throw out_of_range("OutOfRange in MagicalContainer(++)");
    }
    return *(this->magical_container.primeContainer[size_t(this->currentIndex)]);
}


