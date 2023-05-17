// Andrzej Tokajuk

#include "catch_amalgamated.hpp"
#include "../product.h"

TEST_CASE("product tests", "[product]")
{
    std::string name = "Milk";
    std::string manufacturer = "Mlekovita";
    std::string batch_number = "1234567";
    std::string expiration_date = "01.01.2023";
    std::vector<std::string> ingredients = {"milk", "sugar"};
    Product milk(name , 500, manufacturer, batch_number, expiration_date, {"milk", "sugar"});
    ExpirationDate date1(expiration_date);

    SECTION("testing constructor")
    {
        CHECK(date1.get_day() == 1);
        CHECK(date1.get_month() == 1);
        CHECK(date1.get_year() == 2023);

        CHECK(milk.get_name() == "Milk");
        CHECK(milk.get_manufacturer() == "Mlekovita");
        CHECK(milk.get_batch_number() == "1234567");
        CHECK(milk.get_expiration_date() == date1);
        CHECK(milk.get_ingredients() == ingredients);
        CHECK(milk.get_ingredients_number() == 2);
    }

    SECTION("modifications of date")
    {
        date1.set_day(4);
        date1.set_month(2);
        date1.set_year(2022);

        CHECK(date1.get_day() == 4);
        CHECK(date1.get_month() == 2);
        CHECK(date1.get_year() == 2022);

        date1.set_day(28);

        CHECK(date1.get_day() == 28);
    }

    SECTION("modifications of strings")
    {
        milk.set_name("Water");
        milk.set_manufacturer("Cisowianka");
        milk.set_batch_number("1234");

        CHECK(milk.get_name() == "Water");
        CHECK(milk.get_manufacturer() == "Cisowianka");
        CHECK(milk.get_batch_number() == "1234");
    }

    SECTION("modifications of date 2")
    {
        milk.set_expiration_date("19.12.2000");
        ExpirationDate date2("19.12.2000");
        CHECK(milk.get_expiration_date() == date2);

        date2.set_day(5);
        CHECK(date2.get_day() == 5);
        date2.set_month(10);
        CHECK(date2.get_month() == 10);
        date2.set_year(2001);
        CHECK(date2.get_year() == 2001);
    }

    SECTION("modifications of volume and ingredients")
    {
        milk.set_volume(1000);
        milk.add_ingredient("salt");
        ingredients.push_back("salt");

        CHECK(milk.get_volume() == 1000);
        CHECK(milk.get_ingredients() == ingredients);
        CHECK(milk.get_ingredients_number() == 3);

        milk.del_ingredient("sugar");
        ingredients = {"milk", "salt"};
        CHECK(milk.get_ingredients() == ingredients);
        CHECK(milk.get_ingredients_number() == 2);
        CHECK(milk.is_ingredient_present("milk") == true);
        CHECK(milk.is_ingredient_present("sugar") == false);

        milk.modify_ingredient("milk", "water");
        ingredients = {"water", "salt"};
        CHECK(milk.get_ingredients() == ingredients);

        milk.set_ingredients({"coconut", "oil", "peanuts"});
        ingredients = {"coconut", "oil", "peanuts"};
        CHECK(milk.get_ingredients() == ingredients);
        CHECK(milk.get_ingredients_number() == 3);
    }
}