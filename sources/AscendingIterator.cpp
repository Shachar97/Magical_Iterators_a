
#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"
#include "prime.hpp"

using namespace std;

namespace ariel{

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer magic)
        :ascIter_(new vector<int>),currentIndex_(0){/*TODO: build insert linklist of magic (deep copy)*/
      
        *ascIter_=*(magic.magic_); // O(n)

        if(ascIter_->size()>1){
            sort(ascIter_->begin(),ascIter_->end()); // O(nlog(n))
        }
    }

    MagicalContainer::AscendingIterator & MagicalContainer::AscendingIterator:: operator=(const AscendingIterator& other) {
        if (this != &other) {
            ascIter_ = other.ascIter_;
            currentIndex_ = other.currentIndex_;
        }
        return *this;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& other)
        :ascIter_(other.ascIter_), currentIndex_(other.currentIndex_){
    }

    MagicalContainer::AscendingIterator::~AscendingIterator(){
        delete ascIter_;
    }

    int ariel::MagicalContainer::AscendingIterator::operator*() const{
            return (*ascIter_)[currentIndex_];
    }

    ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator++() {
        ++currentIndex_;
        return *this;
    }
        
    ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::operator++(int){
        AscendingIterator temp = *this;
        ++(*this);
        return temp;
    }

    ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator--(){
        --currentIndex_;
        return *this;
    }
        
    ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::operator--(int){
        AscendingIterator temp = *this;
        --(*this);
        return temp;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator==(const ariel::MagicalContainer::AscendingIterator &other) const {
        return currentIndex_ == other.currentIndex_;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator!=(const ariel::MagicalContainer::AscendingIterator &other) const {
        return !(*this == other);
    }

    bool ariel::MagicalContainer::AscendingIterator::operator==(std::vector<int>::iterator other) const {
        return *this == other;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator!=(std::vector<int>::iterator other) const{
        return !(*this == other);
    }

    bool ariel::MagicalContainer::AscendingIterator::operator<(const ariel::MagicalContainer::AscendingIterator &other) const {
        return currentIndex_ < other.currentIndex_;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator>(const ariel::MagicalContainer::AscendingIterator &other) const {
        return currentIndex_ > other.currentIndex_;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator<=(const ariel::MagicalContainer::AscendingIterator &other) const {
        return currentIndex_ <= other.currentIndex_;
    }

    bool ariel::MagicalContainer::AscendingIterator::operator>=(const ariel::MagicalContainer::AscendingIterator &other) const {
        return currentIndex_ >= other.currentIndex_;
    }

    std::vector<int>::iterator ariel::MagicalContainer::AscendingIterator::begin(){
        return ascIter_->begin();
    }

    std::vector<int>::iterator ariel::MagicalContainer::AscendingIterator::end(){
        return ascIter_->end();
    }

    void ariel::MagicalContainer::AscendingIterator::addElement(int data) {/*TODO*/
        if(ascIter_->size()==0){
            ascIter_->push_back(data);
        }else{
            auto it = std::lower_bound(ascIter_->begin(), ascIter_->end(), data);
            ascIter_->insert(it,data);
        }
        
    }
}