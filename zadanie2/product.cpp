// Andrzej Tokajuk

#include "product.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <sstream>



ExpirationDate::ExpirationDate(std::string date)
{
    size_t first_separator_pos = date.find('.');
    size_t second_separator_pos = date.find('.', first_separator_pos + 1);

    if (first_separator_pos == std::string::npos || second_separator_pos == std::string::npos)
    {
        throw std::invalid_argument("Invalid date format");
    }

    std::string day_str = date.substr(0, first_separator_pos);
    std::string month_str = date.substr(first_separator_pos + 1, second_separator_pos - first_separator_pos - 1);
    std::string year_str = date.substr(second_separator_pos + 1);

    day = std::stoi(day_str);
    month = std::stoi(month_str);
    year = std::stoi(year_str);

    if (!is_valid(day, month, year))
    {
        throw std::invalid_argument("Invalid date");
    }
}


uint8_t ExpirationDate::get_day()
{
    return day;
}
uint8_t ExpirationDate::get_month()
{
    return month;
}
unsigned int ExpirationDate::get_year()
{
    return year;
}
void ExpirationDate::set_day(uint8_t day)
{
    if (is_valid(day, month, year))
    {
        this -> day = day;
    }
    else
    {
        throw std::invalid_argument("Invalid day");
    }
}
void ExpirationDate::set_month(uint8_t month)
{
    if (is_valid(day, month, year))
    {
        this -> month = month;
    }
    else
    {
        throw std::invalid_argument("Invalid month");
    }
}
void ExpirationDate::set_year(unsigned int year)
{
    if (is_valid(day, month, year))
    {
        this -> year = year;
    }
    else
    {
        throw std::invalid_argument("Invalid year");
    }
}


bool ExpirationDate::is_valid(uint8_t day, uint8_t month, unsigned int year)
{
    if (day == 0 || day > 31 || month == 0 || month > 12)
    {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        return false;
    }
    if (month == 2)
    {
        bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (is_leap_year && day > 29)
        {
            return false;
        }
        if (!is_leap_year && day > 28)
        {
            return false;
        }
    }
    return true;
}

bool ExpirationDate::operator==(const ExpirationDate& other) const
{
    return day == other.day && month == other.month && year == other.year;
}




Product::Product(std::string name,
            unsigned int volume,
            std::string manufacturer,
            std::string batch_number,
            ExpirationDate expiration_date,
            std::vector<std::string> ingredients)
    : name(name), volume(volume), manufacturer(manufacturer),
      batch_number(batch_number), expiration_date(expiration_date), ingredients(ingredients){}


std::string Product::get_name()
{
    return name;
}
unsigned int Product::get_volume()
{
    return volume;
}
std::string Product::get_manufacturer()
{
    return manufacturer;
}
std::string Product::get_batch_number()
{
    return batch_number;
}
ExpirationDate Product::get_expiration_date()
{
    return expiration_date;
}
std::vector<std::string> Product::get_ingredients()
{
    return ingredients;
}


void Product::set_name(std::string name)
{
    this -> name = name;
}
void Product::set_volume(unsigned int volume)
{
    this -> volume = volume;
}
void Product::set_manufacturer(std::string manufacturer)
{
    this -> manufacturer = manufacturer;
}
void Product::set_batch_number(std::string batch_number)
{
    this -> batch_number = batch_number;
}
void Product::set_expiration_date(std::string expiration_date)
{
    ExpirationDate new_expiration_date(expiration_date);
    this -> expiration_date = new_expiration_date;
}
void Product::set_ingredients(std::vector<std::string> ingredients)
{
    this -> ingredients = ingredients;
}


bool Product::is_ingredient_present(std::string ingredient)
{
    if (std::find(ingredients.begin(), ingredients.end(), ingredient) != ingredients.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Product::add_ingredient(std::string ingredient)
{
    if (!is_ingredient_present(ingredient))
    {
        ingredients.push_back(ingredient);
    }
    else
    {
        throw std::invalid_argument("Ingredient is already present");
    }
}
void Product::del_ingredient(std::string ingredient)
{
    if (is_ingredient_present(ingredient))
    {
        auto it = std::remove(ingredients.begin(), ingredients.end(), ingredient);
        ingredients.erase(it, ingredients.end());
    }
    else
    {
        throw std::invalid_argument("Ingredient is not present");
    }

}
void Product::modify_ingredient(std::string old_ingredient, std::string new_ingredient)
{
    if (is_ingredient_present(old_ingredient))
    {
        std::replace(ingredients.begin(), ingredients.end(), old_ingredient, new_ingredient);
    }
    else
    {
        throw std::invalid_argument("Ingredient is not present");
    }
}
unsigned int Product::get_ingredients_number()
{
    return ingredients.size();
}


