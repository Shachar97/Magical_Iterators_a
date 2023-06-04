#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"
#include "prime.hpp"

using namespace std;

namespace ariel{
    ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(ariel::MagicalContainer magic)
            :sideIter_(new vector<int>),currentIndex_(0){
            
            if(magic.size()!=0){
                if (magic.size()==1){
                    sideIter_->push_back(magic.magic_->front());
                }else{
                    if(magic.ascendIter_){
                        auto st = magic.ascendIter_->begin();
                        auto en = magic.ascendIter_->end() - 1;
                        while (st < en) {
                            sideIter_->push_back(*st);
                            sideIter_->push_back(*en);
                            ++st;
                            --en;
                        }
                        // Handle the middle element for odd-sized containers
                        if (st == en) {
                            sideIter_->push_back(*st);
                        }
                    }else{
                        vector<int> temp=*(magic.magic_);
                        sort(temp.begin(),temp.end());

                        auto st = temp.begin();
                        auto en = temp.end() - 1;
                        while (st < en) {
                            sideIter_->push_back(*st);
                            sideIter_->push_back(*en);
                            ++st;
                            --en;
                        }
                        // Handle the middle element for odd-sized containers
                        if (st == en) {
                            sideIter_->push_back(*st);
                        }
                    }
                    
                }
            }
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator=(const ariel::MagicalContainer::SideCrossIterator &other) {
            if (this != &other) {
                sideIter_ = other.sideIter_;
                currentIndex_ = other.currentIndex_;
            }
            return *this;
        }

        ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer::SideCrossIterator &other)
            : sideIter_(other.sideIter_), currentIndex_(other.currentIndex_){
        }

        ariel::MagicalContainer::SideCrossIterator::~SideCrossIterator(){
            delete sideIter_;
        }

        int ariel::MagicalContainer::SideCrossIterator::operator*() const {
                return (*sideIter_)[currentIndex_];
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator++() {
            ++currentIndex_;
            return *this;
        }
            
        ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::operator++(int) {
            SideCrossIterator temp = *this;
            ++(*this);
            return temp;
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator--(){
            --currentIndex_;
            return *this;
        }
            
        ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::operator--(int){
            SideCrossIterator temp = *this;
            --(*this);
            return temp;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator==(const ariel::MagicalContainer::SideCrossIterator &other) const {
            return currentIndex_ == other.currentIndex_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator!=(const ariel::MagicalContainer::SideCrossIterator &other) const {
            return !(*this == other);
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator==(std::vector<int>::iterator other) const{
            return *this == other;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator!=(std::vector<int>::iterator other) const{
            return !(*this == other);
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator<(const ariel::MagicalContainer::SideCrossIterator &other) const {
            return currentIndex_ < other.currentIndex_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator>(const ariel::MagicalContainer::SideCrossIterator &other) const{
            return currentIndex_ > other.currentIndex_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator<=(const ariel::MagicalContainer::SideCrossIterator &other) const {
            return currentIndex_ <= other.currentIndex_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator>=(const ariel::MagicalContainer::SideCrossIterator &other) const{
            return currentIndex_ >= other.currentIndex_;
        }

        std::vector<int>::iterator ariel::MagicalContainer::SideCrossIterator::begin(){
            return sideIter_->begin();
        }
        std::vector<int>::iterator ariel::MagicalContainer::SideCrossIterator::end(){
            return sideIter_->end();
        }
        void ariel::MagicalContainer::SideCrossIterator::addElement(int data){/*TODO*/
            if(sideIter_->size()==0){
                sideIter_->push_back(data);
            }else{
                bool flag = true;
                auto it = sideIter_->begin();
                while(it != sideIter_->end()){
                    if(flag){
                        if(data<*it){
                            /*INSERT DATA*/
                            sideIter_->insert(it,data);
                            return;
                        }
                        flag = false;
                        ++it;
                    }else{
                        if(data>*it){
                            /*INSERT DATA*/
                            sideIter_->insert(it,data);
                            return;
                        }
                        flag = true;
                        ++it;
                    }
                }
                sideIter_->push_back(data);
            }
        }
}