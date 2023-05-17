#pragma once

#include <string>

class Address
{
    private:
        std::string street;
        std::string city;
        std::string zip;
        std::string country;

    public:
        Address(std::string street, std::string city, std::string zip, std::string country);

        std::string get_street() const;
        std::string get_city() const;
        std::string get_zip() const;
        std::string get_country() const;

        void set_street(std::string street);
        void set_city(std::string city);
        void set_zip(std::string zip);
        void set_country(std::string country);
};
