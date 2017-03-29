#include "Bike_Header.hpp"
#ifndef Shop_Header_hpp
#define Shop_Header_hpp


class Shop{

        Bike empty_bicycle;
        Bike bicycle[10];
        int number_of_bikes;
        string shop_name;
        string city;
        double money;
        int credit;


    public:

        static int number_of_shops;

        Shop(string name, string place,double cash);
        ~Shop();
        //metods
        int sell_bicycle(int place);
        int buy_bicycle(Bike &bk,int place);
        int buy_2_bicycles(Bike &bk1, Bike &bk2,int place1, int place2);
        int sell_and_change(int place, Bike &bk2);
        //operators
        void operator--();
        void operator++();
        double operator+(Shop &sh2);
        void operator=(Shop &sh1);
        //setting
        void set_shop_name(string help);
        void setCity(string help);
        void setCredit(double help);
        void setMoney(double help);
        //getting
        double getMoney();
        string getCity();
        int getCredit();
        string getName();
        int getRame(int place);
        //view
        void showMe();
};

#endif
