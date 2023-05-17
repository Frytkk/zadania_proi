#include "employee.h"

#include <iostream>

Employee::Employee(std::string first_name, std::string surname, std::string id_number)
    : first_name(first_name), surname(surname), id_number(id_number) {}

Employee::~Employee() {}

std::string Employee::get_first_name() const {
    return first_name;
}

std::string Employee::get_surname() const {
    return surname;
}

std::string Employee::get_id_number() const {
    return id_number;
}


void Employee::set_first_name(std::string first_name) {
    this->first_name = first_name;
}

void Employee::set_surname(std::string surname) {
    this->surname = surname;
}

void Employee::set_id_number(std::string id_number) {
    this->id_number = id_number;
}

void Employee::print(std::ostream& os) const{
    os << *this;
}

double Employee::calculate_salary() const {
    return 0.0;
}


std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os << "ID: " << employee.id_number << ", Name: " << employee.first_name << ", Surname: " << employee.surname << std::endl;
    return os;
}

bool Employee::operator==(const Employee& other) const {
    return (first_name == other.first_name && surname == other.surname && id_number == other.id_number);
}