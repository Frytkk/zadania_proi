#pragma once

#include <memory>
#include <list>
#include "employee.h"
#include "doctor.h"
#include "nurse.h"
#include "paramedic.h"

class EmployeesList {
    private:
        std::list<std::unique_ptr<Employee>> employees;

    public:
        void add_employee(std::unique_ptr<Employee> employee);
        void add_doctor(std::unique_ptr<Doctor> doctor);
        void add_nurse(std::unique_ptr<Nurse> nurse);
        void add_paramedic(std::unique_ptr<Paramedic> paramedic);

        void remove_employee(const Employee& employee);
        void remove_employee_by_id(const std::string& id_number);

        double calculate_whole_salary();

        std::ostream& show_information(std::ostream& os) const;

        std::list<std::unique_ptr<Employee>>::iterator find_employee(const Employee& employee);
        std::list<std::unique_ptr<Employee>>::iterator find_employee_by_id(const std::string& id_number);
};
