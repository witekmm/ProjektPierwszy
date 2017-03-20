#include "Bike_Header.hpp"
#ifndef Shop_Header_hpp
#define Shop_Header_hpp


class Shop{
        static int number_of_shops;
        static Bike empty_bicycle;
        Bike bicycle[10];
        int number_of_bikes;
        string shop_name;
        string city;
        double money;
        int credit;


    public:
        Shop(string name, string place,double cash);
        ~Shop();
        void sell_bicycle(Bike &bk1);
        int buy_bicycle(Bike &bk);
        int buy_2_bicycles(Bike &bk1, Bike &bk2);
        void sell_and_change(Bike &bk1, Bike &bk2);
        //operators
        void operator--();
        void operator++();
        double operator+(Shop &sh2);
        //setting
        void set_shop_name(string help);
        void setCity(string help);
};

#endif
