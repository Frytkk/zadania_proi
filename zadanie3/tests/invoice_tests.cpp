// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../address.h"
#include "../date.h"
#include "../product.h"
#include "../invoice.h"

TEST_CASE("tests", "[all files]")
{
    std::string street = "Nowowiejska 15";
    std::string city = "Warsaw";
    std::string zip = "01-100";
    std::string country = "Poland";
    Address address1(street, city, zip, country);


    SECTION("testing address getters, setters")
    {
        CHECK(address1.get_street() == "Nowowiejska 15");
        CHECK(address1.get_city() == "Warsaw");
        CHECK(address1.get_zip() == "01-100");
        CHECK(address1.get_country() == "Poland");

        address1.set_street("Grzybowska");
        address1.set_city("Lodz");
        address1.set_zip("10-200");
        address1.set_country("USA");

        CHECK(address1.get_street() == "Grzybowska");
        CHECK(address1.get_city() == "Lodz");
        CHECK(address1.get_zip() == "10-200");
        CHECK(address1.get_country() == "USA");
    }

    SECTION("testing comparing addresses")
    {
        Address address1("Nowowiejska 15", "Warsaw", "01-100", "Poland");
        Address address2("Nowowiejska 15", "Warsaw", "01-100", "Poland");
        Address address3("Grzybowska", "Lodz", "10-200", "USA");
        CHECK(address1.get_city() == address2.get_city());
        CHECK(address1.get_city() != address3.get_city());
        CHECK(address1.get_country() == address2.get_country());
        CHECK(address1.get_country() != address3.get_country());
        CHECK(address1.get_street() == address2.get_street());
        CHECK(address1.get_street() != address3.get_street());
        CHECK(address1.get_zip() == address2.get_zip());
        CHECK(address1.get_zip() != address3.get_zip());
    }


    SECTION("valid date constructor")
    {
        Date date("30.12.2022");
        CHECK(date.get_day() == 30);
        CHECK(date.get_month() == 12);
        CHECK(date.get_year() == 2022);
    }

    SECTION("valid date setters")
    {
        Date date("31.01.2023");
        date.set_day(15);
        date.set_month(6);
        date.set_year(2024);
        CHECK(date.get_day() == 15);
        CHECK(date.get_month() == 6);
        CHECK(date.get_year() == 2024);
    }

    SECTION("invalid date constructor")
    {
        REQUIRE_THROWS_AS(Date("31-01-2023"), std::invalid_argument);
        REQUIRE_THROWS_AS(Date("01.13.2023"), std::invalid_argument);
        REQUIRE_THROWS_AS(Date("30.02.2023"), std::invalid_argument);
    }

    SECTION("invalid date setters")
    {
        Date date("31.01.2023");
        REQUIRE_THROWS_AS(date.set_day(32), std::invalid_argument);
        REQUIRE_THROWS_AS(date.set_month(13), std::invalid_argument);
        REQUIRE_THROWS_AS(date.set_year(0), std::invalid_argument);
        REQUIRE_THROWS_WITH(date.set_year(0), ("Invalid year"));
    }




    Product product("Test product", "Test manufacturer", 10.0f);

    SECTION("test name")
    {
        REQUIRE(product.get_name() == "Test product");
        product.set_name("New name");
        REQUIRE(product.get_name() == "New name");
    }

    SECTION("test manufacturer")
    {
        REQUIRE(product.get_manufacturer() == "Test manufacturer");
        product.set_manufacturer("New manufacturer");
        REQUIRE(product.get_manufacturer() == "New manufacturer");
    }

    SECTION("test price")
    {
        REQUIRE(product.get_price() == 10.0f);
        product.set_price(20.0f);
        REQUIRE(product.get_price() == 20.0f);
    }

    Product product1("Test product 1", "Test manufacturer", 10.0f);
    Product product2("Test product 2", "Test manufacturer", 20.0f);

    SECTION("test operator<")
    {
        REQUIRE(product1 < product2);
    }

    SECTION("test operator>")
    {
        REQUIRE(product2 > product1);
    }

    SECTION("test operator<=")
    {
        REQUIRE(product1 <= product2);
        REQUIRE(product1 <= product1);
    }

    SECTION("test operator>=")
    {
        REQUIRE(product2 >= product1);
        REQUIRE(product2 >= product2);
    }

    SECTION("test operator==")
    {
        Product product3("Test product 1", "Test manufacturer", 30.0f);
        REQUIRE(product1 == product3);
        REQUIRE_FALSE(product1 == product2);
    }



    SECTION("test adding new product")
    {
        Address issuer_address("123 Main St.", "Anytown", "12345", "USA");
        Address recipient_address("456 Maple Ave.", "Othertown", "67890", "USA");
        Address address("789 Oak Blvd.", "Another town", "54321", "USA");
        Date date("10.01.2023");
        Invoice invoice("John Doe", issuer_address, "123456789", "Jane Smith", recipient_address, date, address);

        Product product1("product1", "manufacturer1", 10.0f);
        Product product2("product2", "manufacturer2", 20.0f);

        invoice.add_product(product1, 2);
        CHECK(invoice.get_total_quantity() == 2);
        CHECK(invoice.get_total_value() == 20.0f);
        REQUIRE_THROWS_WITH(invoice.add_product(product1, 1), "Product is already in the invoice.");

        invoice.add_product(product2, 1);
        CHECK(invoice.get_total_quantity() == 3);
        CHECK(invoice.get_total_value() == 40.0f);
    }

    SECTION("test adding a product from an invoice to another invoice")
    {
        Address issuer_address("123 Main St.", "Anytown", "12345", "USA");
        Address recipient_address("456 Maple Ave.", "Othertown", "67890", "USA");
        Address address("789 Oak Blvd.", "Another town", "54321", "USA");
        Date date("12.01.2023");
        Invoice invoice1("John Doe", issuer_address, "123456789", "Jane Smith", recipient_address, date, address);
        Invoice invoice2("Bob Johnson", issuer_address, "987654321", "Mary Brown", recipient_address, date, address);

        CHECK(invoice1.get_address().get_street() == address.get_street());
        CHECK(invoice1.get_date().get_year() == date.get_year());



        Product product1("product1", "manufacturer1", 10.0f);
        Product product2("product2", "manufacturer2", 20.0f);

        // Adding a new product to invoice1 and then to invoice2 should increase the total quantity and value in both invoices
        invoice1.add_product(product1, 2);
        invoice2.add_product_from_invoice(product1, 1);
        CHECK(invoice1.get_total_quantity() == 2);
        CHECK(invoice1.get_total_value() == 20.0f);
        CHECK(invoice2.get_total_quantity() == 1);
        CHECK(invoice2.get_total_value() == 10.0f);

        // Adding a product that's already in the invoice should increase the quantity in invoice2 but not the total value
        invoice2.add_product_from_invoice(product1, 2);
        CHECK(invoice2.get_total_quantity() == 3);
        CHECK(invoice2.get_total_value() == 30.0f);

        // Adding a new product to invoice1 and then to invoice2 should increase the total quantity and value in both invoices again
        invoice1.add_product(product2, 1);
        invoice2.add_product_from_invoice(product2, 2);
        CHECK(invoice1.get_total_quantity() == 3);
        CHECK(invoice1.get_total_value() == 40.0f);
        CHECK(invoice2.get_total_quantity() == 5);


    }



    Product product3("book", "empik", 10.0f);
    Product product4("pen", "bic", 1.5f);
    Product product5("pencil", "bic", 0.8f);
    Product product6("backpack", "nike", 100.0f);

    Address issuer_address("123 Main St.", "Anytown", "12345", "USA");
    Address recipient_address("456 Maple Ave.", "Othertown", "67890", "USA");
    Address address("789 Oak Blvd.", "Another town", "54321", "USA");
    Date date("10.01.2023");
    Invoice invoice("John Doe", issuer_address, "123456789", "Jane Smith", recipient_address, date, address);
    Invoice invoice2("John Doe", issuer_address, "123456789", "Jane Smith", recipient_address, date, address);

    SECTION("Add Products to Invoice")
    {
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);
        invoice.add_product(product5, 10);

        REQUIRE(invoice.get_total_quantity() == 17);
        REQUIRE(invoice.get_total_value() == Catch::Approx(35.5f));
    }

    SECTION("Add Products from Invoice to Invoice")
    {

        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);
        invoice2.add_product(product5, 10);

        invoice += invoice2;

        REQUIRE(invoice.get_total_quantity() == 17);
        REQUIRE(invoice.get_total_value() == Catch::Approx(35.5f));
    }

    SECTION("Remove Product from Invoice")
    {
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);
        invoice.add_product(product5, 10);

        invoice.remove_product(product4);

        REQUIRE(invoice.get_total_quantity() == 12);
        REQUIRE(invoice.get_total_value() == Catch::Approx(28.0f));
    }

    SECTION("Modify Product in Invoice")
    {
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);

        invoice.modify_product(product3, product5, 3);

        REQUIRE_THROWS_WITH(invoice.remove_product(product6), "Product not found");
        REQUIRE_THROWS_WITH(invoice.modify_product(product6, product6, 10), "Product not found");
        REQUIRE(invoice.get_total_quantity() == 8);
        REQUIRE(invoice.get_total_value() == Catch::Approx(9.9f));
    }

    SECTION("Get Total Quantity Cheaper or Equal to Price")
    {
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);
        invoice.add_product(product5, 10);

        REQUIRE(invoice.get_total_quantity_cheaper_equal(1.0f) == 10);
        REQUIRE(invoice.get_total_quantity_cheaper_equal(10.0f) == 17);
    }

    SECTION("Sort Products by Name")
    {
        invoice.add_product(product5, 10);
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);

        auto products_sorted = invoice.get_products_by_name();

        REQUIRE(products_sorted[0].first.get_name() == "book");
        REQUIRE(products_sorted[1].first.get_name() == "pen");
        REQUIRE(products_sorted[2].first.get_name() == "pencil");
    }

    SECTION("Sort Products by Price")
    {
        invoice.add_product(product5, 10);
        invoice.add_product(product3, 2);
        invoice.add_product(product4, 5);

        auto products_sorted = invoice.get_products_by_price();

        REQUIRE(products_sorted[0].first.get_name() == "pencil");
        REQUIRE(products_sorted[1].first.get_name() == "pen");
        REQUIRE(products_sorted[2].first.get_name() == "book");
    }



    SECTION("Less than operator")
    {
        Invoice invoice2("Bob Johnson", issuer_address, "987654321", "Mary Brown", recipient_address, date, address);
        invoice2.add_product(product3, 1);
        invoice2.add_product(product4, 2);

        REQUIRE(invoice < invoice2);
        REQUIRE_FALSE(invoice2 < invoice);
    }

    SECTION("Greater than operator")
    {
        Invoice invoice2("Bob Johnson", issuer_address, "987654321", "Mary Brown", recipient_address, date, address);
        invoice2.add_product(product3, 3);
        invoice2.add_product(product4, 2);

        REQUIRE(invoice2 > invoice);
        REQUIRE_FALSE(invoice > invoice2);
    }

    SECTION("Less than or equal to operator")
    {
        Invoice invoice2("Bob Johnson", issuer_address, "987654321", "Mary Brown", recipient_address, date, address);
        invoice2.add_product(product3, 2);
        invoice2.add_product(product4, 3);

        REQUIRE(invoice <= invoice2);
        REQUIRE(invoice <= invoice);
        REQUIRE_FALSE(invoice2 <= invoice);
    }

    SECTION("Greater than or equal to operator")
    {
        Invoice invoice2("Bob Johnson", issuer_address, "987654321", "Mary Brown", recipient_address, date, address);
        invoice2.add_product(product4, 3);

        REQUIRE(invoice >= invoice);
        REQUIRE_FALSE(invoice >= invoice2);
    }





    SECTION("Invoice addition operator", "[invoice]") {
        // Create two invoices
        Invoice invoice1("Company A", Address("123 Main St", "City A", "12345", "Country A"), "12345", "Company B",
                        Address("456 Main St", "City B", "67890", "Country B"), Date("01.01.2023"), Address("789 Main St", "City C", "13579", "Country C"));
        invoice1.add_product(Product("Product A", "Manufacturer A", 10.0), 2);

        Invoice invoice2("Company A", Address("123 Main St", "City A", "12345", "Country A"), "12345", "Company B",
                        Address("456 Main St", "City B", "67890", "Country B"), Date("01.01.2023"), Address("789 Main St", "City C", "13579", "Country C"));
        invoice2.add_product(Product("Product B", "Manufacturer B", 20.0), 3);

        // Test addition operator
        Invoice invoice3 = invoice1 + invoice2;
        REQUIRE(invoice3.get_issuer_name() == "Company A");
        REQUIRE(invoice3.get_issuer_address().get_street() == "123 Main St");
        REQUIRE(invoice3.get_issuer_address().get_city() == "City A");
        REQUIRE(invoice3.get_issuer_address().get_zip() == "12345");
        REQUIRE(invoice3.get_issuer_address().get_country() == "Country A");
        REQUIRE(invoice3.get_issuer_tax_id() == "12345");
        REQUIRE(invoice3.get_recipient_name() == "Company B");
        REQUIRE(invoice3.get_recipient_address().get_street() == "456 Main St");
        REQUIRE(invoice3.get_recipient_address().get_city() == "City B");
        REQUIRE(invoice3.get_recipient_address().get_zip() == "67890");
        REQUIRE(invoice3.get_recipient_address().get_country() == "Country B");
        REQUIRE(invoice3.get_date().get_day() == 1);
        REQUIRE(invoice3.get_date().get_month() == 1);
        REQUIRE(invoice3.get_date().get_year() == 2023);
        REQUIRE(invoice3.get_address().get_street() == "789 Main St");
        REQUIRE(invoice3.get_address().get_city() == "City C");
        REQUIRE(invoice3.get_address().get_zip() == "13579");
        REQUIRE(invoice3.get_address().get_country() == "Country C");
        REQUIRE(invoice3.get_products_by_name().size() == 2);
        REQUIRE(invoice3.get_products_by_name()[0].first.get_name() == "Product A");
        REQUIRE(invoice3.get_products_by_name()[0].first.get_manufacturer() == "Manufacturer A");
        REQUIRE(invoice3.get_products_by_name()[0].second == 2);
        REQUIRE(invoice3.get_products_by_name()[1].first.get_name() == "Product B");
        REQUIRE(invoice3.get_products_by_name()[1].first.get_manufacturer() == "Manufacturer B");
        REQUIRE(invoice3.get_products_by_name()[1].second == 3);
    }



    SECTION("Test operator+=")
    {
        Invoice invoice7("Issuer 3", issuer_address, "33333333", "Recipient 3", recipient_address, Date("5.3.2023"), address);
        invoice7.add_product(Product("Product A", "Manufacturer A", 8.0), 1);
        invoice7.add_product(Product("Product B", "Manufacturer B", 15.0), 2);

        Invoice invoice8("Issuer 3", issuer_address, "33333333", "Recipient 3", recipient_address, Date("5.3.2023"), address);
        invoice8.add_product(Product("Product C", "Manufacturer C", 6.0), 3);

        invoice7 += invoice8;

        REQUIRE(invoice7.get_issuer_name() == "Issuer 3");
        REQUIRE(invoice7.get_issuer_address().get_street() == "123 Main St.");
        REQUIRE(invoice7.get_issuer_tax_id() == "33333333");
        REQUIRE(invoice7.get_recipient_name() == "Recipient 3");
        REQUIRE(invoice7.get_recipient_address().get_city() == "Othertown");
        REQUIRE(invoice7.get_date().get_day() == 5);
        REQUIRE(invoice7.get_date().get_month() == 3);
        REQUIRE(invoice7.get_date().get_year() == 2023);
        REQUIRE(invoice7.get_address().get_street() == "789 Oak Blvd.");
        REQUIRE(invoice7.get_products_by_name().size() == 3);


        // Check the first item
        REQUIRE(invoice7.get_products_by_name()[0].first.get_name() == "Product A");
        REQUIRE(invoice7.get_products_by_name()[0].first.get_manufacturer() == "Manufacturer A");
        REQUIRE(invoice7.get_products_by_name()[0].second == 1);

        // Check the second item
        REQUIRE(invoice7.get_products_by_name()[1].first.get_name() == "Product B");
        REQUIRE(invoice7.get_products_by_name()[1].first.get_manufacturer() == "Manufacturer B");
        REQUIRE(invoice7.get_products_by_name()[1].second == 2);

        // Check the third item
        REQUIRE(invoice7.get_products_by_name()[2].first.get_name() == "Product C");
        REQUIRE(invoice7.get_products_by_name()[2].first.get_manufacturer() == "Manufacturer C");
        REQUIRE(invoice7.get_products_by_name()[2].second == 3);
    }








}