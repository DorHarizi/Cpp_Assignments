#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;

TEST_CASE("MagicalContainer Tests") {

    // Testing basic functionality: Adding and Removing elements
    SUBCASE("Adding and Removing Elements") {
        MagicalContainer container;

        // Initially, the container should be empty
        CHECK(container.size() == 0);

        // Adding elements to the container
        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        // Now, the container should have 5 elements
        CHECK(container.size() == 5);

        // Removing specific elements from the container
        container.removeElement(3);
        container.removeElement(10);

        // After removing two elements, the container size should be 3
        CHECK(container.size() == 3);
    }

    // Testing the AscendingIterator functionality
    SUBCASE("AscendingIterator Tests") {
        ariel::MagicalContainer container;

        // Adding elements to the container
        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator it(container);

        // Checking if the elements are accessed in ascending order
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

        // Comparing iterators to check equality and relational operators
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

    // Testing the PrimeIterator functionality
    SUBCASE("PrimeIterator Tests") {
        ariel::MagicalContainer container;

        // Adding elements to the container
        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        ariel::MagicalContainer::PrimeIterator it(container);

        // Checking if the iterator correctly accesses prime numbers only
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);

        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        // Comparing iterators to check equality and relational operators
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

    // Testing the SideCrossIterator functionality
    SUBCASE("SideCrossIterator Tests") {
        ariel::MagicalContainer container;

        // Adding elements to the container
        container.addElement(5);
        container.addElement(3);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        ariel::MagicalContainer::SideCrossIterator it(container);

        // Checking if the iterator correctly accesses elements in a cross order
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

        // Comparing iterators to check equality and relational operators
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
