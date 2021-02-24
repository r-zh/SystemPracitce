//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_DATE_H
#define COEN244_ASS4_DATE_H

#include <iostream>
//we are assuming here that the developer is checking for
//correct input to Date object when using it
class Date {
    int month;
    int day;
    int year;

    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void print() const
    {
        std::cout << month << "/" << day << "/" << year;
    }

};


#endif //COEN244_ASS4_DATE_H
