#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

int adding(int number1, int number2)
{
    return 0;
}

TEST_CASE("Adding0and0")
{
    int number1 = 0;
    int number2 =0;
    REQUIRE(adding(0,0) == number1+number2);
}
