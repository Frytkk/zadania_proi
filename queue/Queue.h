//
// Created by Artur Kempiński on 22/03/2023.
//

#pragma once

#include <map>
#include <queue>
#include "Doctor.h"
#include "Patient.h"

using number = unsigned short;

class Queue {
private:
    Doctor doctor_;
    std::map<number, Patient> patients_;
    std::deque<number> availableQueueNumbers_;
    number maxQueueSize_;
public:
    Queue(const Doctor& doctor, number maxQueueSize);
    Doctor getDoctor() const;
    void setDoctor(const Doctor& newDoctor);
    void addPatient(const Patient& newPatient);
    void delPatient(number queueNumber);
    Patient getPatient(number queueNumber) const;
    bool isPatientInQueue(const Patient& patientToCheck) const;
    unsigned short getPatientsOfAge(age ageToCheck) const;
    unsigned short getPatientsOfGender(Gender genderToCheck) const;
    std::vector<Patient> getPatientsSortedByAge() const;
    void addPatientWithNumber(const Patient& patient, number patientNumber);
};

Queue readQueueFromCSV(const std::string& fileName);
std::vector<unsigned short> stringVectorToShort(const std::vector<std::string>& stringVector);
