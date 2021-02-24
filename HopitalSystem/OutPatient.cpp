//
// Created by tawfiq on 2020-04-06.
//

#include "OutPatient.h"
#include "Doctor.h"

void OutPatient::print() const {
    std::cout << "id: " << id  <<"\nname: " << name << "\n" << "Appointment Date: ";
    appointmentDate.print();
    std::cout << "\nAppointment Time: ";
    appointmentTime.print();
    std::cout << "\nDoctor: ";
    if(doctor!= nullptr)
        doctor->print();
    else
        std::cout << "doctor not assigned\n";
}
