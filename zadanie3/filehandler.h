#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Filehandler
{
    public:
        static std::vector<std::string> read_lines(const std::string& file_name);
};


