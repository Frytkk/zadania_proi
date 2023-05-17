#include "product.h"


Product::Product(std::string name, std::string manufacturer, float price)
    : name(name), manufacturer(manufacturer), price(price){}

std::string Product::get_name() const
{
    return name;
}

std::string Product::get_manufacturer() const
{
    return manufacturer;
}

float Product::get_price() const
{
    return price;
}


void Product::set_name(std::string name)
{
    this->name = name;
}

void Product::set_manufacturer(std::string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Product::set_price(float price)
{
    this->price = price;
}


bool Product::operator<(const Product& other) const
{
    return price < other.price;
}

bool Product::operator>(const Product& other) const
{
    return price > other.price;
}

bool Product::operator<=(const Product& other) const
{
    return price <= other.price;
}

bool Product::operator>=(const Product& other) const
{
    return price >= other.price;
}

bool Product::operator==(const Product& other) const
{
    return (name == other.name && manufacturer == other.manufacturer);
}
