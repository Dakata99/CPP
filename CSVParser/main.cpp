#include <iostream>

#include "CSVParser.h"

void run(void)
{
    CSVParser csv;
    csv.parse_file("ex");
    table t = csv.get_data();

    for (size_t i = 0; i < t.size(); i++)
    {
        for (size_t j = 0; j < t[i].size(); j++) std::cout << t[i][j] << '|';
        
        std::cout << std::endl;
    }
    
}

int main(void)
{
    run();

    return 0;
}