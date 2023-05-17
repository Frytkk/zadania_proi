// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../employees_list.h"
#include "../employee.h"
#include "../doctor.h"
#include "../nurse.h"
#include "../paramedic.h"

TEST_CASE("EmployeesList tests", "[employees_list]") {
    EmployeesList employeesList;

    SECTION("testing add_employee()") {
        std::unique_ptr<Employee> employee1 = std::make_unique<Employee>("Maciek", "Kowal", "1234");
        employeesList.add_employee(std::move(employee1));
        REQUIRE(employeesList.get_employees_list().size() == 1);
    }

    SECTION("testing add_doctor()") {
        std::unique_ptr<Doctor> doctor1 = std::make_unique<Doctor>("Basia", "Kasia", "5678", "cardiologist", 5);
        employeesList.add_doctor(std::move(doctor1));
        REQUIRE(employeesList.get_employees_list().size() == 1);
    }

    SECTION("testing add_nurse()") {
        std::unique_ptr<Nurse> nurse1 = std::make_unique<Nurse>("Kasia", "Basia", "9012", 10, true);
        employeesList.add_nurse(std::move(nurse1));
        REQUIRE(employeesList.get_employees_list().size() == 1);
    }

    SECTION("testing add_paramedic()") {
        std::unique_ptr<Paramedic> paramedic1 = std::make_unique<Paramedic>("Mateusz", "Maria", "3456", 8, true);
        employeesList.add_paramedic(std::move(paramedic1));
        REQUIRE(employeesList.get_employees_list().size() == 1);
    }

    SECTION("testing remove_employee()") {
        std::unique_ptr<Employee> employee2 = std::make_unique<Employee>("Maria", "Dedel", "1234");
        employeesList.add_employee(std::move(employee2));
        REQUIRE(employeesList.get_employees_list().size() == 1);

        Employee employeeToRemove("Maria", "Dedel", "1234");
        employeesList.remove_employee(employeeToRemove);
        REQUIRE(employeesList.get_employees_list().empty());
    }

    SECTION("testing remove_employee_by_id()") {
        std::unique_ptr<Employee> employee3 = std::make_unique<Employee>("Kamil", "Bartek", "1234");
        employeesList.add_employee(std::move(employee3));
        REQUIRE(employeesList.get_employees_list().size() == 1);

        std::string idToRemove = "1234";
        employeesList.remove_employee_by_id(idToRemove);
        REQUIRE(employeesList.get_employees_list().empty());
    }

    SECTION("testing calculate_whole_salary()") {
        std::unique_ptr<Doctor> doctor2 = std::make_unique<Doctor>("Kamil", "Bartek", "5678", "cardiologist", 5);
        employeesList.add_doctor(std::move(doctor2));

        std::unique_ptr<Nurse> nurse2 = std::make_unique<Nurse>("Kasia", "Marysia", "9012", 10, true);
        employeesList.add_nurse(std::move(nurse2));

        std::unique_ptr<Paramedic> paramedic2 = std::make_unique<Paramedic>("Wojtek", "Wola", "3456", 8, true);
        employeesList.add_paramedic(std::move(paramedic2));

        double expectedSalary = 33300.0;
        CHECK(employeesList.calculate_whole_salary() == expectedSalary);
    }

    SECTION("testing show_information()") {
        std::unique_ptr<Doctor> doctor3 = std::make_unique<Doctor>("Maria", "Polka", "5678", "cardiologist", 5);
        employeesList.add_doctor(std::move(doctor3));

        std::unique_ptr<Nurse> nurse3 = std::make_unique<Nurse>("Robert", "Robertowski", "9012", 10, true);
        employeesList.add_nurse(std::move(nurse3));

        std::unique_ptr<Paramedic> paramedic3 = std::make_unique<Paramedic>("Tomek", "Tomkowski", "3456", 8, true);
        employeesList.add_paramedic(std::move(paramedic3));

        std::stringstream ss;
        employeesList.show_information(ss);

        std::string expectedOutput = "Doctor: Maria Polka (ID: 5678)\n";
        expectedOutput += "Specialization: cardiologist\n";
        expectedOutput += "Years of experience: 5\n";
        expectedOutput += "Salary: 20000.000000\n";
        expectedOutput += "Nurse: Robert Robertowski (ID: 9012)\n";
        expectedOutput += "Years of experience: 10\n";
        expectedOutput += "Has nursing degree: Yes\n";
        expectedOutput += "Salary: 8000.000000\n";
        expectedOutput += "ID: 3456, Name: Tomek, Surname: Tomkowski\n";

        CHECK(ss.str() == expectedOutput);
    }
}
