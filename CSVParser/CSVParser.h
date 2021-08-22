#ifndef _CSV_PARSER_H_
#define _CSV_PARSER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

typedef std::vector<std::vector<std::string>> table;

enum State { DATA = 0, COMMA, QUOTED, END, };

class CSVParser
{
private:
    std::ifstream ifs;
    table t;

    void read(void);

public:
    void parse_file(const std::string&);
    std::vector<std::vector<std::string>> get_data(void) const;
};

#endif