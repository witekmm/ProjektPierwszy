#include "Bike_Header.hpp"

Bike::Bike(string a1, double a2, int rame, int wheel, int years){
            name = a1;
            price = a2;
            rame_size = rame;
            wheel_size = wheel;
            age = years;
}

void Bike::operator++(int){
    price+=100;
    cout<<"The price of the bike was increased by 100$"<<endl;
    return;
}

void Bike::operator++(){
    price+=1000;
    cout<<"The price of the bike was increased by 1000$"<<endl;
    return;
}

double Bike::operator-(Bike &bk2){ // Operator - polega na obnizeniu ceny 1 roweru gdy oddajemy rower 2
        cout<<"Bike price after discount is "<<price-0.5*bk2.price<<endl;
        return price-0.5*bk2.price;
}

double Bike::operator+(Bike &bk2){ // Operator + polega na obliczeniu ceny 2 rowerów kupowanych w jednym czasie
        cout<<"Price for those 2 bikes is "<<0.8*price+0.8*bk2.price<<endl;
        return 0.8*price+0.8*bk2.price;
    }

string Bike::getName(){
        return name;
}

double Bike::getPrice(){
        return price;
}

int Bike::get_rame_size(){
        return rame_size;
}

int Bike::get_wheel_size(){
        return wheel_size;
}

int Bike::getAge(){
        return age;
}

void Bike::setAge(int help){
        if(help<0) return;
        age=help;
        return;
}

void Bike::setName(string help){
        name=help;
        return;
}

void Bike::setPrice(double help){
        if(help<0) return;
        price=help;
        return;
}

void Bike::set_rame_size(int help){
        if(help < 10 || help > 30) return;
        rame_size=help;
        return;
}

void Bike::set_wheel_size(int help){
        if(help < 10 || help > 30) return;
        wheel_size=help;
        return;
}

void Bike::setAll(string help_name,double help_price,int help_wheel,int help_rame,int help_age){
        if(help_wheel==0 &&  help_rame==0 && help_age==0 && help_price==0){
                name=help_name;
                price=help_price;
                wheel_size=help_wheel;
                rame_size=help_rame;
                age=help_age;
                return;
        }
        if(help_wheel < 10 || help_wheel > 30 || help_rame < 10 || help_rame > 30) return;
        if(help_age < 0 || help_price < 0) return;
        name=help_name;
        price=help_price;
        wheel_size=help_wheel;
        rame_size=help_rame;
        age=help_age;
        return;

}
