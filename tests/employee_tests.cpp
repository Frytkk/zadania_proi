// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../employee.h"


TEST_CASE("employee simple tests", "[employee]")
{
    Employee employee("Maciek", "Kowal", "1234");

    SECTION("testing getters"){
        CHECK(employee.get_first_name() == "Maciek");
        CHECK(employee.get_surname() == "Kowal");
        CHECK(employee.get_id_number() == "1234");
    }

    SECTION("testing setters"){
        employee.set_first_name("Mateusz");
        employee.set_surname("Janowski");
        employee.set_id_number("2345");

        CHECK(employee.get_first_name() == "Mateusz");
        CHECK(employee.get_surname() == "Janowski");
        CHECK(employee.get_id_number() == "2345");
        CHECK(employee.calculate_salary() == 0.0);
    }

    SECTION("testing printing employee data"){
        std::stringstream ss;
        ss << employee;
        CHECK(ss.str() == "ID: 1234, Name: Maciek, Surname: Kowal\n");
    }

    SECTION("testing == operator"){
        Employee employee2("Maciek", "Kowal", "1234");
        CHECK(employee == employee2);
    }

}