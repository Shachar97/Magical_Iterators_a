#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "prime.hpp"

using namespace std;

namespace ariel{
    class MagicalContainer
    {
    private:
    vector<int>* magic_;
        
    public:

    /*~~~~~~~AscendingIterator~~~~~~~~~*/
    class AscendingIterator
    {
    private:
        vector<int>* ascIter_;
        size_t currentIndex_;
    public:
        AscendingIterator(MagicalContainer magic);

        AscendingIterator& operator=(const AscendingIterator& other);

        AscendingIterator(const AscendingIterator& other);

        ~AscendingIterator();
        /*
        TODO OPERATORS
        */
        friend ostream& operator<<(ostream& os, const AscendingIterator& it)
        {
            os << *it;  
            return os;
        }

        int operator*() const;

        AscendingIterator& operator++();
            
        AscendingIterator operator++(int);

        AscendingIterator& operator--();
            
        AscendingIterator operator--(int);

        bool operator==(const AscendingIterator& other) const ;

        bool operator!=(const AscendingIterator& other) const ;

        bool operator==(const vector<int>::iterator other) const ;

        bool operator!=(const vector<int>::iterator other) const ;

        bool operator<(const AscendingIterator &other) const ;

        bool operator>(const AscendingIterator &other) const ;

        bool operator<=(const AscendingIterator &other) const;

        bool operator>=(const AscendingIterator &other) const;



        vector<int>::iterator begin();

        vector<int>::iterator end();

        void addElement(int data);
    };

    /*~~~~~~~SideCrossIterator~~~~~~~~~*/
    class SideCrossIterator
    {
    private:
    vector<int>* sideIter_;
    size_t currentIndex_;
              
    public:
        SideCrossIterator(MagicalContainer magic);

        SideCrossIterator& operator=(const SideCrossIterator& other);

        SideCrossIterator(const SideCrossIterator& other);

        ~SideCrossIterator();

        /*
        TODO OPERATORS
        */
        friend ostream& operator<<(ostream& os, const SideCrossIterator& it) {
            os << it;  
            return os;
        }

        int operator*() const;

        SideCrossIterator& operator++();
            
        SideCrossIterator operator++(int);

        SideCrossIterator& operator--();
            
        SideCrossIterator operator--(int);

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const ;

        bool operator==(const vector<int>::iterator other) const ;

        bool operator!=(const vector<int>::iterator other) const ;

        bool operator<(const SideCrossIterator &other) const;

        bool operator>(const SideCrossIterator &other) const ;

        bool operator<=(const SideCrossIterator &other) const ;

        bool operator>=(const SideCrossIterator &other) const ;

        vector<int>::iterator begin();

        vector<int>::iterator end();

        void addElement(int data);
    };

    /*~~~~~~~PrimeIterator~~~~~~~~~*/
    class PrimeIterator
    {
    private:
        vector<int>* primeIter_;
        size_t currentIndex_;
        
    public:
        PrimeIterator(MagicalContainer magic);

        PrimeIterator& operator=(const PrimeIterator& other);

        PrimeIterator(const PrimeIterator& other);

        ~PrimeIterator();

        friend ostream& operator<<(ostream& os, const PrimeIterator& it) {
            os << it;  
            return os;
        }

        int operator*() const;

        PrimeIterator& operator++();
            
        PrimeIterator operator++(int);

        PrimeIterator& operator--();

        PrimeIterator operator--(int);

        bool operator==(const PrimeIterator& other) const ;

        bool operator!=(const PrimeIterator& other) const;

        bool operator==(const vector<int>::iterator other) const ;

        bool operator!=(const vector<int>::iterator other) const;

        bool operator<(const PrimeIterator &other) const ;

        bool operator>(const PrimeIterator &other) const ;


        bool operator<=(const PrimeIterator &other) const;


        bool operator>=(const PrimeIterator &other) const ;


        vector<int>::iterator begin();

        vector<int>::iterator end();


        void addElement(int data);
    };
    
    /*~~~~~~~MagicalContainer~~~~~~~~~*/
    private:
        
        AscendingIterator* ascendIter_;
        SideCrossIterator* sideIter_;
        PrimeIterator* primeIter_;

    public:
        MagicalContainer():magic_(new vector<int>),ascendIter_(nullptr),sideIter_(nullptr),primeIter_(nullptr){}
        ~MagicalContainer(){
            delete magic_;
        }
        void addElement(int data){/*TODO*/

            magic_->push_back(data);

            /*AscendingIterator*/
            if(ascendIter_){/*TODO*/
                ascendIter_->addElement(data);
            }

            /*SideCrossIterator*/
            if(sideIter_){/*TODO*/
                sideIter_->addElement(data);
            }

            /*PrimeIterator*/
            if(primeIter_){/*TODO*/
                primeIter_->addElement(data);
            }

            return;
        }
        void removeElement(int data){/*TODO*/ }
        int size() const {/*TODO*/return magic_->size();}
        vector<int>::iterator begin(){
            return magic_->begin();
        }
        vector<int>::iterator end(){
            return magic_->end();
        }
    };
    
}

#endif