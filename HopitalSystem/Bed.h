//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_BED_H
#define COEN244_ASS4_BED_H


class Bed {
    Bed(int id) : id(id), isAvailable(true){}
    int id; //the uniquness of the ID will be handled by Hospital
    bool isAvailable;
};


#endif //COEN244_ASS4_BED_H
