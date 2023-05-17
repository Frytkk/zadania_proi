// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../paramedic.h"

TEST_CASE("Paramedic simple tests", "[paramedic]") {
    SECTION("testing constructor and getters") {
        Paramedic paramedic("Maciek", "Kowal", "5678", 10, true);

        CHECK(paramedic.get_first_name() == "Maciek");
        CHECK(paramedic.get_surname() == "Kowal");
        CHECK(paramedic.get_id_number() == "5678");
        CHECK(paramedic.get_years_of_experience() == 10);
        CHECK(paramedic.get_has_paramedic_degree() == true);
    }

    SECTION("testing setters") {
        Paramedic paramedic("Maciek", "Kowal", "5678", 10, true);

        paramedic.set_years_of_experience(12);
        paramedic.set_has_paramedic_degree(false);

        CHECK(paramedic.get_years_of_experience() == 12);
        CHECK(paramedic.get_has_paramedic_degree() == false);
    }

    SECTION("testing calculate_salary()") {
        Paramedic paramedic("Maciek", "Kowal", "5678", 10, true);

        double expectedSalary = 5500.0;
        CHECK(paramedic.calculate_salary() == expectedSalary);
    }

    SECTION("testing printing paramedic data") {
        Paramedic paramedic("Maciek", "Kowal", "5678", 10, true);
        std::stringstream ss;
        ss << paramedic;

        std::string expectedOutput = "ID: 5678, Name: ";
        expectedOutput += paramedic.get_first_name();
        expectedOutput += ", Surname: ";
        expectedOutput += paramedic.get_surname();
        expectedOutput += "\n";

        CHECK(ss.str() == expectedOutput);
    }
}
