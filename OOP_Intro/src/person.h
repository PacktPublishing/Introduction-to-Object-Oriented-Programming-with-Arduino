#ifndef person_h
#define person_h


#include <Arduino.h>

class person{
    protected:
        int age;
        int height;

        String forname;
        String lastname;
        String sex;
        String adress;
        String zipcode;
        String country;
    public:
        person(String _forename, String _lastname, String _sex, int height);
        void printAll();
        void printPersonDetails();
        void setLastname(String _lastname);
        void setAge(int _age);
};

#endif