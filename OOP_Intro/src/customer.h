#ifndef customer_h
#define customer_h

#include <Arduino.h>
#include "person.h"

class customer : public person{
    private:
        int customerid;
        int sales;
    public:
        using person::person;
        void setCustomerID(int nr);
        void sumSales(int _sales);
        void printPersonDetails();
};

#endif