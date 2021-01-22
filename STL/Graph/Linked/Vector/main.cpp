#include <iostream>
#include "Graph.h"
#include "GList.h"
#include "GEList.h"
#include "GMatrix.h"
#include <string>

typedef void (*fp_t)(void);

//#include "GListTests.cpp"
#include "GEListTests.cpp"
//#include "GMatrixTests.cpp"


int main(void)
{
    //glist_tests();
    gelist_tests();

    return 0;
}