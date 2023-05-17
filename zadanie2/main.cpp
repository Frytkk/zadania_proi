// Andrzej Tokajuk

#include <iostream>
#include <sstream>
#include "product.h"

int main(int argc, char* argv[])
{
    if(argc < 6)
    {
        std::cerr << "Incorrect number of command line arguments - expected at least 6, got " << argc << std::endl;
        return 1;
    }

    std::string name;
    unsigned int volume;
    std::string manufacturer;
    std::string batch_number;
    std::string expiration_date;
    std::vector<std::string> ingredients;

    std::stringstream stream;
    stream << argv[1];
    stream >> name;
    stream.clear();
    stream << argv[2];
    if(!(stream >> volume))
    {
        std::cerr << "Volume should be a positive integer" << std::endl;
        return 1;
    }
    stream.clear();
    stream << argv[3];
    stream >> manufacturer;
    stream.clear();
    stream << argv[4];
    stream >> batch_number;
    stream.clear();
    stream << argv[5];
    stream >> expiration_date;


    for (int i = 6; i < argc; i++)
    {
        ingredients.push_back(argv[i]);
    }

    std::cout << "name: " << name << std::endl;
    std::cout << "volume: " << volume << std::endl;
    std::cout << "manufacturer: " << manufacturer << std::endl;
    std::cout << "batch number: " << batch_number << std::endl;
    std::cout << "expiration date: " << expiration_date << std::endl;
    std::cout << "ingredients: ";
    for (auto const& s : ingredients)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
