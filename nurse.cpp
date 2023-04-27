#include "nurse.h"

#include <stdexcept>

Nurse::Nurse(std::string first_name, std::string surname, std::string id_number,
    unsigned int years_of_experience, bool has_nursing_degree)
    : Employee(first_name, surname, id_number), years_of_experience(years_of_experience),
      has_nursing_degree(has_nursing_degree) {}

Nurse::~Nurse() {}

unsigned int Nurse::get_years_of_experience() const {
    return years_of_experience;
}

bool Nurse::get_has_nursing_degree() const {
    return has_nursing_degree;
}

void Nurse::set_years_of_experience(unsigned int years_of_experience) {
    this->years_of_experience = years_of_experience;
}

void Nurse::set_has_nursing_degree(bool has_nursing_degree) {
    this->has_nursing_degree = has_nursing_degree;
}

double Nurse::calculate_salary() const {
    double salary = base_salary;

    if (has_nursing_degree) {
        salary += nursing_degree_bonus;
    }

    salary += years_of_experience * experience_bonus;

    return salary;
}

void Nurse::print(std::ostream& os) const{
    os << *this;
}

std::ostream& operator<<(std::ostream& os, const Nurse& nurse) {
    os << static_cast<std::string>("Nurse: ") << nurse.get_first_name() << static_cast<std::string>(" ") << nurse.get_surname() << static_cast<std::string>(" (ID: ") << nurse.get_id_number() << static_cast<std::string>(")\n");
    os << static_cast<std::string>("Years of experience: ") << std::to_string(nurse.get_years_of_experience()) << static_cast<std::string>("\n");
    os << static_cast<std::string>("Has nursing degree: ") << static_cast<std::string>(nurse.get_has_nursing_degree() ? "Yes" : "No") << static_cast<std::string>("\n");
    os << static_cast<std::string>("Salary: ") << std::to_string(nurse.calculate_salary()) << static_cast<std::string>("\n");

    return os;
}
