#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"
#include "prime.hpp"

using namespace std;

namespace ariel{
    ariel::MagicalContainer::PrimeIterator::PrimeIterator(ariel::MagicalContainer magic)
        :primeIter_(new vector<int>),currentIndex_(0){
        if(magic.magic_->size()>0){
            
            auto it = magic.magic_->begin();
            while(it != magic.magic_->end()){
                
                if(isPrime(*it)){
                    
                    primeIter_->push_back(*it);
                }
                ++it;
            }
            sort(primeIter_->begin(),primeIter_->end());
        }
    }

    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator=(const ariel::MagicalContainer::PrimeIterator &other) {
        if (this != &other) {
            primeIter_ = other.primeIter_;
            currentIndex_ = other.currentIndex_;
        }
        return *this;
    }

    ariel::MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other)
        : primeIter_(other.primeIter_), currentIndex_(other.currentIndex_){
    }

    ariel::MagicalContainer::PrimeIterator::~PrimeIterator(){
        delete primeIter_;
    }

    int ariel::MagicalContainer::PrimeIterator::operator*() const{
        return (*primeIter_)[currentIndex_];
    }

    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator++() {
        ++currentIndex_;
        return *this;
    }
        
    ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::operator++(int)
    {
        PrimeIterator temp = *this;
        ++(*this);
        return temp;
    }

    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator--()
    {
        --currentIndex_;
        return *this;
    }
        
    ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::operator--(int)
    {
        PrimeIterator temp = *this;
        --(*this);
        return temp;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator==(const ariel::MagicalContainer::PrimeIterator &other) const{
            return currentIndex_ == other.currentIndex_;
        }

    bool ariel::MagicalContainer::PrimeIterator::operator!=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return !(*this == other);
    }

    bool ariel::MagicalContainer::PrimeIterator::operator==(std::vector<int>::iterator other) const{
        return *this == other;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator!=(std::vector<int>::iterator other) const
    {
        return !(*this == other);
    }

    bool ariel::MagicalContainer::PrimeIterator::operator<(const ariel::MagicalContainer::PrimeIterator &other) const {
        return currentIndex_ < other.currentIndex_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator>(const ariel::MagicalContainer::PrimeIterator &other) const {
        return currentIndex_ > other.currentIndex_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator<=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return currentIndex_ <= other.currentIndex_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator>=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return currentIndex_ >= other.currentIndex_;
    }

    std::vector<int>::iterator ariel::MagicalContainer::PrimeIterator::begin()
    {
        return primeIter_->begin();
    }

    std::vector<int>::iterator ariel::MagicalContainer::PrimeIterator::end(){
        return primeIter_->end();
    }

    void ariel::MagicalContainer::PrimeIterator::addElement(int data){/*TODO*/
        if(isPrime(data)){
            if(primeIter_->size()==0){
                primeIter_->push_back(data);
            }else{
                auto it = primeIter_->begin();
                while(it != primeIter_->end()){
                    if(data<*it){
                        /*INSERT DATA*/
                        primeIter_->insert(it,data);
                        return;
                    }
                    ++it;
                }
                primeIter_->push_back(data);
            }
        }
    }
}