//
// Created by tawfiq on 2020-04-06.
// Abstract class to be used for all patients
//

#ifndef COEN244_ASS4_PATIENT_H
#define COEN244_ASS4_PATIENT_H
#include "Person.h"
#include <string>

class Doctor;   //forward declaration

//This class is only holding a pointer to the doctor
//it does not own the pointer
//the hospital holds and owns all doctor objects
//therefore it will not be deleted here in the destruction
//of the Patient.
//it will be deleted when hospital is deleted

class Patient : public Person{
public:
    //doctor initialized to nullptr at first
    Patient(int id, std::string name) : id(id), Person(name), doctor(nullptr) {}
    int getID() const { return id;}
    void setDoctor(Doctor const * doc)   { doctor = doc;}
    Doctor const* getDoctor() const { return doctor;}
    virtual void print() const =0;
protected:
    int id; //the uniquness of the ID will be handled by Hospital
    Doctor const *  doctor; //doctor who is providing treatment
    //the pointer can change, but the doctor object is const which means
    //the doctor can not be modified from here
};


#endif //COEN244_ASS4_PATIENT_H
