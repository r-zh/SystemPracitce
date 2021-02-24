//
// Created by tawfiq on 2020-04-06.
//

#include "InPatient.h"
#include "Doctor.h"

void InPatient::print() const {

    std::cout << "id: " << id  <<"\nname: " << name << "\n" << "Admission Date: ";
    addmissionDate.print();
    std::cout << "\nDischarge Date: ";
    dischargeDate.print();
    std::cout << "\nBed number: " << bedNumber << "\nDaily charge: " << dailyCharge << "\nDoctor: ";
    if(doctor!= nullptr)
        doctor->print();
    else
        std::cout << "doctor not assigned\n";
}
