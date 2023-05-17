#pragma once

#include <string>
#include "employee.h"
#include "specialization.h"


class Doctor : public Employee {
    private:
        std::string specialization;
        unsigned int years_of_experience;
        static constexpr double base_salary = 10000.0;

    public:
        Doctor(std::string name, std::string surname, std::string id_number,
            std::string specialization, unsigned int years_of_experience);

        virtual ~Doctor();

        std::string get_specialization() const;
        unsigned int get_years_of_experience() const;

        void set_specialization(std::string specialization);
        void set_years_of_experience(unsigned int years_of_experience);

        virtual void print(std::ostream& os) const override;
        virtual double calculate_salary() const override;

        friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor);
};
