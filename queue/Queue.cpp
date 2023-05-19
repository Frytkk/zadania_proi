//
// Created by Artur Kempiński on 22/03/2023.
//

#include <numeric>
#include <map>
#include "Queue.h"
#include "rapidcsv.h"
#include <unordered_set>
#include <string>

std::map<std::string,Gender> stringToGender = {
        {"Male", Gender::male},
        {"Female", Gender::female}
};


std::vector<unsigned short> stringVectorToShort(const std::vector<std::string>& stringVector) {
    std::vector<unsigned short> shortVector;
    for (const auto& string : stringVector)
        shortVector.push_back(std::stoi(string));
    return shortVector;
};



Queue::Queue(const Doctor& doctor, number maxQueueSize):
    doctor_(doctor), maxQueueSize_(maxQueueSize) {
    for (number i = 1; i <= maxQueueSize_; i++)
        availableQueueNumbers_.push_back(i);
}

Doctor Queue::getDoctor() const {
    return doctor_;
}

void Queue::setDoctor(const Doctor& newDoctor) {
    doctor_ = newDoctor;
}

void Queue::addPatient(const Patient& newPatient) {
    if (availableQueueNumbers_.empty())
        throw std::length_error("Max amount of patient reached, couldn't add a new one");
    number newQueueNumber = availableQueueNumbers_.front();
    availableQueueNumbers_.pop_front();
    patients_.insert({newQueueNumber, newPatient});
}

void Queue::delPatient(number queueNumber) {
    if(!patients_.erase(queueNumber))
        throw std::out_of_range("There is no patient with given number in the queue");
    availableQueueNumbers_.push_back(queueNumber);
}

Patient Queue::getPatient(number queueNumber) const {
    return patients_.at(queueNumber);
}

bool Queue::isPatientInQueue(const Patient &patientToCheck) const {
    return std::any_of(patients_.begin(), patients_.end(),
                       [patientToCheck](const auto& patient) -> bool {
        return patient.second == patientToCheck;
    });
}

unsigned short Queue::getPatientsOfAge(age ageToCheck) const {
    return std::accumulate(patients_.begin(), patients_.end(),0,
                           [ageToCheck](unsigned short sum, const auto& patient) -> unsigned short {
        return patient.second.getAge() == ageToCheck ? sum + 1 : sum;
    });
}

unsigned short Queue::getPatientsOfGender(Gender genderToCheck) const {
    return std::accumulate(patients_.begin(), patients_.end(), 0,
                           [genderToCheck](unsigned short sum, const auto& patient) -> unsigned short {
        return patient.second.getGender() == genderToCheck ? sum + 1 : sum;
    });
}

std::vector<Patient> Queue::getPatientsSortedByAge() const {
    std::vector<Patient> patients;
    for (const auto& patient : patients_)
        patients.push_back(patient.second);
    std::sort(patients.begin(), patients.end(),
              [](const Patient& patient1, const Patient& patient2) -> bool {
        return patient1.getAge() < patient2.getAge();
    });
    return patients;
}

void Queue::addPatientWithNumber(const Patient& patient, number patientNumber) {
    if (std::ranges::find(availableQueueNumbers_, patientNumber) == availableQueueNumbers_.end())
        throw std::out_of_range("Given number is not available");
    patients_.insert({patientNumber, patient});
    availableQueueNumbers_.erase(std::ranges::find(availableQueueNumbers_, patientNumber));
}


Queue readQueueFromCSV(const std::string& fileName) {
    rapidcsv::Document doc(fileName);
    std::string doctorName = doc.GetColumn<std::string>("doctorName")[0];
    std::vector<std::string> specializations = doc.GetColumn<std::string>("doctorSpecialzations");

    std::unordered_set<std::string> s(specializations.begin(), specializations.end());
    specializations.assign(s.begin(), s.end());

    Doctor doctor(doctorName, specializations);

    number maxQueueSize = std::stoi(doc.GetColumn<std::string>("maxQueueSize")[0]);
    Queue queue(doctor, maxQueueSize);

    std::vector<number> queueNumbers = stringVectorToShort(doc.GetColumn<std::string>("queueNumber"));
    std::vector<std::string> patientNames = doc.GetColumn<std::string>("patientName");
    std::vector<age> patientAges = stringVectorToShort(doc.GetColumn<std::string>("patientAge"));
    std::vector<std::string> patientGenders = doc.GetColumn<std::string>("patientGender");

    for (size_t i = 0; i < queueNumbers.size(); i++) {
        std::string patientName = patientNames[i];
        age patientAge = patientAges[i];
        Gender patientGender = stringToGender[patientGenders[i]];
        number patientNumber = queueNumbers[i];
        Patient patient(patientName, patientGender, patientAge);
        queue.addPatientWithNumber(patient, patientNumber);
    }
    return queue;
}