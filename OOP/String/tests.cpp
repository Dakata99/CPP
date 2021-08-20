#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING

#include <iostream>

#include "doctest.h"
#include "String.h"
#include "tests.h"

int main(void)
{
    doctest::Context().run();

    return 0;
}