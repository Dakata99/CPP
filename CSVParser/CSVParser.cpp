#include "CSVParser.h"
/*
void CSVParser::read(void)
{
    std::string line;
    std::vector<std::string> vec;
    State st = DATA;
    while (ifs >> std::noskipws >> line)
    {
        std::string value;
        for (size_t i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case ',': st = COMMA; break;
            case '"': st = QUOTED; break;
            case '\n': st = END; break;
            default: break;
            }

            switch (st)
            {
            case DATA: value.push_back(line[i]); break;
            case COMMA:
                vec.push_back(value);
                value.clear();
                break;
            case QUOTED: break;
            case END:
                t.push_back(vec);
                vec.clear();
                break;
            default: break;
            }
        }
    }
}
*/
void CSVParser::read(void)
{
    char symbol;
    std::vector<std::string> vec;
    State st = DATA;

    std::string value;
    while (ifs >> std::noskipws >> symbol)
    {
        switch (symbol)
        {
        case ',': st = COMMA; break;
        case '"': st = QUOTED; break;
        case '\n': st = END; break;
        default: break;
        }

        switch (st)
        {
        case DATA: value.push_back(symbol); break;
        case COMMA:
            vec.push_back(value);
            value.clear();
            st = DATA;
            break;
        case QUOTED: value.push_back(symbol); break;
        case END:
            t.push_back(vec);
            vec.clear();
            st = DATA;
            break;
        default: break;
        }
    }
}

void CSVParser::parse_file(const std::string& file_name)
{
    ifs.open(file_name);
    
    if (ifs.is_open())
        read();
    else
        printf("Could not open file %s...\n", file_name.c_str());
}

std::vector<std::vector<std::string>> CSVParser::get_data(void) const { return t; }