#include "Funktionheader.hpp"

using namespace std;

int Shop::number_of_shops = 0;

int main()
{
    Shop firstShop("First", "Krakow", 10000);
    Shop secondShop("Second", "Warsaw", 15000);
    Shop thirdShop("Third", "Krakow", 18000);
    Bike bikeOne("One",899.99,22,24,2);
    Bike bikeTwo("Two",1299.99,20,26,1);
    Bike bikeThree("Three",2000.00,23,28,0);
    Bike bikeTwoCopy(bikeTwo);
    bikeTwoCopy.view();
    TestingClass tests;
    tests.testAdding(bikeOne,bikeTwo);
    tests.testAdding(firstShop,secondShop);
    tests.testBuying(bikeOne,bikeThree,2,5);




    return 0;
}
