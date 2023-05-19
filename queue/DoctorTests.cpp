//
// Created by Artur Kempiński on 23/03/2023.
//

#include "catch_amalgamated.hpp"
#include "../Queue.h"

TEST_CASE("Doctor tests", "[Doctor]") {
    std::vector<std::string> testSpecializations{"Cardio", "Dentist"};
    Doctor testDoctor{"Doctor", testSpecializations};

    CHECK(testDoctor.getName() == "Doctor");
    CHECK(testDoctor.getSpecializations() == testSpecializations);

    SECTION("Adding doctor specialization") {
        CHECK(testDoctor.getSpecializations().size() == 2);
        testDoctor.addSpecialization("Dermatology");
        CHECK(testDoctor.getSpecializations().size() == 3);
    }
    SECTION("Deleting doctor specialization") {
        testDoctor.addSpecialization("Dermatology");
        CHECK(testDoctor.getSpecializations().size() == 3);
        testDoctor.delSpecialization("Dermatology");
        CHECK(testDoctor.getSpecializations().size() == 2);
        CHECK(testDoctor.getSpecializations() == testSpecializations);
    }


}