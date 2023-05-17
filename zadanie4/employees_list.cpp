#include "employees_list.h"
#include <algorithm>


void EmployeesList::add_employee(std::unique_ptr<Employee> employee) {
    employees.push_back(std::move(employee));
}

void EmployeesList::add_doctor(std::unique_ptr<Doctor> doctor) {
    employees.push_back(std::move(doctor));
}

void EmployeesList::add_nurse(std::unique_ptr<Nurse> nurse) {
    employees.push_back(std::move(nurse));
}

void EmployeesList::add_paramedic(std::unique_ptr<Paramedic> paramedic) {
    employees.push_back(std::move(paramedic));
}


void EmployeesList::remove_employee(const Employee& employee) {
    auto it = find_employee(employee);
    if (it != employees.end()) {
        employees.erase(it);
    }
}

void EmployeesList::remove_employee_by_id(const std::string& id_number) {
    auto it = find_employee_by_id(id_number);
    if (it != employees.end()) {
        employees.erase(it);
    }
}


std::list<std::unique_ptr<Employee>>::iterator EmployeesList::find_employee(const Employee& employee) {
    return std::find_if(employees.begin(), employees.end(),
        [&](const std::unique_ptr<Employee>& emp_ptr) {
            return *emp_ptr == employee;
        });
}


std::list<std::unique_ptr<Employee>>::iterator EmployeesList::find_employee_by_id(const std::string& id_number) {
    return std::find_if(employees.begin(), employees.end(),
        [&](const std::unique_ptr<Employee>& emp_ptr) {
            return emp_ptr->get_id_number() == id_number;
        });
}

const std::list<std::unique_ptr<Employee>>& EmployeesList::get_employees_list() const{
    return employees;
}


double EmployeesList::calculate_whole_salary() {
    double total_salary = 0.0;
    for (const auto& emp : employees) {
        total_salary += emp->calculate_salary();
    }
    return total_salary;
}


std::ostream& EmployeesList::show_information(std::ostream& os) const {
    for (const auto& emp : employees) {
        emp->print(os);
    }
    return os;
}
