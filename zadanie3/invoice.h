#pragma once

#include <vector>
#include <string>
#include "product.h"
#include "date.h"
#include "address.h"

class Invoice {
    private:
        std::string issuer_name;
        Address issuer_address;
        std::string issuer_tax_id;
        std::string recipient_name;
        Address recipient_address;
        Date date;
        Address address;
        std::vector <std::pair<Product, unsigned int>> products;
        float total_value;
        int total_quantity;

    public:
        Invoice(std::string issuer_name, Address issuer_address,
                std::string issuer_tax_id, std::string recipient_name,
                Address recipient_address, Date date,
                Address address);

        std::string get_issuer_name() const;
        Address get_issuer_address() const;
        std::string get_issuer_tax_id() const;
        std::string get_recipient_name() const;
        Address get_recipient_address() const;
        Date get_date() const;
        Address get_address() const;
        float get_total_value() const;
        int get_total_quantity() const;

        void set_issuer_name(std::string issuer_name);
        void set_issuer_address(Address issuer_address);
        void set_issuer_tax_id(std::string issuer_tax_id);
        void set_recipient_name(std::string recipient_name);
        void set_recipient_address(Address recipient_address);
        void set_date(std::string date);
        void set_address(Address address);

        int product_position(Product product) const;
        void add_product(Product product, unsigned int quantity);
        void add_product_from_invoice(Product product, unsigned int quantity);
        void remove_product(Product product);
        void modify_product(Product product_to_modify, Product product_modified, unsigned int quantity);
        int get_total_quantity_cheaper_equal(float price) const;

        void sort_products_by_name();
        void sort_products_by_price();
        std::vector<std::pair<Product, unsigned int>> get_products_by_price() const;
        std::vector<std::pair<Product, unsigned int>> get_products_by_name() const;
        bool operator<(const Invoice& other) const;
        bool operator>(const Invoice& other) const;
        bool operator<=(const Invoice& other) const;
        bool operator>=(const Invoice& other) const;
        Invoice operator+(const Invoice& other) const;
        Invoice& operator+=(const Invoice& other);
};