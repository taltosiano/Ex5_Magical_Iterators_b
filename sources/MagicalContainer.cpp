#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace ariel;

   MagicalContainer::MagicalContainer() {}
    
    void MagicalContainer::addElement(int element) {
         //find the first place in the range which has a value bigger than the element
        auto it = upper_bound(this->elements.begin(), this->elements.end(), element);
        this->elements.insert(it, element);  
        auto itPrime = upper_bound(this->primeElem.begin(), this->primeElem.end(), element);
        if(isPrime(element))
        {
            this->primeElem.insert(itPrime, element);    
        }  
    }
    void MagicalContainer::removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                return;
            }
        }
        throw runtime_error("Element not found");         
    }
    
    int MagicalContainer::size(){
        return elements.size();
    }

     bool MagicalContainer::isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= std::sqrt(number); ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
    
//--------------AscendingIterator---------------//

    //constructors
    MagicalContainer::AscendingIterator::AscendingIterator() : 
        container(nullptr), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : 
        container(&container), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}
    //destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Assignment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (container != other.container) {
            throw runtime_error("iterators are pointing at different containers");
        }
        if (this != &other) {
            this->container = other.container;
            this->index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return (index == other.index) && (container == other.container);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return (container == other.container) && (index > other.index);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return (container == other.container) && (index < other.index);
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container->elements[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if (index >= container->size()) {
            throw std::runtime_error("cannot increment iterator beyond end");
        }
        ++index;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(*container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator it(*container);
        it.index = container->elements.size();  // index=container size because this is the end
        return it;
        } 

//--------------SideCrossIterator---------------//

    //constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator() : 
    container(nullptr), index(0), crossIter(0){}
    
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : 
    container(&container), index(0), crossIter(0){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) :
    container(other.container), index(other.index), crossIter(other.crossIter) {}

    //destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Assignment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if(container != other.container){
                throw runtime_error("iterators are pointing at different containers");
            }
            if(this != &other) {
                this->index = other.index;
                this->crossIter = other.crossIter;
                this->container = other.container;
            }
        return *this;
        }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (index == other.index) && (container == other.container);
   }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    
        return (index > other.index) && (container == other.container);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return (index < other.index) && (container == other.container);
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return this->container->elements[this->crossIter];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (index >= this->container->size()) {
        throw std::runtime_error("cannot increment iterator beyond end");
    }
    index++;
    if (crossIter < container->size() / 2) {
        crossIter = (size_t)container->size() - (crossIter + 1);
    } else {
        crossIter = (size_t)container->size() - crossIter;
    }
    return *this;
    } 

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(*container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator it(*container);
        it.index = container->elements.size();  // index=container size because this is the end
        return it;
    }



//--------------PrimeIterator---------------//

    //constructors
    MagicalContainer::PrimeIterator::PrimeIterator() : 
        container(nullptr), index(0) {}
        
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : 
        container(&container), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) :
        container(other.container), index(other.index) {}

    //destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Assignment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if(this->container != other.container){
            throw runtime_error("iterators are pointing at different containers");
        }
        if(this != &other) {
            this->index = other.index;
            this->container = other.container;
        }
        return *this;
    }
    
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return (this->index == other.index) && (container == other.container);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
         return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return (container == other.container) && (this->index > other.index);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return (container == other.container) && (this->index < other.index);
    }

    int MagicalContainer::PrimeIterator::operator*() const {
         return this->container->primeElem[this->index];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {        
        if (this->index >= container->primeElem.size())
                {
                    throw std::runtime_error("cannot increment iterator beyond end");
                }
                    ++this->index;
                return *this;
        }


    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(*container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator it(*this->container);
        it.index = container->primeElem.size();  // index=container size because this is the end
        return it;
    }
