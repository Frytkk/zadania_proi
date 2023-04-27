#include <iostream>
#include <string>
#include <memory>
#include "employees_list.h"
#include "doctor.h"
#include "nurse.h"
#include "paramedic.h"

int main() {
    EmployeesList employees_list;
    int option;
    do {
        std::cout << "\nMenu:\n"
            << "1. Add Doctor\n"
            << "2. Add Nurse\n"
            << "3. Add Paramedic\n"
            << "4. Remove Employee\n"
            << "5. Show Whole Salary\n"
            << "6. Show All Employees\n"
            << "7. Exit\n"
            << "Choose an option: ";
        std::cin >> option;

        if (option == 1) {
            std::string name, surname, id_number, specialization;
            unsigned int years_of_experience;

            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter surname: ";
            std::cin >> surname;
            std::cout << "Enter ID number: ";
            std::cin >> id_number;
            std::cout << "Enter specialization: ";
            std::cin >> specialization;
            std::cout << "Enter number of years worked: ";
            std::cin >> years_of_experience;

            auto doctor = std::make_unique<Doctor>(name, surname, id_number, specialization, years_of_experience);
            employees_list.add_doctor(std::move(doctor));

            std::cout << "Doctor has been added." << std::endl;
        }
        else if (option == 2) {
            std::string name, surname, id_number;
            unsigned int years_of_experience;
            bool has_nursing_degree;

            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter surname: ";
            std::cin >> surname;
            std::cout << "Enter ID number: ";
            std::cin >> id_number;
            std::cout << "Enter number of years worked: ";
            std::cin >> years_of_experience;
            std::cout << "Has nursing degree? (1/0): ";
            std::cin >> has_nursing_degree;

            auto nurse = std::make_unique<Nurse>(name, surname, id_number, years_of_experience, has_nursing_degree);
            employees_list.add_nurse(std::move(nurse));

            std::cout << "Nurse has been added." << std::endl;
        }
        else if (option == 3) {
            std::string name, surname, id_number;
            unsigned int years_of_experience;
            bool has_paramedic_degree;

            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter surname: ";
            std::cin >> surname;
            std::cout << "Enter ID number: ";
            std::cin >> id_number;
            std::cout << "Enter number of years worked: ";
            std::cin >> years_of_experience;
            std::cout << "Has paramedic degree? (1/0): ";
            std::cin >> has_paramedic_degree;

            auto paramedic = std::make_unique<Paramedic>(name, surname, id_number, years_of_experience, has_paramedic_degree);
            employees_list.add_paramedic(std::move(paramedic));

            std::cout << "Paramedic has been added." << std::endl;
        }
        else if (option == 4) {
            // Remove employee
            std::string id_number;
            std::cout << "Enter employee ID number to remove: ";
            std::cin >> id_number;

            employees_list.remove_employee_by_id(id_number);

            std::cout << "Employee with ID number " << id_number << " has been removed." << std::endl;
        }
        else if (option == 5) {
            // Show whole salary
            double total_salary = employees_list.calculate_whole_salary();
            std::cout << "The total salary of all employees is " << total_salary << std::endl;
        }
        else if (option == 6) {
            // Show all employees
            std::cout << "Information about all employees in the list:\n" << std::endl;
            employees_list.show_information(std::cout);
        }
    } while (option != 7);

    std::cout << "Exiting the program..." << std::endl;

    return 0;
}