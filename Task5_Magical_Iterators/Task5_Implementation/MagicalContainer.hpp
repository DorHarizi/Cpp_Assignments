#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

namespace ariel{
    class MagicalContainer
    {
    private:
        vector<int> container;
        vector<int*> primeContainer;

    public:
        MagicalContainer();
        ~MagicalContainer();
//        MagicalContainer(const MagicalContainer& other) = default;
//        MagicalContainer& operator=(const MagicalContainer& other) {return *this;}
        static bool isPrime(int number);
        void addElement(int element);
        void removeElement(int element);
        int size();

        class AscendingIterator {
        private:
            MagicalContainer& magical_container;
            vector<int>::const_iterator current;
            int currentIndex;

        public:
            explicit AscendingIterator(MagicalContainer& magical_container);
            ~AscendingIterator();
//            AscendingIterator &operator=(const AscendingIterator &other);                      // Copy assignment operator
//            AscendingIterator(AscendingIterator &&other) noexcept = default;                   // Move constructor
//            AscendingIterator &operator=(AscendingIterator &&other) noexcept { return *this; } // Move assignment operator
            AscendingIterator& begin();
            AscendingIterator& end();
            AscendingIterator& operator=(const AscendingIterator& other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
        };

        class SideCrossIterator {
        private:
            MagicalContainer& magical_container;
            vector<int>::const_iterator current;
            int currentIndex;
            int forwardIndex;
            int backwardIndex;
            bool forwardDirection;

        public:
            explicit SideCrossIterator(MagicalContainer& magical_container);
            ~SideCrossIterator();
//            SideCrossIterator &operator=(const SideCrossIterator &other);                      // Copy assignment operator
//            SideCrossIterator(SideCrossIterator &&other) noexcept = default;                   // Move constructor
//            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept { return *this; } // Move assignment operator
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

        class PrimeIterator {
        private:
            MagicalContainer& magical_container;
            vector<int*>::const_iterator current;
            int currentIndex;

        public:
            explicit PrimeIterator(MagicalContainer& magical_container);
            ~PrimeIterator();
//            PrimeIterator &operator=(const PrimeIterator &other);                      // Copy assignment operator
//            PrimeIterator(PrimeIterator &&other) noexcept = default;                   // Move constructor
//            PrimeIterator &operator=(PrimeIterator &&other) noexcept { return *this; } // Move assignment operator
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
