#include "Shop_Header.hpp"
#ifndef Funktionheader_hpp
#define Funktionheader_hpp

class TestingClass{

    public:

    void testAdding(Bike &bike1, Bike &bike2);
    void testAdding(Shop &shop1, Shop &shop2);


    void testEqual(Shop &shop1, Shop &shop2);

    void testDecrementation(Shop &shop1);

    void testPreIncrementation(Shop &shop1);
    void testPreIncrementation(Bike &bike1);

    void testPostIncrementation(Bike &bike1);

    void testBuying(Bike &bike1,int place);
    void testBuying(Bike &bike1, Bike &bike2, int place1,int place2);

    void testSelling(Bike &bike1);
    void testSellChange(Bike &bike1,Bike &bike2);
};

#endif
