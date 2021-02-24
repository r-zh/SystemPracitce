//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_PERSON_H
#define COEN244_ASS4_PERSON_H

#include <string>

class Person {

public:
    Person(std::string name) : name(name) {}
    std::string getName() const { return name;}
    void setName(const std::string& n) {name = n;}

    virtual void print() const = 0;

protected:
    std::string name;
};


#endif //COEN244_ASS4_PERSON_H
