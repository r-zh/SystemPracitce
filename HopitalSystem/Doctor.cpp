//
// Created by tawfiq on 2020-04-06.
//

#include "Doctor.h"
#include "InPatient.h"
#include "OutPatient.h"
#include <iostream>

Doctor::~Doctor()
{
    for(auto patient : patients)
        delete patient; //this assumes that all the patients in the vector are valid objects
        //it is the case, because only the doctor has access to these objects that are copied when the patient is added
}

void Doctor::print() const
{
    std::cout << "name: " << name << "\nMedical License: " << medicalLicense
        << "\nSpecificity: " << specificity << "\nNumber of Patients: " << patients.size() << "\n";

}

void Doctor::printWithPatients() const {
    print();
    std::cout << "Patients: \n";
    //this assumes that all the pointers in the vector are valid patients
    for(auto patient : patients)
        patient->print();
    std::cout << "\n";

}

void Doctor::addPatient(Patient *patient) {
    if(auto inpatient = dynamic_cast<InPatient*>(patient))
        patients.push_back(new InPatient(*inpatient));
    else if(auto outpatient = dynamic_cast<OutPatient*>(patient))
        patients.push_back(new OutPatient(*outpatient));
}
