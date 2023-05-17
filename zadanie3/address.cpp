#include "address.h"



Address::Address(std::string street, std::string city, std::string zip, std::string country)
        : street(street), city(city), zip(zip), country(country) {}

std::string Address::get_street() const
{
    return street;
}

std::string Address::get_city() const
{
    return city;
}

std::string Address::get_zip() const
{
    return zip;
}

std::string Address::get_country() const
{
    return country;
}


void Address::set_street(std::string street)
{
    this->street = street;
}

void Address::set_city(std::string city)
{
    this->city = city;
}

void Address::set_zip(std::string zip)
{
    this->zip = zip;
}

void Address::set_country(std::string country)
{
    this->country = country;
}
