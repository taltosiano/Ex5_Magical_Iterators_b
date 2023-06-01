#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
namespace ariel{

   MagicalContainer::MagicalContainer() {}
    
    void MagicalContainer::addElement(int element) {
       elements.push_back(element);
       sort(elements.begin(), elements.end());         // each push we sort
}
    
    void MagicalContainer::removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                return;
            }
        }
        throw runtime_error("Element not found in container");         
    }
    
    int MagicalContainer::size(){
        return elements.size();
    }

    vector<int> MagicalContainer::getElements() const{
        return elements;
    }

//--------------AscendingIterator---------------//

   
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont, int index) : container(cont), index(index) {}
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : container(cont), index(0) {}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}
    
    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if(this != &other) {
            this->container = other.container;
            this->index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return (&this->container == &other.container && this->index == other.index);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return (this->index > other.index);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return !(this->index > other.index);
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.elements[(std::vector<int>::size_type)index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        index++;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(container,0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(container,container.size());
    }


//--------------SideCrossIterator---------------//


   
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, int index, bool isEnd) : 
    container(container), index(index), isEnd(isEnd){}
    
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : 
    container(container), index(0), isEnd(true){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) :
    container(other.container), index(other.index), isEnd(other.isEnd) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if(this != &other) {
            this->container = other.container;
            this->index = other.index;
            this->isEnd = other.isEnd;
        }
        return *this;
   }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (&this->container == &other.container) && (isEnd == other.isEnd) && (index == other.index);
   }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
         return (this->index > other.index);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return !(*this > other);
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
       if (isEnd) {
            return container.elements[(std::vector<int>::size_type)index];
        } else {
            return container.elements[(std::vector<int>::size_type)(container.size() - index)];
        }
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (isEnd){
            if(index != container.size()/2)
            ++index;
            else
                index = container.size();
        }
      
        isEnd = !isEnd;

        return *this;
}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(container,0,true);

    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return SideCrossIterator(container, container.size(), false);
    }



//--------------PrimeIterator---------------//

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, int index) : 
        container(container), index(index) {}
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : 
        container(container), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) :
        container(other.container), index(other.index) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if(this != &other) {
            this->container = other.container;
            this->index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return (this->index == other.index);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
         return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return (this->index > other.index);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return !(this->index > other.index);
    }

    int MagicalContainer::PrimeIterator::operator*() const {
         return container.elements[static_cast<std::vector<int>::size_type>(index)];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        do {
            index++;
        } while (index < container.size() && !isPrime(container.elements[static_cast<std::vector<int>::size_type>(index)]));
        return *this;
      }



    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(container, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return PrimeIterator(container,container.size());

    }
    }
