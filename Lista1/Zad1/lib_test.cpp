#include <iostream>
#include <stdio.h>
#include "catch_amalgamated.hpp"
#include "lib.h"

#define CONFIG_CATCH_MAIN

TEST_CASE("Factorial loop") {
    REQUIRE( factorial_loop(0) == 1 );
    REQUIRE( factorial_loop(1) == 1 );
    REQUIRE( factorial_loop(2) == 2 );
    REQUIRE( factorial_loop(3) == 6 );
    REQUIRE( factorial_loop(4) == 24 );
    REQUIRE( factorial_loop(5) == 120 );
}

TEST_CASE("Factorial recursive") {
    REQUIRE( factorial_recursive(0) == 1 );
    REQUIRE( factorial_recursive(1) == 1 );
    REQUIRE( factorial_recursive(2) == 2 );
    REQUIRE( factorial_recursive(3) == 6 );
    REQUIRE( factorial_recursive(4) == 24 );
    REQUIRE( factorial_recursive(5) == 120 );
}

TEST_CASE("GCD loop") {
    REQUIRE( gcd_loop(0, 0) == 0 );
    REQUIRE( gcd_loop(1, 0) == 1 );
    REQUIRE( gcd_loop(0, 1) == 1 );
    REQUIRE( gcd_loop(1, 1) == 1 );
    REQUIRE( gcd_loop(3, 15) == 3 );
    REQUIRE( gcd_loop(15, 3) == 3 );
    REQUIRE( gcd_loop(3, 17) == 1 );
    REQUIRE( gcd_loop(17, 3) == 1 );
    REQUIRE( gcd_loop(15, 625) == 5 );
    REQUIRE( gcd_loop(625, 15) == 5 );
}

TEST_CASE("GCD recursive") {
    REQUIRE( gcd_recursive(0, 0) == 0 );
    REQUIRE( gcd_recursive(1, 0) == 1 );
    REQUIRE( gcd_recursive(0, 1) == 1 );
    REQUIRE( gcd_recursive(1, 1) == 1 );
    REQUIRE( gcd_recursive(3, 15) == 3 );
    REQUIRE( gcd_recursive(15, 3) == 3 );
    REQUIRE( gcd_recursive(3, 17) == 1 );
    REQUIRE( gcd_recursive(17, 3) == 1 );
    REQUIRE( gcd_recursive(15, 625) == 5 );
    REQUIRE( gcd_recursive(625, 15) == 5 );
}

TEST_CASE("Diophantic equation loop") {
    int res, val1, val2;
    // normal case
    std::tie(res ,val1, val2) = diophantic_loop(240, 46, 28);
    REQUIRE( res == 0 );
    REQUIRE( 240 * val1 + 46 * val2 == 28 );
    
    std::tie(res ,val1, val2) = diophantic_loop(-240, 46, 28);
    REQUIRE( res == 0 );
    REQUIRE( -240 * val1 + 46 * val2 == 28 );

    std::tie(res ,val1, val2) = diophantic_loop(240, 46, -28);
    REQUIRE( res == 0 );
    REQUIRE( 240 * val1 + 46 * val2 == -28 );

    // c == 0, both values should be 0
    std::tie(res ,val1, val2) = diophantic_loop(240, 46, 0);
    REQUIRE( res == 0 );
    REQUIRE( val1 == 0 );
    REQUIRE( val2 == 0);

    // c isn't divisible by GCD, no results
    std::tie(res ,val1, val2) = diophantic_loop(240, 46, 3);
    REQUIRE( res == 1 );

    // a = b = 0, c != 0, no results
    std::tie(res ,val1, val2) = diophantic_loop(0, 0, 1);
    REQUIRE( res == 1 );

    // a = b = c = 0, infinite results
    std::tie(res ,val1, val2) = diophantic_loop(0, 0, 0);
    REQUIRE( res == 2 ); 
}

TEST_CASE("Diophantic equation recursive") {
    int res, val1, val2;
    // normal case
    std::tie(res ,val1, val2) = diophantic_recursive(240, 46, 28);
    REQUIRE( res == 0 );
    REQUIRE( 240 * val1 + 46 * val2 == 28 );
    
    std::tie(res ,val1, val2) = diophantic_recursive(-240, 46, 28);
    REQUIRE( res == 0 );
    REQUIRE( -240 * val1 + 46 * val2 == 28 );

    std::tie(res ,val1, val2) = diophantic_recursive(240, 46, -28);
    REQUIRE( res == 0 );
    REQUIRE( 240 * val1 + 46 * val2 == -28 );

    // c == 0, both values should be 0
    std::tie(res ,val1, val2) = diophantic_recursive(240, 46, 0);
    REQUIRE( res == 0 );
    REQUIRE( val1 == 0 );
    REQUIRE( val2 == 0);

    // c isn't divisible by GCD, no results
    std::tie(res ,val1, val2) = diophantic_recursive(240, 46, 3);
    REQUIRE( res == 1 );

    // a = b = 0, c != 0, no results
    std::tie(res ,val1, val2) = diophantic_recursive(0, 0, 1);
    REQUIRE( res == 1 );

    // a = b = c = 0, infinite results
    std::tie(res ,val1, val2) = diophantic_recursive(0, 0, 0);
    REQUIRE( res == 2 ); 
}