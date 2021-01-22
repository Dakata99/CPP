#include <iostream>
#include "../Graph.h"
#include "GEList.h"
#include "OWTests.cpp"
#include "ONWTests.cpp"
#include "NOWTests.cpp"
#include "NONWTests.cpp"
#include <string>

typedef void (*fp_t)(void);

void tests(void)
{
    fp_t func[] = { OW_tests, ONWTests, NOWTests, NONWTests };

    func[0]();
    //func[1]();
    //func[2]();
    //func[3]();
}

int main(void)
{
    tests();

    return 0;
}