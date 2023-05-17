// Andrzej Tokajuk


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "filehandler.h"
#include "date.h"
#include "invoice.h"
#include "product.h"


int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Error: no input file specified" << std::endl;
        return 1;
    }

    Filehandler file;


    std::vector<std::string> lines = file.read_lines(argv[1]);

    std::vector<Invoice> invoices;
    std::vector<Product> products;

    std::string type;

    for (auto& line : lines) {
        std::istringstream iss(line);
        // iss >> type;
        std::getline(iss >> std::ws, type);
        if (type == "Invoice")
        {
            std::string issuer, recipient, issue_date, due_date;
            std::string issuer_tax_id;
            std::string address1, address2, address3, address4;
            std::string address5, address6, address7, address8;
            std::string address9, address10, address11, address12;
            // unsigned int day, month, year;
            // iss >> issuer;
            iss.clear();
            iss.str(line);
            std::getline(iss >> std::ws, issuer);
            std::getline(iss >> std::ws, address1);
            std::getline(iss >> std::ws, address2);
            std::getline(iss >> std::ws, address3);
            std::getline(iss >> std::ws, address4);
            std::getline(iss >> std::ws, issuer_tax_id);
            std::getline(iss >> std::ws, recipient);
            std::getline(iss >> std::ws, address5);
            std::getline(iss >> std::ws, address6);
            std::getline(iss >> std::ws, address7);
            std::getline(iss >> std::ws, address8);
            std::getline(iss >> std::ws, issue_date);
            // iss >> day >> month >> year;
            std::getline(iss >> std::ws, address9);
            std::getline(iss >> std::ws, address10);
            std::getline(iss >> std::ws, address11);
            std::getline(iss >> std::ws, address12);

            invoices.emplace_back(issuer, Address(address1, address2, address3, address4),
                issuer_tax_id, recipient, Address(address1, address2, address3, address4), Date(issue_date),
                Address(address9, address10, address11, address12));
        }
        else if (type == "Product")
        {
            std::string name, manufacturer;
            float price;
            int quantity;

            std::getline(iss >> std::ws, name);
            std::getline(iss >> std::ws, manufacturer);
            iss >> price >> quantity;

            products.emplace_back(name, manufacturer, price);

        }
    }




    std::cout << "Invoices:" << std::endl;
    for (const auto& invoice : invoices) {
        std::cout << "Issuer name: " << invoice.get_issuer_name() << "\n";
        // std::cout << "Issuer address: " << invoice.get_issuer_address().to_string() << "\n";
        std::cout << "Issuer tax ID: " << invoice.get_issuer_tax_id() << "\n";
        std::cout << "Recipient name: " << invoice.get_recipient_name() << "\n";
        // std::cout << "Recipient address: " << invoice.get_recipient_address().to_string() << "\n";
        // std::cout << "Date: " << invoice.get_date().to_string() << "\n";
        std::cout << "Products:\n";
        const auto& products = invoice.get_products_by_name();
        for (const auto& [product, quantity] : products) {
            std::cout << "- Product name: " << product.get_name() << "\n";
            std::cout << "  Manufacturer: " << product.get_manufacturer() << "\n";
            std::cout << "  Price: " << product.get_price() << "\n";
            std::cout << "  Quantity: " << quantity << "\n";
            std::cout << "  Total price: " << product.get_price() * quantity << "\n";
        }
        std::cout << "Total price: " << invoice.get_total_value() << "\n";
        std::cout << "-------------------------\n";
    }

    // std::cout << std::endl << "Products:" << std::endl;
    // for (auto& product : products) {
    //     std::cout << product.to_string() << std::endl;
    // }

    return 0;
}
