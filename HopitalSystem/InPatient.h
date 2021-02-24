//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_INPATIENT_H
#define COEN244_ASS4_INPATIENT_H

#include "Patient.h"
#include "Date.h"


class InPatient : public Patient{
public:

    InPatient(int id, const std::string &name, const Date &addmissionDate, const Date &dischargeDate, int bedNumber,
              double dailyCharge) : Patient(id, name), addmissionDate(addmissionDate), dischargeDate(dischargeDate),
                                    bedNumber(bedNumber), dailyCharge(dailyCharge) {}

    //public methods
    virtual void print() const;



    //getters and setters
    const Date &getAddmissionDate() const {
        return addmissionDate;
    }

    void setAddmissionDate(const Date &addmissionDate) {
        InPatient::addmissionDate = addmissionDate;
    }

    const Date &getDischargeDate() const {
        return dischargeDate;
    }

    void setDischargeDate(const Date &dischargeDate) {
        InPatient::dischargeDate = dischargeDate;
    }

    int getBedNumber() const {
        return bedNumber;
    }

    void setBedNumber(int bedNumber) {
        InPatient::bedNumber = bedNumber;
    }

    double getDailyCharge() const {
        return dailyCharge;
    }

    void setDailyCharge(double dailyCharge) {
        InPatient::dailyCharge = dailyCharge;
    }

protected:

    Date addmissionDate;
    Date dischargeDate;
    int bedNumber;
    double dailyCharge;


};


#endif //COEN244_ASS4_INPATIENT_H
