#include <iostream>
#include "Doctor.h"
#include "Hospital.h"

#define line "\n------------------------------\n"

/*
 *Perosn: name
 *  - Patient : unique ID, Doctor who provided service
 *
 *      -- inpatient:
 *          admitted to the hospital and assignned a bed
 *          if no available beds -> patient cant be admitted
 *          hospital charges: daily rate for the duration of their stay
 *          memebers:
 *              Admission date
 *              Discharge date
 *              int bed number
 *              double daily charge
 *      -- outpatient:
 *          appointment for the present day with a doctor
 *          fixed fee charge by the hospital per visit
 *
 *          members:
 *              Appoitment date and time
 *  - Doctors:
 *          medical license number (string)
 *          specificity (string)
 *          patients
 *
 * Beds:
 *      - unique ID
 *      - flag isAvailable
 *
 *
 * Hospital:
 *      - all beds (500) in the hospital
 *      - all doctors (max 100)
 *      - all inpatients (max 500)
 *
 */
int main() {

    {
        std::cout << line << "Testing Adding Doctors" << line;
        Hospital hospital;

        for(int i = 0; i < 101; i++)
        {
            if(!hospital.addDoctor("DName2", "DML2", "DSpec2"))
                std::cout << "at i: " << i << " adding doctor returned false";

        }
    }


    {
        std::cout << line << "Testing Adding InPatients" << line;

        Hospital hospital;

        std::cout << line << "With Unavailable Bed Number" << line;

        if(!hospital.addInpatient("inpatient1", Date(1,1,2020),Date(1,5,2020), 10, 100))
            std::cout << "inPatient not admitted\n";

        std::cout << line << "With Available Bed Number" << line;
        hospital.addBed();
        if(hospital.addInpatient("inpatient1", Date(1,1,2020),Date(1,5,2020), hospital.getRandomAvailableBed(), 100))
            std::cout << "inPatient admitted successfully\n";

        std::cout << line << "Testing Adding OutPatients" << line;
        if(hospital.addOutpatient("outpatient1", Date(1,1,2020), Time(13,0)))
            std::cout << "outpatient successfully added\n";

        std::cout << line << "Testing assigning new Bed to InPatients \nwithout having bed available " << line;
        if(!hospital.assignBed(0,1))
            std::cout << "was not able to assign bed\n";

        std::cout << line << "Testing assigning new Bed to InPatients (bed 0) \nwith having bed available (bed 1) " << line;
        hospital.addBed();
        if(hospital.assignBed(0,1))
            std::cout << "was able to assign bed\n";
        if(hospital.isBedAvailable(0))
            std::cout << "bed 0 is available now\n";
        if(!hospital.isBedAvailable(1))
            std::cout << "bed 1 is not available now\n";


        std::cout << line << "Testing assigning doctor to inpatient (0) " << line;

        std::cout << line << "with unavailable doctor ML " << line;
        if(!hospital.assignDoctorToPatient("wrongML", 0, true))
            std::cout << "not able to assign doctor\n";

        std::cout << line << "add new doctor (DML1) and assign again " << line;
        hospital.addDoctor("DName1", "DML1", "DSpec1");
        std::cout << "All Hospital Information: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();

        hospital.assignDoctorToPatient("DML1", 0, true);

        std::cout << line << "Hospital information after assigning: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();


        std::cout << line << "Testing assigning doctor to outpatient (0) " << line;

        std::cout << line << "with unavailable doctor ML " << line;
        if(!hospital.assignDoctorToPatient("wrongML", 0, false))
            std::cout << "not able to assign doctor\n";

        std::cout << line << "add new doctor (DML2) and assign again " << line;
        hospital.addDoctor("DName2", "DML2", "DSpec2");
        std::cout << "All Hospital Information: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();

        hospital.assignDoctorToPatient("DML2", 0, false);

        std::cout << line << "Hospital information after assigning: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();

        std::cout << line << "Testing removing non existent Doctor " << line;
        if(!hospital.removeDoctor("wrongML"))
            std::cout << "returns false\n";

        std::cout << line << "Testing removing Doctor (DML1) " << line;
        hospital.removeDoctor("DML1");
        std::cout << line << "Hospital information after removing: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();

        std::cout << line << "Testing removing Doctor (DML2) " << line;
        hospital.removeDoctor("DML2");
        std::cout << line << "Hospital information after removing: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();


        std::cout << line << "Testing removing inpatient (0) " << line;
        std::cout << "before removing: ";
        hospital.printAllAvailableBeds();

        hospital.removeInPatient(0);

        std::cout << line << "All Hospital Information after removing: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();
        hospital.printAllAvailableBeds();

        std::cout << line << "removing inpatient (0) again" << line;
        if(!hospital.removeInPatient(0))
            std::cout << "returns false\n";


        std::cout << line << "Testing removing outpatient (0) " << line;

        hospital.removeOutPatient(0);

        std::cout << line << "All Hospital Information after removing: \n";
        hospital.printAllDoctors(true);
        hospital.printAllInPatients();
        hospital.printAllOutPatients();
        hospital.printAllAvailableBeds();

        std::cout << line << "removing outpatient (0) again" << line;
        if(!hospital.removeOutPatient(0))
            std::cout << "returns false\n";

    }




    return 0;
}
