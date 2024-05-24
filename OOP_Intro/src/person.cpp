#include "person.h"

person::person(String _forename, String _lastname, String _sex, int _height){
    forname=_forename;
    lastname=_lastname;
    sex=_sex;
    height=_height;
}

void person::printAll(){
    Serial.println(age);
}

void person::printPersonDetails(){
    Serial.printf("Name: %s Lastname: %s Age: %d Sex: %s Height: %d \n",forname,lastname,age,sex,height,height);
}

void person::setAge(int _age){
    if(_age>100)age=99;
    else age=_age;
}

void person::setLastname(String _lastname){
    lastname=_lastname;
}
