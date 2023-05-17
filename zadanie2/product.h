// Andrzej Tokajuk

#pragma once
#include <cstdint>
#include <string>
#include <vector>

class ExpirationDate
{
    private:
        uint8_t day;
        uint8_t month;
        unsigned int year;
    public:
        ExpirationDate(std::string date);
        bool is_valid(uint8_t day, uint8_t month, unsigned int year);

        uint8_t get_day();
        uint8_t get_month();
        unsigned int get_year();

        void set_day(uint8_t day);
        void set_month(uint8_t month);
        void set_year(unsigned int year);

        bool operator==(const ExpirationDate& other) const;
};


class Product
{
    private:
        std::string name;
        unsigned int volume;
        std::string manufacturer;
        std::string batch_number;
        ExpirationDate expiration_date;
        std::vector<std::string> ingredients;
    public:
        Product(std::string name,
            unsigned int volume,
            std::string manufacturer,
            std::string batch_number,
            ExpirationDate expiration_date,
            std::vector<std::string> ingredients);

        std::string get_name();
        unsigned int get_volume();
        std::string get_manufacturer();
        std::string get_batch_number();
        ExpirationDate get_expiration_date();
        std::vector<std::string> get_ingredients();

        void set_name(std::string name);
        void set_volume(unsigned int volume);
        void set_manufacturer(std::string manufacturer);
        void set_batch_number(std::string batch_number);
        void set_expiration_date(std::string expiration_date);
        void set_ingredients(std::vector<std::string> ingredients);

        bool is_ingredient_present(std::string ingredient);
        void add_ingredient(std::string ingredient);
        void del_ingredient(std::string ingredient);
        void modify_ingredient(std::string old_ingredient, std::string new_ingredient);
        unsigned int get_ingredients_number();

};