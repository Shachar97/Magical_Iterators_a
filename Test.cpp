#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include "sources/prime.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

#define SEED 100
#define LOOP 10

TEST_SUITE("Add && remove Elements in Magical") {
    MagicalContainer container;
    TEST_CASE("sizing"){
        srand(SEED);
        CHECK_EQ(container.size(),0);
        for(int i=1;i<=LOOP;i++){
            container.addElement(i);
            CHECK_EQ(container.size(),i);
        }
    }
    TEST_CASE("Removing element") {
        
        for (int i=1 ; i<=LOOP; i++){
            CHECK_NE( find(container.begin(),container.end(),i) , container.end());
            container.removeElement(i);
            CHECK_EQ( find(container.begin(),container.end(),i) , container.end());
        }
    }
}
TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    
    for (int i = LOOP; i > 0; i--)
    {
        container.addElement(i);
    }
    
    MagicalContainer::AscendingIterator ascIter(container);
    int i=1;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        CHECK_EQ(*it , i++);
    }
}

TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    
    for (int i = LOOP; i > 0; i--)
    {
        container.addElement(i);
    }
    
    MagicalContainer::SideCrossIterator SideIter(container);
    int i=1;
    int j=LOOP;
    int flag =1;
    for (auto it = SideIter.begin(); it != SideIter.end(); ++it)
    {
        if(flag){
            flag =0;
            CHECK_EQ(*it , i++);    
        }else{
            CHECK_EQ(*it , j--);
        }
        
    }
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    
    for (int i = LOOP; i > 0; i--)
    {
        container.addElement(i);
    }
    
    MagicalContainer::PrimeIterator primeIter(container);
    int i=1;

    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        while(!isPrime(i)){
            i++;
        }
        if(isPrime(i)){
            CHECK_EQ(*it , i);    
        }
        i++;
    }
}

TEST_CASE("Operators") {
    MagicalContainer container;
    
    for (int i = 3; i > 0; i--)
    {
        container.addElement(i);
    }
    MagicalContainer::AscendingIterator ascIter_1(container);
    MagicalContainer::AscendingIterator ascIter_2(container);

    auto it_1 = ascIter_1.begin();
    auto it_2 = ascIter_2.begin();
    
    CHECK(ascIter_1 != ascIter_2); 
    CHECK_EQ(it_1,it_2); //operator =
    CHECK(it_1++ < ++it_2); // increment &  Pre-increment & operator <
    CHECK_EQ(it_1,it_2); //operator =
    CHECK(++it_1 > it_2++); // increment &  Pre-increment & operator >
    CHECK_EQ(it_1,it_2); //operator =

    CHECK(--it_1 != it_2--); // decrement &  Pre-decrement & operator !=

    MagicalContainer::AscendingIterator SideIter_1(container);
    MagicalContainer::AscendingIterator SideIter_2(container);

    auto it_3 = SideIter_1.begin();
    auto it_4 = SideIter_2.begin();
    
    CHECK(SideIter_1 != SideIter_2); 
    CHECK_EQ(it_3,it_4); //operator =
    CHECK(it_3++ < ++it_4); // increment &  Pre-increment & operator <
    CHECK_EQ(it_3,it_4); //operator =
    CHECK(++it_3 > it_4++); // increment &  Pre-increment & operator >
    CHECK_EQ(it_3,it_4); //operator =

    CHECK(--it_3 != it_4--); // decrement &  Pre-decrement & operator !=

    MagicalContainer::PrimeIterator PrimeIter_1(container);
    MagicalContainer::PrimeIterator PrimeIter_2(container);

    auto it_5 = PrimeIter_1.begin();
    auto it_6 = PrimeIter_2.begin();
    
    CHECK(PrimeIter_1 != PrimeIter_2); 
    CHECK_EQ(it_5,it_6); //operator =
    CHECK(it_5++ < ++it_6); // increment &  Pre-increment & operator <
    CHECK_EQ(it_5,it_6); //operator =
    CHECK(++it_5 > it_6++); // increment &  Pre-increment & operator >
    CHECK_EQ(it_5,it_6); //operator =

    CHECK(--it_5 != it_6--); // decrement &  Pre-decrement & operator !=

}

