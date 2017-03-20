#include "Shop_Header.hpp"

Shop::Shop(string name, string place,double cash){
    number_of_shops++;
    number_of_bikes=0;
    shop_name=name;
    city=place;
    money=cash;
    empty_bicycle::setAll("empty_place",0,0,0,0);
    credit=0;
}

Shop::~Shop(){
    number_of_shops--;
}

void Shop::sell_bicycle(Bike &bk1){
    double temp = bk1::getPrice();
    money+=temp;
    number_of_bikes--;
    bk1::setAll(empty_bicycle::getName(),empty_bicycle::getPrice(),empty_bicycle::get_wheel_size(),empty_bicycle::get_rame_size(),empty_bicycle::getAge());
    return;
}

int Shop::buy_bicycle(Bike &bk){
    if(number_of_bikes==10) return 1;
    double temp = bk::getPrice();
    if(money<temp) return 1;
    money-=temp;
    bicycle[number_of_bikes]=bk;
    number_of_bikes++;
    return 0;
}

int Shop::buy_2_bicycles(Bike &bk1, Bike &bk2){
    if(number_of_bikes>=9) return 1;
    if(money<(bk1+bk2)) return 1;
    money-=(bk1+bk2);
    bicycle[number_of_bikes]=bk1;
    bicycle[number_of_bikes+1]=bk2;
    number_of_bikes+=2;
    return 0;
}

void Shop::sell_and_change(Bike &bk1, Bike &bk2){
    money+=(bk1-bk2);
    bk1=bk2;
    return;
}

void Shop::operator--(){//Splacenie pozyczki. Kazdorazowo 1000$
        if(credit == 0){
            cout<<"Nothing to pay off!"<<endl;
            return;
        }
        else{
            if(money < 1000){
                cout<<"Not enough money to pay off the debt"<<endl;
                return;
            }
            cout<<"1000$ payed off!"<<endl;
            credit-=1000;
            money-=1000;
            return;
        }
}

void Shop::operator++(){//Po¿yczka z banku. Ka¿dorazowo 1000$
        if(credit > 10000){
            cout<<"Achieved maximum amount of borrowed money"<<endl;
            return;
        }
        else{
            cout<<"1000$ borrowed!"<<endl;
            credit+=1000;
            money += 1000;
            return;
        }
}

double Shop::operator+ (Shop &sh2){ //£¹czenie 2 sklepów. Mo¿e siê odbyæ tylko gdy oba sklepy s¹ w 1 mieœcie
        if(city != sh2.city){
            cout<<"Different cities! Cannot connect shops!"<<endl;
            return 0;
        }
        else{
            cout<<"Account balance after connect is going to be"<<money+sh2.money<<endl;
            return money+sh2.money;
        }
}

void Shop::set_shop_name(string help){
        shop_name=help;
        return;
}

void Shop::setCity(string help){
        city=help;
        return;
}
