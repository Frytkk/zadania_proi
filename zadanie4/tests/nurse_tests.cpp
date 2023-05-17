// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../nurse.h"

TEST_CASE("Nurse simple tests", "[nurse]") {
    SECTION("testing constructor and getters") {
        Nurse nurse("Maciek", "Kowal", "1234", 7, true);

        CHECK(nurse.get_first_name() == "Maciek");
        CHECK(nurse.get_surname() == "Kowal");
        CHECK(nurse.get_id_number() == "1234");
        CHECK(nurse.get_years_of_experience() == 7);
        CHECK(nurse.get_has_nursing_degree() == true);
    }

    SECTION("testing setters") {
        Nurse nurse("Maciek", "Kowal", "1234", 7, true);

        nurse.set_first_name("Mateusz");
        nurse.set_surname("Bocian");
        nurse.set_id_number("1234");
        nurse.set_years_of_experience(10);
        nurse.set_has_nursing_degree(false);

        CHECK(nurse.get_first_name() == "Mateusz");
        CHECK(nurse.get_surname() == "Bocian");
        CHECK(nurse.get_id_number() == "1234");

        CHECK(nurse.get_years_of_experience() == 10);
        CHECK(nurse.get_has_nursing_degree() == false);
    }

    SECTION("testing calculate_salary()") {
        Nurse nurse("Maciek", "Kowal", "1234", 7, true);

        double expectedSalary = 7700.0;
        CHECK(nurse.calculate_salary() == expectedSalary);
    }

    SECTION("testing printing nurse data") {
        Nurse nurse("Maciek", "Kowal", "1234", 7, true);
        std::stringstream ss;
        ss << nurse;

        std::string expectedOutput = "Nurse: Maciek Kowal (ID: 1234)\n";
        expectedOutput += "Years of experience: 7\n";
        expectedOutput += "Has nursing degree: Yes\n";
        expectedOutput += "Salary: " + std::to_string(nurse.calculate_salary()) + "\n";

        CHECK(ss.str() == expectedOutput);
    }
}
