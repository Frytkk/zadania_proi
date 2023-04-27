#pragma once

#include <string>

class Employee{
    protected:
        std::string first_name;
        std::string surname;
        std::string id_number;

    public:
        Employee(std::string first_name, std::string surname, std::string id_number);
        virtual ~Employee();

        std::string get_first_name() const;
        std::string get_surname() const;
        std::string get_id_number() const;

        void set_first_name(std::string first_name);
        void set_surname(std::string surname);
        void set_id_number(std::string id_number);

        virtual void print(std::ostream& os) const;
        virtual double calculate_salary() const;

        friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
        bool operator==(const Employee& other) const;
};