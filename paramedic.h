#pragma once

#include "employee.h"

class Paramedic : public Employee {
    private:
        static constexpr double base_salary = 4000.0;
        static constexpr double emt_degree_bonus = 500.0;
        static constexpr double experience_bonus = 100.0;

        unsigned int years_of_experience;
        bool has_paramedic_degree;

    public:
        Paramedic(std::string first_name, std::string surname, std::string id_number,
            unsigned int years_of_experience, bool has_paramedic_degree);

        virtual ~Paramedic();

        unsigned int get_years_of_experience() const;
        bool get_has_paramedic_degree() const;

        void set_years_of_experience(unsigned int years_of_experience);
        void set_has_paramedic_degree(bool has_paramedic_degree);

        virtual void print(std::ostream& os) const override;
        virtual double calculate_salary() const override;

};
