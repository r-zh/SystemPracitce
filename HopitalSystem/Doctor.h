//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_DOCTOR_H
#define COEN244_ASS4_DOCTOR_H

#include "Person.h"
#include "InPatient.h"
#include <string>
#include <vector>


class Doctor : public Person {

public:

    Doctor(std::string name, std::string ML, std::string spec) :
        Person(name), medicalLicense(ML), specificity(spec) {}

    ~Doctor();
    std::string getMedicalLicense() const { return medicalLicense; }
    std::string getSpecificity() const {return specificity;}

    void print() const;
    void printWithPatients() const;

    void addPatient(Patient* patient);  //in here we will make a copy of the patients
    // just in case they get deleted from the hospital's system
    // the doctor can keep their own record of their patients
    // which means we need to delete these patients when we destruct the doctor
protected:
    std::string medicalLicense;
    std::string specificity;
    std::vector<Patient*> patients; //to hold pointers of all doctor's patients (in and out)

};


#endif //COEN244_ASS4_DOCTOR_H
