
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;

TEST_CASE("MagicalContainer Tests") {
    SUBCASE("Adding and Removing Elements") {
        MagicalContainer container;

        CHECK(container.size() == 0);

        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        CHECK(container.size() == 5);

        container.removeElement(3);
        container.removeElement(10);

        CHECK(container.size() == 3);
    }

    SUBCASE("AscendingIterator Tests") {
        ariel::MagicalContainer container;

        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator it(container);

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 10);

        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it2;
        ++it2;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK((it1 < it2));
    }

    SUBCASE("PrimeIterator Tests") {
        ariel::MagicalContainer container;

        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        ariel::MagicalContainer::PrimeIterator it(container);

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);

        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it2;
        ++it2;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK((it1 < it2));
    }

    SUBCASE("SideCrossIterator Tests") {
        ariel::MagicalContainer container;

        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        ariel::MagicalContainer::SideCrossIterator it(container);

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 5);

        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it2;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK((it1 < it2));

        ++it1;
        ++it2;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK((it1 < it2));
    }
}

