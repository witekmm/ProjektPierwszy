#ifndef Bike_Header_hpp
#define Bike_Header_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Bike{
        string name;
        double price;
        int rame_size;
        int wheel_size;
        int age;

    public:
        Bike(string a1, double a2, int rame, int wheel, int years);
        //operators
        void operator++(int);
        void operator++();
        double operator-(Bike &bk2);
        double operator+(Bike &bk2);
        //getting
        string getName();
        double getPrice();
        int get_rame_size();
        int get_wheel_size();
        int getAge();
        //changing
        void setAge(int help);
        void setName(string help);
        void setPrice(double help);
        void set_rame_size(int help);
        void set_wheel_size(int help);
        void setAll(string help_name,double help_price,int help_wheel,int help_rame,int help_age);

};


#endif
