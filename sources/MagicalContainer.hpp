#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

namespace ariel{
class MagicalContainer {
  private: 
    std::vector<int> elements;         // all the numbers in container
    std::vector<int> primeElem;        // only the prime numbers in container


  public:
    MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int size();
    bool isPrime(int number);

    class AscendingIterator {
      private:
        MagicalContainer* container;
        size_t index;

        public:
        AscendingIterator();
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();

        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();

        AscendingIterator begin();
        AscendingIterator end();
        };

    class SideCrossIterator {
      private:
        MagicalContainer* container;
        size_t index;
        size_t crossIter;           // for operator * - using for returning value in the current index

      public:
        SideCrossIterator();
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();

        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();

        SideCrossIterator begin();
        SideCrossIterator end();


        };

    class PrimeIterator{
      private:
        MagicalContainer* container;
        size_t index;

      public:
        PrimeIterator();
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();

        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();
            
        PrimeIterator begin();
        PrimeIterator end();

        };  
    };
}
#endif
