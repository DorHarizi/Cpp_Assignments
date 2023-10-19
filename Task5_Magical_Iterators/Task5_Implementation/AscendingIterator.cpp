#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magical_container):
        magical_container(magical_container), current(magical_container.container.begin()), currentIndex(0){}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    this->current = this->magical_container.container.begin();
    this->currentIndex = 0;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    this->current = this->magical_container.container.end();
    this->currentIndex = this->magical_container.size();
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if(&this->magical_container != &other.magical_container)
    {
        throw runtime_error("The iterators don't pointer on the same MagicalContainer(=)");
    }
    this->current = other.current;
    this->currentIndex = other.currentIndex;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other)const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(==)");
    }
    return this->current == other.current;
}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(!=)");
    }
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    if (&this->magical_container != &other.magical_container) {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(<)");
    }
    return this->current < other.current;
}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    if(&this->magical_container != &other.magical_container)
    {
        throw invalid_argument("The iterators don't pointer on the same MagicalContainer(>)");
    }
    return this->current > other.current;
}

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

int MagicalContainer::AscendingIterator::operator*()const
{
    if(this->current == this->magical_container.container.end())
    {
        throw runtime_error("OutOfRange in MagicalContainer *()");
    }
    return this->magical_container.container[size_t(this->currentIndex)];
}


