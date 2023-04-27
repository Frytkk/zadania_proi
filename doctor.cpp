#include "doctor.h"
#include "specialization.h"
#include "specialization_not_found_exception.h"

Doctor::Doctor(std::string name, std::string surname, std::string id_number,
    std::string specialization, unsigned int years_of_experience)
    : Employee(name, surname, id_number), specialization(specialization), years_of_experience(years_of_experience) {

    if (Specialization::get_value_ptr(specialization) == nullptr) {
        throw SpecializationNotFoundException(specialization);
    }
}

Doctor::~Doctor() {}

std::string Doctor::get_specialization() const {
    return specialization;
}

unsigned int Doctor::get_years_of_experience() const {
    return years_of_experience;
}

void Doctor::set_specialization(std::string specialization) {
    if (Specialization::get_value_ptr(specialization) == nullptr) {
        throw SpecializationNotFoundException(specialization);
    }
    this->specialization = specialization;
}

void Doctor::set_years_of_experience(unsigned int years_of_experience) {
    this->years_of_experience = years_of_experience;
}

double Doctor::calculate_salary() const {
    return base_salary + (*Specialization::get_value_ptr(specialization) * years_of_experience);
}

void Doctor::print(std::ostream& os) const{
    os << *this;
}

std::ostream& operator<<(std::ostream& os, const Doctor& doctor) {
    os << static_cast<std::string>("Doctor: ") <<static_cast<std::string> (doctor.get_first_name()) << static_cast<std::string>(" ") << doctor.get_surname() << static_cast<std::string>(" (ID: ") << doctor.get_id_number() << static_cast<std::string>(")\n");
    os << static_cast<std::string>("Specialization: ") << doctor.get_specialization() << static_cast<std::string>("\n");
    os << static_cast<std::string>("Years of experience: ") << std::to_string(doctor.get_years_of_experience()) << static_cast<std::string>("\n");
    os << static_cast<std::string>("Salary: ") << std::to_string(doctor.calculate_salary()) << static_cast<std::string>("\n");
    return os;
}
