#pragma once

#include <string>
#include <map>
#include <stdexcept>

class Specialization {
    public:
        static std::map<std::string, unsigned int> specializations;
        static void add_specialization(const std::string& name, unsigned int value);
        static void remove_specialization(const std::string& name);
        static unsigned int* get_value_ptr(const std::string& name);
        static unsigned int get_value(const std::string& name);
};
