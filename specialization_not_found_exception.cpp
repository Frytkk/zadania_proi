#include "specialization_not_found_exception.h"

SpecializationNotFoundException::SpecializationNotFoundException(std::string specialization):
    std::invalid_argument("Specialization having the following name not found: " + specialization){}
