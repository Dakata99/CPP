TEST_CASE("CHECK FOR A DOUBLE NUMBER")
{
    CHECK(is_number("1.0") == true);
    CHECK(is_number("-1.0") == true);
    CHECK(is_number("1.25") == true);
    CHECK(is_number("-1.25") == true);
    CHECK(is_number("1.0.0") == false);
    CHECK(is_number("1") == true);
    CHECK(is_number("-1") == true);
    CHECK(is_number("123124356.2134657") == true);
    CHECK(is_number("-123124356.2134657") == true);
}