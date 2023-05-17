// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../doctor.h"
#include "../specialization_not_found_exception.h"

TEST_CASE("Doctor simple tests", "[doctor]") {
    SECTION("testing constructor and getters") {
        Doctor doctor("Maciek", "Kowal", "5678", "pediatrician", 5);

        CHECK(doctor.get_first_name() == "Maciek");
        CHECK(doctor.get_surname() == "Kowal");
        CHECK(doctor.get_id_number() == "5678");
        CHECK(doctor.get_specialization() == "pediatrician");
        CHECK(doctor.get_years_of_experience() == 5);
    }

    SECTION("testing setters") {
        Doctor doctor("Maciek", "Kowal", "5678", "pediatrician", 5);

        doctor.set_first_name("Mateusz");
        doctor.set_surname("Bocian");
        doctor.set_id_number("1234");
        doctor.set_specialization("cardiologist");
        doctor.set_years_of_experience(10);

        CHECK(doctor.get_first_name() == "Mateusz");
        CHECK(doctor.get_surname() == "Bocian");
        CHECK(doctor.get_id_number() == "1234");
        CHECK(doctor.get_specialization() == "cardiologist");
        CHECK(doctor.get_years_of_experience() == 10);
    }

    SECTION("testing calculate_salary()") {
        Doctor doctor("Maciek", "Kowal", "5678", "cardiologist", 5);

        double expectedSalary = 20000.0;
        CHECK(doctor.calculate_salary() == expectedSalary);
    }

    SECTION("testing printing doctor data") {
        Doctor doctor("Maciek", "Kowal", "5678", "cardiologist", 5);
        std::stringstream ss;
        ss << doctor;

        std::string expectedOutput = "Doctor: Maciek Kowal (ID: 5678)\n";
        expectedOutput += "Specialization: cardiologist\n";
        expectedOutput += "Years of experience: 5\n";
        expectedOutput += "Salary: " + std::to_string(doctor.calculate_salary()) + "\n";

        CHECK(ss.str() == expectedOutput);
    }

    SECTION("testing specialization not found exception") {
        CHECK_THROWS_AS(Doctor("Maciek", "Kowal", "5678", "InvalidSpecialization", 5), SpecializationNotFoundException);
    }
}
