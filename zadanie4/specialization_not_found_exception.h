#pragma once
#include <stdexcept>


class SpecializationNotFoundException : public std::invalid_argument
{
    public:
        SpecializationNotFoundException(std::string specialization);
};


