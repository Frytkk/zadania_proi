#include "paramedic.h"

Paramedic::Paramedic(std::string first_name, std::string surname, std::string id_number,
    unsigned int years_of_experience, bool has_paramedic_degree)
    : Employee(first_name, surname, id_number), years_of_experience(years_of_experience),
        has_paramedic_degree(has_paramedic_degree)
{}

Paramedic::~Paramedic() {}

unsigned int Paramedic::get_years_of_experience() const {
    return years_of_experience;
}

bool Paramedic::get_has_paramedic_degree() const {
    return has_paramedic_degree;
}

void Paramedic::set_years_of_experience(unsigned int years_of_experience) {
    this->years_of_experience = years_of_experience;
}

void Paramedic::set_has_paramedic_degree(bool has_paramedic_degree) {
    this->has_paramedic_degree = has_paramedic_degree;
}

double Paramedic::calculate_salary() const {
    double salary = base_salary;

    if (has_paramedic_degree) {
        salary += emt_degree_bonus;
    }

    salary += experience_bonus * years_of_experience;

    return salary;
}

void Paramedic::print(std::ostream& os) const{
    os << *this;
}
