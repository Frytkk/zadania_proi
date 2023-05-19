//
// Created by Artur Kempiński on 22/03/2023.
//

#include "Patient.h"


Patient::Patient(const std::string& name, Gender gender, age age): name_(name), gender_(gender), age_(age) {}

std::string Patient::getName() const {
    return name_;
}

Gender Patient::getGender() const {
    return gender_;
}

age Patient::getAge() const {
    return age_;
}

bool Patient::operator==(const Patient &other) const {
    bool isNameEqual = name_ == other.getName();
    bool isGenderEqual = gender_ == other.getGender();
    bool isAgeEqual = age_ == other.getAge();
    return isNameEqual && isGenderEqual && isAgeEqual;
}