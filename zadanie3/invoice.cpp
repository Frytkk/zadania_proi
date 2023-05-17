#include "invoice.h"
#include <algorithm>
#include <stdexcept>

Invoice::Invoice(std::string issuer_name, Address issuer_address,
                std::string issuer_tax_id, std::string recipient_name,
                Address recipient_address, Date date,
                Address address)
                : issuer_name(issuer_name), issuer_address(issuer_address), issuer_tax_id(issuer_tax_id),
                recipient_name(recipient_name), recipient_address(recipient_address),
                date(date), address(address), total_value(0.0f), total_quantity(0){}

std::string Invoice::get_issuer_name() const
{
    return issuer_name;
}

Address Invoice::get_issuer_address() const
{
    return issuer_address;
}

std::string Invoice::get_issuer_tax_id() const
{
    return issuer_tax_id;
}

std::string Invoice::get_recipient_name() const
{
    return recipient_name;
}

Address Invoice::get_recipient_address() const
{
    return recipient_address;
}

Date Invoice::get_date() const
{
    return date;
}

Address Invoice::get_address() const
{
    return address;
}

float Invoice::get_total_value() const
{
    return total_value;
}

int Invoice::get_total_quantity() const
{
    return total_quantity;
}


void Invoice::set_issuer_name(std::string issuer_name)
{
    this->issuer_name = issuer_name;
}

void Invoice::set_issuer_address(Address issuer_address)
{
    this->issuer_address = issuer_address;
}

void Invoice::set_issuer_tax_id(std::string issuer_tax_id)
{
    this->issuer_tax_id = issuer_tax_id;
}

void Invoice::set_recipient_name(std::string recipient_name)
{
    this->recipient_name = recipient_name;
}

void Invoice::set_recipient_address(Address recipient_address)
{
    this->recipient_address = recipient_address;
}

void Invoice::set_date(std::string date)
{
    Date new_date(date);
    this -> date = new_date;
}

void Invoice::set_address(Address address)
{
    this->address = address;
}


int Invoice::product_position(Product product) const
{
    auto iter = std::find_if(products.begin(), products.end(), [product](const auto& pair)
    {
        return pair.first == product;
    });
    return (iter != products.end()) ? std::distance(products.begin(), iter) : -1;
}


void Invoice::add_product(Product product, unsigned int quantity)
{
    int pos = product_position(product);
    if (pos == -1)
    {
        products.push_back(std::make_pair(product, quantity));
        total_quantity += quantity;
        total_value += product.get_price() * quantity;
    }
    else
    {
        throw std::invalid_argument("Product is already in the invoice.");
    }
}

void Invoice::add_product_from_invoice(Product product, unsigned int quantity)
{
    int pos = product_position(product);
    if (pos == -1)
    {
        products.push_back(std::make_pair(product, quantity));
    }
    else
    {
        products[pos].second += quantity;
    }
    total_quantity += quantity;
    total_value += product.get_price() * quantity;
}

void Invoice::remove_product(Product product)
{
    auto pos = product_position(product);
    if (pos == -1)
    {
        throw std::invalid_argument("Product not found");
    }
    total_quantity -= products[pos].second;
    total_value -= product.get_price() * products[pos].second;
    products.erase(products.begin() + pos);
}

void Invoice::modify_product(Product product_to_modify, Product product_modified, unsigned int quantity)
{
    auto pos = product_position(product_to_modify);
    if (pos == -1)
    {
        throw std::invalid_argument("Product not found");
    }
    total_quantity -= products[pos].second;
    total_value -= product_to_modify.get_price() * products[pos].second;

    products[pos].first = product_modified;
    products[pos].second = quantity;

    total_quantity += quantity;
    total_value += product_modified.get_price() * quantity;
}

int Invoice::get_total_quantity_cheaper_equal(float price) const
{
    int quantity_cheaper_equal = 0;
    for(auto product : products)
    {
        if (product.first.get_price() <= price)
        {
            quantity_cheaper_equal += product.second;
        }
    }
    return quantity_cheaper_equal;
}

void Invoice::sort_products_by_name()
{
    std::sort(products.begin(), products.end(), [](std::pair<Product, unsigned int>& a, std::pair<Product, unsigned int>& b)
    {
        return a.first.get_name() < b.first.get_name();
    });
}

void Invoice::sort_products_by_price()
{
    std::sort(products.begin(), products.end(), [](std::pair<Product, unsigned int>& a, std::pair<Product, unsigned int>& b)
    {
        return a.first.get_price() < b.first.get_price();
    });
}

std::vector<std::pair<Product, unsigned int>> Invoice::get_products_by_price() const
{
    std::vector <std::pair<Product, unsigned int>> products_duplicate = products;
    std::sort(products_duplicate.begin(), products_duplicate.end(), [](std::pair<Product, unsigned int>& a, std::pair<Product, unsigned int>& b)
    {
        return a.first.get_price() < b.first.get_price();
    });
    return products_duplicate;
}

std::vector<std::pair<Product, unsigned int>> Invoice::get_products_by_name() const
{
    std::vector <std::pair<Product, unsigned int>> products_duplicate = products;
    std::sort(products_duplicate.begin(), products_duplicate.end(), [](std::pair<Product, unsigned int>& a, std::pair<Product, unsigned int>& b)
    {
        return a.first.get_name() < b.first.get_name();
    });
    return products_duplicate;
}

bool Invoice::operator<(const Invoice& other) const
{
    return total_value < other.total_value;
}

bool Invoice::operator>(const Invoice& other) const
{
    return total_value > other.total_value;
}

bool Invoice::operator<=(const Invoice& other) const
{
    return !operator>(other);
}

bool Invoice::operator>=(const Invoice& other) const
{
    return !operator<(other);
}


Invoice Invoice::operator+(const Invoice& other) const
{
    if (issuer_name != other.issuer_name || recipient_name != other.recipient_name)
    {
        throw std::invalid_argument("Cannot add invoices from different issuers or recipients.");
    }
    // nie wiem jak sensownie ustawic nowa date i adres, dlatego przekazuje stare

    Invoice result(issuer_name, issuer_address, issuer_tax_id, recipient_name, recipient_address, date, address);

    for (const auto& [product, quantity] : products)
    {
        result.add_product_from_invoice(product, quantity);
    }
    for (const auto& [product, quantity] : other.products)
    {
        result.add_product_from_invoice(product, quantity);
    }

    return result;
}

Invoice& Invoice::operator+=(const Invoice& other)
{
    if (issuer_name != other.issuer_name || recipient_name != other.recipient_name)
    {
        throw std::invalid_argument("Cannot add invoices from different issuers or recipients.");
    }

    for (const auto& [product, quantity] : other.products)
    {
        add_product_from_invoice(product, quantity);
    }

    return *this;
}
