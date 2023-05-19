//
// Created by Artur Kempiński on 23/03/2023.
//

#include "catch_amalgamated.hpp"
#include "../Queue.h"

TEST_CASE("Queue tests", "[Queue]") {
    std::vector<std::string> testSpecializations{"Cardio", "Dentist"};
    Doctor testDoctor1{"Doctor1", testSpecializations};
    Queue testQueue{testDoctor1, 3};
    Patient testPatient1{"Rafał", Gender::male, 21};
    testQueue.addPatient(testPatient1);

    SECTION("Getting doctor") {
        CHECK(testQueue.getDoctor().getName() == "Doctor1");
    }
    SECTION("Changing doctor") {
        Doctor testDoctor2{"Doctor2", testSpecializations};
        testQueue.setDoctor(testDoctor2);

        CHECK(testQueue.getDoctor().getName() == "Doctor2");
    }
    SECTION("Getting patient by his queue number") {
        CHECK(testQueue.getPatient(1).getName() == "Rafał");
    }
    SECTION("Trying to get non-existent patient") {
        CHECK_THROWS_AS(testQueue.getPatient(2), std::out_of_range);
    }
    SECTION("Adding few patients") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        Patient testPatient3{"Dawid", Gender::male, 22};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);

        CHECK(testQueue.getPatient(1).getName() == "Rafał");
        CHECK(testQueue.getPatient(2).getName() == "Łukasz");
        CHECK(testQueue.getPatient(3).getName() == "Dawid");
    }
    SECTION("Adding patient over limit") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        Patient testPatient3{"Dawid", Gender::male, 21};
        Patient testPatient4{"Zbigniew", Gender::male, 22};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);

        CHECK_THROWS_AS(testQueue.addPatient(testPatient4), std::length_error);
    }
    SECTION("Deleting patient") {
        testQueue.delPatient(1);

        CHECK_THROWS_AS(testQueue.getPatient(1), std::out_of_range);
    }
    SECTION("Deleting non-existent patient") {
        CHECK_THROWS_AS(testQueue.delPatient(5), std::out_of_range);
    }
    SECTION("Checking queue numbers distribution") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        Patient testPatient3{"Dawid", Gender::male, 21};
        Patient testPatient4{"Zbigniew", Gender::male, 21};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);
        testQueue.delPatient(2);
        testQueue.addPatient(testPatient4);

        CHECK(testQueue.getPatient(2).getName() == "Zbigniew");
    }
    SECTION("Testing isPatientInQueue() true") {
        CHECK(testQueue.isPatientInQueue(testPatient1));
    }
    SECTION("Testing isPatientInQueue() false") {
        Patient testPatient2{"Łukasz", Gender::male, 21};

        CHECK_FALSE(testQueue.isPatientInQueue(testPatient2));
    }
    SECTION("Testing getting amount of patients of given age") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        Patient testPatient3{"Dawid", Gender::male, 20};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);

        CHECK(testQueue.getPatientsOfAge(21) == 2);
        CHECK(testQueue.getPatientsOfAge(19) == 0);
    }
    SECTION("Testing getting amount of patients of given gender") {
        Patient testPatient2{"Łukasz", Gender::male, 21};
        Patient testPatient3{"Michalina", Gender::female, 20};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);

        CHECK(testQueue.getPatientsOfGender(Gender::male) == 2);
        CHECK(testQueue.getPatientsOfGender(Gender::female) == 1);
    }
    SECTION("Testing getting patients sorted by age") {
        Patient testPatient2{"Łukasz", Gender::male, 25};
        Patient testPatient3{"Michalina", Gender::female, 15};
        testQueue.addPatient(testPatient2);
        testQueue.addPatient(testPatient3);
        std::vector<Patient> patientsByAge {testPatient3, testPatient1, testPatient2};

        CHECK(testQueue.getPatientsSortedByAge() == patientsByAge);
    }
    SECTION("Testing changing patient's number correct") {
        Patient testPatient2{"Łukasz", Gender::male, 25};
        testQueue.addPatientWithNumber(testPatient2, 3);

        CHECK(testQueue.getPatient(3).getName() == "Łukasz");
        Patient testPatient3{"Michalina", Gender::female, 15};
        testQueue.addPatient(testPatient3);

        CHECK(testQueue.getPatient(2).getName() == "Michalina");
    }
    SECTION("Testing adding patient with number incorrect") {
        Patient testPatient2{"Łukasz", Gender::male, 25};

        CHECK_THROWS_AS(testQueue.addPatientWithNumber(testPatient2, 1), std::out_of_range);
        CHECK_THROWS_AS(testQueue.addPatientWithNumber(testPatient2, 4), std::out_of_range);
    }
    SECTION("Testing reading from csv") {
        Queue readQueue = readQueueFromCSV("testQueue.csv");

        CHECK(readQueue.getDoctor().getName() == "Dr. Zbigniew Beksiński");
        CHECK(readQueue.getDoctor().getSpecializations() == std::vector<std::string>{"Chirurgia", "Kardiologia"});
        CHECK(readQueue.getPatient(1).getName() == "Anna Wrona");
        CHECK(readQueue.getPatient(6).getName() == "Agnieszka Walcowa");
        CHECK(readQueue.getPatient(6).getAge() == 45);
        CHECK(readQueue.getPatient(3).getName() == "Janusz Knur");
        CHECK(readQueue.getPatientsOfGender(Gender::female) == 2);
    }
}