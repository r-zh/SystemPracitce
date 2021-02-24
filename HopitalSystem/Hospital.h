//
// Created by tawfiq on 2020-04-06.
//

#ifndef COEN244_ASS4_HOSPITAL_H
#define COEN244_ASS4_HOSPITAL_H


#include <array>
#include "Bed.h"
#include "Doctor.h"
#include "OutPatient.h"

class Hospital {

public:
    Hospital() : beds({{nullptr}}), doctors({{nullptr}}), inPatients({{nullptr}}), outPatients({{nullptr}}) {}
    ~Hospital();

    bool addDoctor(std::string name, std::string ML, std::string spec);
    bool removeDoctor(std::string ML);

    //returns the ID of the patient, -1 for error adding patient
    int addInpatient(const std::string &name, const Date &addmissionDate, const Date &dischargeDate, int bedNumber,
                      double dailyCharge);
    bool removeInPatient(int id);

    //returns the ID of the patient, -1 for error adding patient
    int addOutpatient(const std::string &name, const Date &appointmentDate, const Time &appointmentTime);
    bool removeOutPatient(int id);

    bool addBed();

    bool assignBed(int inPatientID, int bedID);
    int getRandomAvailableBed() const;
    bool isBedAvailable(int bedID) const ;
    bool setBedAvailibility(int bedID, bool isAvailable) const;
    bool assignDoctorToPatient(const std::string& medicalLicense, int patientID, bool isInPatient);

    void printAllInPatients() const;
    void printAllOutPatients() const;
    void printAllDoctors(bool withPatients=false) const;
    void printAllAvailableBeds() const;

    void printDoctorByML(std::string ML, bool withPatients = false);

    int getNumberOfAvailableBeds() const;
    int getNumberOfTotalBeds() const;
    int getNumberOfDoctors() const;
    int getNumberOfInPatients() const;
    int getNumberOfOutPatients() const;

private:
    //max numbers
    const static int maxNumberOfBeds = 500;
    const static int maxNumberOfDoctors = 100;
    const static int maxNumberOfPatients = 500;

    std::array<Bed*, maxNumberOfBeds> beds;
    std::array<Doctor*, maxNumberOfDoctors> doctors;
    std::array<InPatient*, maxNumberOfPatients> inPatients;
    std::array<OutPatient*, maxNumberOfPatients> outPatients;

    //counters to generate unique IDs for patients and beds
    int inPatientIDCounter = -1;
    int outPatientIDCounter = -1;
    int bedIDCounter = -1;



};


#endif //COEN244_ASS4_HOSPITAL_H
