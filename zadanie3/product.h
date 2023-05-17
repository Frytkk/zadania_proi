#pragma once

#include <string>


class Product {
    private:
        std::string name;
        std::string manufacturer;
        float price;

    public:
        Product(std::string name, std::string manufacturer, float price);
        std::string get_name() const;
        std::string get_manufacturer() const;
        float get_price() const;

        void set_name(std::string name);
        void set_manufacturer(std::string manufacturer);
        void set_price(float price);

        bool operator<(const Product& other) const;
        bool operator>(const Product& other) const;
        bool operator<=(const Product& other) const;
        bool operator>=(const Product& other) const;
        bool operator==(const Product& other) const;
};
