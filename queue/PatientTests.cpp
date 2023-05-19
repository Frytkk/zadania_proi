//
// Created by Artur Kempiński on 26/03/2023.
//

#include "catch_amalgamated.hpp"
#include "../Patient.h"

TEST_CASE("Patient tests", "[Patient]") {
    Patient testPatient{"Łukasz", Gender::male, 21};

    SECTION("Testing == operator true") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        CHECK(testPatient == testPatient2);
    }
    SECTION("Testing == operator false") {
        Patient testPatient2{"Karolina", Gender::female, 25};
        CHECK_FALSE(testPatient == testPatient2);
    }
}