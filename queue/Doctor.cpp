//
// Created by Artur Kempiński on 22/03/2023.
//

#include "Doctor.h"
#include <ranges>


Doctor::Doctor(const std::string& name, const std::vector<std::string>& specializations):
    name_(name), specializations_(specializations)  {}

std::string Doctor::getName() const {
    return name_;
}

std::vector<std::string> Doctor::getSpecializations() const {
    std::vector<std::string> sortedSpec = specializations_;
    std::ranges::sort(sortedSpec);
    return sortedSpec;
}

void Doctor::addSpecialization(std::string newSpecialization) {
    specializations_.push_back(newSpecialization);
}

void Doctor::delSpecialization(std::string delSpecialization) {
    auto it = std::ranges::find(specializations_, delSpecialization);
    if (it != specializations_.end())
        specializations_.erase(it);
    else
        throw std::out_of_range("Given specialization is not in doctor's specializations");
}