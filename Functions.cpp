#include "Funktionheader.hpp"


void TestingClass::testAdding(Bike &bike1, Bike &bike2){
        double test = (bike1.getPrice() + bike2.getPrice())*0.8;
        double check = bike1 + bike2;
        assert(test==check);
        return;
    }

void TestingClass::testAdding(Shop &shop1, Shop &shop2){
        double test = shop1.getMoney() + shop2.getMoney();
        double check = shop1 + shop2;
        if(check == 0){
            assert(shop1.getCity() != shop2.getCity());
        }
        else assert(test == check);
        return;
}

void TestingClass::testEqual(Shop &shop1, Shop &shop2){
        double test = shop2.getMoney();
        shop1 = shop2;
        assert(test == shop1.getMoney());
        return;
}

void TestingClass::testDecrementation(Shop &shop1){

        Shop testing(shop1.getName(),shop1.getCity(),shop1.getMoney());
        testing.setCredit(shop1.getCredit());

        double test1 = shop1.getCredit()-1000;
        double test2 = shop1.getMoney()-1000;
        --testing;
        if(shop1.getCredit()>0){
        assert(test1 == testing.getCredit());
        assert(test2 == testing.getMoney());
        }

        return;
}

void TestingClass::testPreIncrementation(Shop &shop1){

        Shop testing(shop1.getName(),shop1.getCity(),shop1.getMoney());
        testing.setCredit(shop1.getCredit());

        double test1 = shop1.getCredit()+1000;
        double test2 = shop1.getMoney()+1000;
        ++testing;
        if(shop1.getCredit()<10000){
        assert(test1 == testing.getCredit());
        assert(test2 == testing.getMoney());
        }

        return;
}

void TestingClass::testPreIncrementation(Bike &bike1){
        Bike testing(bike1);
        double test = bike1.getPrice()+1000;
        ++testing;
        assert(test == testing.getPrice());
        return;
}

void TestingClass::testPostIncrementation(Bike &bike1){
        Bike testing(bike1);
        double test = bike1.getPrice()+100;
        testing++;
        assert(test == testing.getPrice());
        return;
}

void TestingClass::testBuying(Bike &bike1,int place){
        Shop shop1("name","place",50000);
        int test = shop1.buy_bicycle(bike1,place);
        if(test){
        assert(shop1.getRame(place+1) == bike1.get_rame_size());
        assert(50000-bike1.getPrice()==shop1.getMoney());
        }
        return;
}

void TestingClass::testBuying(Bike &bike1,Bike &bike2,int place1,int place2){
        Shop shop1("name","place",50000);
        int test = shop1.buy_2_bicycles(bike1,bike2,place1,place2);
        if(test){
        assert(shop1.getRame(place1+1)==bike1.get_rame_size());
        assert(shop1.getRame(place2+1)==bike2.get_rame_size());
        assert(50000-0.8*(bike1.getPrice()+bike2.getPrice())==shop1.getMoney());
        }
        return;
}

void  TestingClass::testSelling(Bike &bike1){
        Shop shop1("name","place",50000);
        shop1.buy_bicycle(bike1,5);
        shop1.buy_bicycle(bike1,6);
        shop1.setMoney(50000);
        int test = shop1.sell_bicycle(5);
        if(test){
            assert(50000+bike1.getPrice()==shop1.getMoney());
            assert(0==shop1.getRame(5));
        }
        return;
}

void TestingClass::testSellChange(Bike &bike1,Bike &bike2){
        Shop shop1("name","place",50000);
        shop1.buy_bicycle(bike1,5);
        shop1.buy_bicycle(bike1,6);
        shop1.setMoney(50000);
        int test = shop1.sell_and_change(5,bike2);
        if(test){
            assert(shop1.getRame(5) == bike2.get_rame_size());
            assert(50000+bike1.getPrice()-0.5*bike2.getPrice() == shop1.getMoney());
        }
        return;
}
