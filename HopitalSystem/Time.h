//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_TIME_H
#define COEN244_ASS4_TIME_H
#include <iostream>

//hours are stored 0 to 23
class Time {
    unsigned int hour;
    unsigned int minute;

    Time(unsigned int hour, unsigned int minute) : hour(hour%24), minute(minute%60) {}

    void print() const
    {
        std::cout << hour << ":" << minute;
    }
};


#endif //COEN244_ASS4_TIME_H
