//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_OUTPATIENT_H
#define COEN244_ASS4_OUTPATIENT_H


#include "Date.h"
#include "Time.h"
#include "Patient.h"


class OutPatient : public Patient {
public:
    OutPatient(int id, const std::string &name, const Date &appointmentDate, const Time &appointmentTime) : Patient(id, name),
        appointmentDate(appointmentDate),
        appointmentTime(appointmentTime) {}

    //public methods
    virtual void print() const;


    //getters and setters
    const Date &getAppointmentDate() const {
        return appointmentDate;
    }

    void setAppointmentDate(const Date &appointmentDate) {
        OutPatient::appointmentDate = appointmentDate;
    }

    const Time &getAppointmentTime() const {
        return appointmentTime;
    }

    void setAppointmentTime(const Time &appointmentTime) {
        OutPatient::appointmentTime = appointmentTime;
    }

protected:
    Date appointmentDate;
    Time appointmentTime;
};


#endif //COEN244_ASS4_OUTPATIENT_H
