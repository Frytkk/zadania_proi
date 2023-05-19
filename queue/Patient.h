//
// Created by Artur Kempiński on 22/03/2023.
//

#pragma once


#include <string>


enum class Gender { male, female };

using age = unsigned short;

class Patient {
private:
    std::string name_;
    Gender gender_;
    age age_;

public:
    Patient(const std::string& name, Gender gender, age age);
    std::string getName() const;
    Gender getGender() const;
    age getAge() const;
    bool operator==(const Patient& other) const;
};
