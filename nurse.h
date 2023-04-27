#pragma once

#include "employee.h"

class Nurse : public Employee {
private:
    unsigned int years_of_experience;
    bool has_nursing_degree;
    static constexpr double base_salary = 3000.0;
    static constexpr double experience_bonus = 50.0;
    static constexpr double nursing_degree_bonus = 200.0;

public:
    Nurse(std::string first_name, std::string surname, std::string id_number,
        unsigned int years_of_experience, bool has_nursing_degree);
    ~Nurse();

    unsigned int get_years_of_experience() const;
    bool get_has_nursing_degree() const;

    void set_years_of_experience(unsigned int years_of_experience);
    void set_has_nursing_degree(bool has_nursing_degree);

    virtual void print(std::ostream& os) const override;
    virtual double calculate_salary() const override;

    friend std::ostream& operator<<(std::ostream& os, const Nurse& nurse);
};
