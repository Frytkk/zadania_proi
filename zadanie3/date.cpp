
#include <stdexcept>
#include "date.h"


Date::Date(std::string date)
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


uint8_t Date::get_day() const
{
    return day;
}
uint8_t Date::get_month() const
{
    return month;
}
unsigned int Date::get_year() const
{
    return year;
}
void Date::set_day(uint8_t day)
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
void Date::set_month(uint8_t month)
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
void Date::set_year(unsigned int year)
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

bool Date::is_valid(uint8_t day, uint8_t month, unsigned int year)
{
    if (day == 0 || day > 31 || month == 0 || month > 12 || year == 0)
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
