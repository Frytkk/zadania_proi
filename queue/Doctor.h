//
// Created by Artur Kempiński on 22/03/2023.
//

#pragma once


#include <string>
#include <vector>

class Doctor {
private:
    std::string name_;
    std::vector<std::string> specializations_;
public:
    Doctor(const std::string& name, const std::vector<std::string>& specializations);
    std::string getName() const;
    void addSpecialization(std::string newSpecialization);
    void delSpecialization(std::string delSpecialization);
    std::vector<std::string> getSpecializations() const;
};
