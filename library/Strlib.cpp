#include "Strlib.h"

bool is_number(const std::string& num)
{
    std::regex double_num("^(-|)[0-9]+(\\.[0-9]+)?$");

    return std::regex_match(num, double_num);
}