#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

namespace ariel{
class MagicalContainer {
  private:
    std::vector<int> elements;  

  public:
    MagicalContainer();

    void addElement(int element);
    void removeElement(int element);
    int size();
    std::vector<int> getElements() const; 


    class AscendingIterator {
      private:
        MagicalContainer& container;
        int index;

        public:
        AscendingIterator(MagicalContainer& container, int index);
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();

        AscendingIterator() = delete; 
        AscendingIterator(AscendingIterator&&) = delete;
        AscendingIterator& operator=(AscendingIterator&&) = delete;

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
        MagicalContainer& container;
        int index;
        bool isEnd;


      public:
        SideCrossIterator(MagicalContainer& container, int index, bool isEnd);
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();

        SideCrossIterator() = delete; 
        SideCrossIterator(SideCrossIterator&&) = delete;
        SideCrossIterator& operator=(SideCrossIterator&&) = delete;

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
        MagicalContainer& container;
        int index;
        static bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }


      public:
        PrimeIterator(MagicalContainer& container, int index);
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();

        PrimeIterator() = delete; 
        PrimeIterator(PrimeIterator&&) = delete;
        PrimeIterator& operator=(PrimeIterator&&) = delete;

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
