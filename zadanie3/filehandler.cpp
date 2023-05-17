#include "filehandler.h"

std::vector<std::string> Filehandler::read_lines(const std::string& file_name)
{
    std::vector<std::string> lines;
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << file_name << std::endl;
        return lines;
    }
    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}
