//
// Created by tawfiq on 2020-04-06.
//

#include "Hospital.h"


Hospital::~Hospital() {

    for (auto bed : beds)
        if(bed != nullptr)
            delete bed;

    for(auto inPatient : inPatients)
        if(inPatient != nullptr)
            delete inPatient;

    for(auto outPatient : outPatients)
        if(outPatient != nullptr)
            delete outPatient;

    for(auto doctor : doctors)
        if(doctor != nullptr)
            delete doctor;
}

int Hospital::getNumberOfTotalBeds() const {
    //count how many beds exist
    int count = 0;
    for(const auto& bed : beds)
        if(bed != nullptr)
            count++;
    return count;
}

int Hospital::getNumberOfAvailableBeds() const {
    //count how many beds are avaialble
    int count = 0;
    for(const auto& bed : beds)
        if(bed != nullptr && bed->isAvailable)
            count++;
    return count;
}


int Hospital::getNumberOfDoctors() const {
    int count = 0;
    for(const auto& doctor : doctors)
        if(doctor != nullptr)
            count++;
    return count;
}

int Hospital::getNumberOfInPatients() const {
    int count = 0;
    for(const auto& inpatient : inPatients)
        if(inpatient != nullptr)
            count++;
    return count;
}

int Hospital::getNumberOfOutPatients() const {
    int count = 0;
    for(const auto& outpatient : outPatients)
        if(outpatient != nullptr)
            count++;
    return count;
}

bool Hospital::addDoctor(std::string name, std::string ML, std::string spec) {

    //find an empty place in the array to insert the new doctor
    for(auto& doctor : doctors)
    {
        if(doctor == nullptr)
        {
            doctor = new Doctor(name, ML, spec);
            return true;
        }

    }
    return false;
}

int Hospital::addInpatient(const std::string &name, const Date &addmissionDate, const Date &dischargeDate, int bedNumber,
                       double dailyCharge) {

    //check if the bed is available
    if(!isBedAvailable(bedNumber))
        return false;

    for(auto& patient : inPatients)
    {
        if(patient == nullptr)
        {
            inPatientIDCounter++;   //increment the unique ID counter
            patient = new InPatient(inPatientIDCounter, name, addmissionDate, dischargeDate, bedNumber, dailyCharge);
            setBedAvailibility(bedNumber, false);
            return true;
        }
    }

    return false;
}

int Hospital::getRandomAvailableBed() const {
    for(const auto& bed : beds)
        if(bed != nullptr && bed->isAvailable)
            return bed->id;

    return -1;
}

bool Hospital::isBedAvailable(int bedID) const {
    for(const auto& bed : beds)
        if(bed != nullptr && bed->id==bedID)
            return bed->isAvailable;

    return false;
}

bool Hospital::setBedAvailibility(int bedID, bool isAvailable) const {
    for(const auto& bed : beds)
        if(bed != nullptr && bed->id==bedID)
        {
            bed->isAvailable = isAvailable;
            return true;
        }

    return false;
}

bool Hospital::addBed() {

    for(auto& bed : beds)
    {
        if(bed == nullptr)
        {
            bedIDCounter++;
            bed = new Bed(bedIDCounter);
            return true;
        }
    }

    return false;
}

int Hospital::addOutpatient(const std::string &name, const Date &appointmentDate, const Time &appointmentTime) {
    for(auto& patient : outPatients)
    {
        if(patient == nullptr)
        {
            outPatientIDCounter++;   //increment the unique ID counter
            patient = new OutPatient(outPatientIDCounter, name, appointmentDate, appointmentTime);
            return true;
        }
    }
    return false;
}

bool Hospital::assignBed(int inPatientID, int bedID) {
    if(!isBedAvailable(bedID))
        return false;

    for(auto& patient : inPatients)
    {
        if(patient != nullptr && patient->getID() == inPatientID)
        {
            int tempBed = patient->getBedNumber();  //save bed number to make it available again
            patient->setBedNumber(bedID);
            setBedAvailibility(bedID, false);
            setBedAvailibility(tempBed, true);
            return true;

        }
    }
    return false;
}

bool Hospital::assignDoctorToPatient(const std::string &medicalLicense, int patientID, bool isInPatient) {
    //find if doctor is available
    Doctor *doctor = nullptr;
    for (auto &doc : doctors) {
        if (doc != nullptr && doc->getMedicalLicense() == medicalLicense) {
            doctor = doc;
            break;
        }
    }
    if (doctor == nullptr)
        return false;

    Patient *patient = nullptr;
    //find patient
    if (isInPatient) {
        for (auto &inpatient : inPatients) {
            if (inpatient != nullptr && inpatient->getID() == patientID) {
                patient = inpatient;
                break;
            }
        }
        if (patient == nullptr)
            return false;
    } else
    {
        for (auto &outpatient : outPatients) {
            if (outpatient != nullptr && outpatient->getID() == patientID) {
                patient = outpatient;
                break;
            }
        }
        if (patient == nullptr)
            return false;
    }

    //now we have the doctor and we have the patient
    //set doctor to patient
    patient->setDoctor(doctor);
    //add patient to doctor's list of patients
    doctor->addPatient(patient);


    return true;
}

bool Hospital::removeDoctor(std::string ML) {
    for(auto& doctor : doctors)
    {
        if(doctor != nullptr && doctor->getMedicalLicense() == ML)
        {
            //first find all patients in and out that has this doctor assigned,
            // and make their doctor nullptr

            //inpatients
            for(auto& in : inPatients)
            {
                if(in != nullptr && in->getDoctor() != nullptr && in->getDoctor()->getMedicalLicense()==ML)
                    in->setDoctor(nullptr);
            }

            //outpatients
            for(auto& out : outPatients)
            {
                if(out != nullptr && out->getDoctor() != nullptr && out->getDoctor()->getMedicalLicense()==ML)
                    out->setDoctor(nullptr);
            }

            //now we can delete the doctor
            delete doctor;
            //assign nullptr in the doctors array
            doctor = nullptr;
            return true;
        }
    }
    return false;
}

bool Hospital::removeInPatient(int id) {
    for (auto &inpatient : inPatients) {
        if (inpatient != nullptr && inpatient->getID() == id) {
            //first make the bed available
            setBedAvailibility(inpatient->getBedNumber(), true);
            //then delete the inpatient object
            delete inpatient;
            //now assign nullptr in the array
            inpatient = nullptr;
            return true;
        }
    }
    return false;
}


bool Hospital::removeOutPatient(int id) {
    for (auto &outpatient : outPatients) {
        if (outpatient != nullptr && outpatient->getID() == id) {
            //delete the inpatient object
            delete outpatient;
            //now assign nullptr in the array
            outpatient = nullptr;
            return true;
        }
    }
    return false;
}


void Hospital::printAllInPatients() const {
    std::cout << "InPatients: \n";

    for(const auto& inpatient : inPatients)
        if(inpatient != nullptr)
            inpatient->print();

    std::cout << "\n";
}

void Hospital::printAllOutPatients() const {
    std::cout << "OutPatients: \n";
    for(const auto& outpatient : outPatients)
        if(outpatient != nullptr)
            outpatient->print();

    std::cout << "\n";
}

void Hospital::printAllDoctors(bool withPatients) const
{
    std::cout << "Doctors:\n";
    for(const auto& doctor : doctors)
    {
        if(doctor != nullptr)
        {
            if(withPatients)
                doctor->printWithPatients();
            else
                doctor->print();
        }
    }
    std::cout << "\n";
}

void Hospital::printAllAvailableBeds() const {
    std::cout << "Available Beds: \n";
    for(const auto& bed : beds)
        if(bed != nullptr && bed->isAvailable)
            std::cout << bed->id << "\n";
}

void Hospital::printDoctorByML(std::string ML, bool withPatients) {
    for (auto &doc : doctors) {
        if (doc != nullptr && doc->getMedicalLicense() == ML) {
           if(withPatients)
               doc->printWithPatients();
           else
               doc->print();

           break;
        }
    }
}



