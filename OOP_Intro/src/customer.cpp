#include "customer.h"
#include <Arduino.h>

void customer::setCustomerID(int nr){
    customerid=nr;
}

void customer::sumSales(int _sales){
    sales+=_sales;
}

void customer::printPersonDetails(){
    Serial.printf("Name: %s Lastname: %s Sales: %d \n",forname,lastname,sales);
}