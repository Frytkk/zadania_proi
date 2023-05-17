// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../specialization.h"

TEST_CASE("Specialization tests", "[specialization]") {
    SECTION("testing add_specialization()") {
        Specialization::add_specialization("orthopedist", 30);
        unsigned int expectedValue = 30;
        CHECK(Specialization::get_value("orthopedist") == expectedValue);
    }

    SECTION("testing add_specialization() with existing specialization") {
        CHECK_THROWS_AS(Specialization::add_specialization("pediatrician", 15), std::invalid_argument);
    }

    SECTION("testing remove_specialization()") {
        Specialization::remove_specialization("dermatologist");
        CHECK_THROWS_AS(Specialization::get_value("dermatologist"), std::invalid_argument);
    }

    SECTION("testing remove_specialization() with non-existing specialization") {
        CHECK_THROWS_AS(Specialization::remove_specialization("ophthalmologist"), std::invalid_argument);
    }

    SECTION("testing get_value()") {
        unsigned int expectedValue = 25;
        CHECK(Specialization::get_value("gynecologist") == expectedValue);
        CHECK(Specialization::get_value("pediatrician") == 10);
        CHECK(Specialization::get_value("cardiologist") == 20);
        CHECK_THROWS_WITH(Specialization::get_value("dermatologist"), "Specialization does not exist");
        CHECK(Specialization::get_value("neurologist") == 10);
    }

    SECTION("testing get_value() with non-existing specialization") {
        CHECK_THROWS_AS(Specialization::get_value("oncologist"), std::invalid_argument);
        CHECK_THROWS_AS(Specialization::get_value("invalidSpecialization"), std::invalid_argument);
    }
}
