#pragma once

#include <cstdint>
#include <string>

class Date
{
    private:
        uint8_t day;
        uint8_t month;
        unsigned int year;
    public:
        Date(std::string date);
        bool is_valid(uint8_t day, uint8_t month, unsigned int year);

        uint8_t get_day() const;
        uint8_t get_month() const;
        unsigned int get_year() const;

        void set_day(uint8_t day);
        void set_month(uint8_t month);
        void set_year(unsigned int year);
};
