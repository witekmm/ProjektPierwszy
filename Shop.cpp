#include "Shop_Header.hpp"

Shop::Shop(string name, string place,double cash){
    number_of_shops++;
    number_of_bikes=0;
    shop_name=name;
    city=place;
    money=cash;
    credit=0;
}

Shop::~Shop(){
    number_of_shops--;
}

int Shop::sell_bicycle(int place){
    if(bicycle[place-1].get_wheel_size()==0) return 0;
    double temp = bicycle[place-1].getPrice();
    money+=temp;
    number_of_bikes--;
    bicycle[place-1].setAll(empty_bicycle.getName(),empty_bicycle.getPrice(),empty_bicycle.get_wheel_size(),empty_bicycle.get_rame_size(),empty_bicycle.getAge());
    return 1;
}

int Shop::buy_bicycle(Bike &bk,int place){
    if(number_of_bikes==10) return 0;
    if(bicycle[place-1].get_rame_size()!=0) return 0;
    double temp = bk.getPrice();
    if(money<temp) return 0;
    money-=temp;
    bicycle[place-1].setAll(bk.getName(),bk.getPrice(),bk.get_wheel_size(),bk.get_rame_size(),bk.getAge());
    number_of_bikes++;
    return 1;
}

int Shop::buy_2_bicycles(Bike &bk1, Bike &bk2,int place1, int place2){
    if(number_of_bikes>=9) return 0;
    if(money<(bk1+bk2)) return 0;
    if(bicycle[place1-1].get_wheel_size()!=0 || bicycle[place2-1].get_wheel_size()!=0) return 0;
    money-=(bk1+bk2);
    bicycle[place1-1]=bk1;
    bicycle[place2-1]=bk2;
    number_of_bikes+=2;
    return 1;
}

int Shop::sell_and_change(int place, Bike &bk2){
    if(bicycle[place-1].get_wheel_size()==0) return 0;
    money+=(bicycle[place-1]-bk2);
    bicycle[place-1].setAll(bk2.getName(),bk2.getPrice(),bk2.get_wheel_size(),bk2.get_rame_size(),bk2.getAge());
    return 1;
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
        if(city != sh2.getCity()){
            cout<<"Different cities! Cannot connect shops!"<<endl;
            return 0;
        }
        else{
            cout<<"Account balance after connect is going to be"<<money+sh2.getMoney()<<endl;
            return money+sh2.getMoney();
        }
}

void Shop::operator=(Shop &sh1){
        money = sh1.getMoney();
        return;
}

void Shop::set_shop_name(string help){
        shop_name=help;
        return;
}

void Shop::setCity(string help){
        city=help;
        return;
}

void Shop::setCredit(double help){
        credit = help;
        return;
}

void Shop::setMoney(double help){
        money=help;
        return;
}

double Shop::getMoney(){
        return money;
}

string Shop::getCity(){
        return city;
}

int Shop::getCredit(){
        return credit;
}

string Shop::getName(){
        return shop_name;
}

int Shop::getRame(int place){
    int time = bicycle[place+1].get_rame_size();
    return time;
}

void Shop::showMe(){
        cout<<"Name     | "<<shop_name<<endl;
        cout<<"Location | "<<city<<endl;
        cout<<"Money    | "<<money<<endl;
        cout<<"Credit   | "<<credit<<endl;
        for(int i=0;i<10;i++){
            if(bicycle[i].get_rame_size()==0) continue;
            cout<<i;
            bicycle[i].view();
        }
        return;
}
