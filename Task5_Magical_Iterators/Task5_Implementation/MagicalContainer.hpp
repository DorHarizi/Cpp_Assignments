#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

namespace ariel {
    class MagicalContainer {
    private:
        vector<int> container;  // A vector to hold integers.
        vector<int*> primeContainer;  // A vector to hold pointers to prime numbers in the container.

    public:
        MagicalContainer();  // Default constructor.
        ~MagicalContainer();  // Destructor.
        // Member functions to check prime numbers, add and remove elements, and get the size of the container.
        static bool isPrime(int number);
        void addElement(int element);
        void removeElement(int element);
        int size();

        // Nested class for AscendingIterator.
        class AscendingIterator {
        private:
            MagicalContainer& magical_container;  // Reference to the MagicalContainer object.
            vector<int>::const_iterator current;  // Iterator pointing to the current element.
            int currentIndex;  // Index of the current element.

        public:
            explicit AscendingIterator(MagicalContainer& magical_container);  // Constructor taking a MagicalContainer reference.
            ~AscendingIterator();  // Destructor.

            // Overloaded operators and member functions for iterator functionality.
            AscendingIterator& begin();
            AscendingIterator& end();
            AscendingIterator& operator=(const AscendingIterator& other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;  // Dereference operator.
            AscendingIterator& operator++();  // Pre-increment operator.
        };

        // Nested class for SideCrossIterator.
        class SideCrossIterator {
        private:
            // Similar member variables and functions as AscendingIterator, but with additional logic for bidirectional iteration.
            MagicalContainer& magical_container;
            vector<int>::const_iterator current;
            int currentIndex;
            int forwardIndex;
            int backwardIndex;
            bool forwardDirection;

        public:
            explicit SideCrossIterator(MagicalContainer& magical_container);
            ~SideCrossIterator();
            // Similar overloaded operators and member functions as AscendingIterator.
            SideCrossIterator& begin();
            SideCrossIterator& end();
            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
        };

        // Nested class for PrimeIterator.
        class PrimeIterator {
        private:
            // Similar member variables and functions as AscendingIterator, but iterating over prime numbers.
            MagicalContainer& magical_container;
            vector<int*>::const_iterator current;
            int currentIndex;

        public:
            explicit PrimeIterator(MagicalContainer& magical_container);
            ~PrimeIterator();
            // Similar overloaded operators and member functions as AscendingIterator.
            PrimeIterator& begin();
            PrimeIterator& end();
            PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
        };
    };
}
