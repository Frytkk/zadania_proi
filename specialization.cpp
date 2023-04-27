#include "specialization.h"


std::map<std::string, unsigned int> Specialization::specializations = {
    {"pediatrician", 10},
    {"cardiologist", 20},
    {"dermatologist", 15},
    {"gynecologist", 25},
    {"neurologist", 10}
};

void Specialization::add_specialization(const std::string& name, unsigned int value) {
    if (get_value_ptr(name) != nullptr) {
        throw std::invalid_argument("Specialization already exists");
    }
    specializations[name] = value;
}

void Specialization::remove_specialization(const std::string& name) {
    if (get_value_ptr(name) == nullptr) {
        throw std::invalid_argument("Specialization does not exist");
    }
    specializations.erase(name);
}

unsigned int* Specialization::get_value_ptr(const std::string& name) {
    auto it = specializations.find(name);
    if (it != specializations.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
}

unsigned int Specialization::get_value(const std::string& name) {
    unsigned int* value_ptr = get_value_ptr(name);
    if (value_ptr == nullptr) {
        throw std::invalid_argument("Specialization does not exist");
    }
    return *value_ptr;
}
