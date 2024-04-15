#include <stdio.h>
#include "unity.h"
#include "c_library.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_factorial_loop(void) {
    TEST_ASSERT_EQUAL( 1, factorial_loop(0) );
    TEST_ASSERT_EQUAL( 1, factorial_loop(1) );
    TEST_ASSERT_EQUAL( 2, factorial_loop(2) );
    TEST_ASSERT_EQUAL( 6, factorial_loop(3) );
    TEST_ASSERT_EQUAL( 24, factorial_loop(4) );
    TEST_ASSERT_EQUAL( 120, factorial_loop(5) );
}

void test_factorial_recursive(void) {
    TEST_ASSERT_EQUAL( 1, factorial_recursive(0) );
    TEST_ASSERT_EQUAL( 1, factorial_recursive(1) );
    TEST_ASSERT_EQUAL( 2, factorial_recursive(2) );
    TEST_ASSERT_EQUAL( 6, factorial_recursive(3) );
    TEST_ASSERT_EQUAL( 24, factorial_recursive(4) );
    TEST_ASSERT_EQUAL( 120, factorial_recursive(5) );
}

void test_GCD_loop(void) {
    TEST_ASSERT_EQUAL( 0, gcd_loop(0, 0) );
    TEST_ASSERT_EQUAL( 1, gcd_loop(1, 0) );
    TEST_ASSERT_EQUAL( 1, gcd_loop(0, 1) );
    TEST_ASSERT_EQUAL( 1, gcd_loop(1, 1) );
    TEST_ASSERT_EQUAL( 3, gcd_loop(3, 15) );
    TEST_ASSERT_EQUAL( 3, gcd_loop(15, 3) );
    TEST_ASSERT_EQUAL( 1, gcd_loop(3, 17) );
    TEST_ASSERT_EQUAL( 1, gcd_loop(17, 3) );
    TEST_ASSERT_EQUAL( 5, gcd_loop(15, 625) );
    TEST_ASSERT_EQUAL( 5, gcd_loop(625, 15) );
}

void test_GCD_recursive(void) {
    TEST_ASSERT_EQUAL( 0, gcd_recursive(0, 0) );
    TEST_ASSERT_EQUAL( 1, gcd_recursive(1, 0) );
    TEST_ASSERT_EQUAL( 1, gcd_recursive(0, 1) );
    TEST_ASSERT_EQUAL( 1, gcd_recursive(1, 1) );
    TEST_ASSERT_EQUAL( 3, gcd_recursive(3, 15) );
    TEST_ASSERT_EQUAL( 3, gcd_recursive(15, 3) );
    TEST_ASSERT_EQUAL( 1, gcd_recursive(3, 17) );
    TEST_ASSERT_EQUAL( 1, gcd_recursive(17, 3) );
    TEST_ASSERT_EQUAL( 5, gcd_recursive(15, 625) );
    TEST_ASSERT_EQUAL( 5, gcd_recursive(625, 15) );
}

void test_diophantic_loop(void) {
    DiophanticResult res;
    // normal case
    res = diophantic_loop(240, 46, 28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 28, 240 * res.x + 46 * res.y );
    
    res = diophantic_loop(-240, 46, 28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 28, -240 * res.x + 46 * res.y );

    res = diophantic_loop(240, 46, -28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( -28, 240 * res.x + 46 * res.y );

    // c, 0, both values should be 0
    res = diophantic_loop(240, 46, 0);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 0, res.x );
    TEST_ASSERT_EQUAL( 0, res.y );

    // c isn't divisible by GCD, no results
    res = diophantic_loop(240, 46, 3);
    TEST_ASSERT_EQUAL( 1, res.r );

    // a = b = 0, c != 0, no results
    res = diophantic_loop(0, 0, 1);
    TEST_ASSERT_EQUAL( 1, res.r );

    // a = b = c = 0, infinite results
    res = diophantic_loop(0, 0, 0);
    TEST_ASSERT_EQUAL( 2, res.r ); 
}

void test_diophantic_recursive(void) {
    DiophanticResult res;
    // normal case
    res = diophantic_recursive(240, 46, 28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 28, 240 * res.x + 46 * res.y );
    
    res = diophantic_recursive(-240, 46, 28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 28, -240 * res.x + 46 * res.y );

    res = diophantic_recursive(240, 46, -28);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( -28, 240 * res.x + 46 * res.y );

    // c, 0, both values should be 0
    res = diophantic_recursive(240, 46, 0);
    TEST_ASSERT_EQUAL( 0, res.r );
    TEST_ASSERT_EQUAL( 0, res.x );
    TEST_ASSERT_EQUAL( 0, res.y );

    // c isn't divisible by GCD, no results
    res = diophantic_recursive(240, 46, 3);
    TEST_ASSERT_EQUAL( 1, res.r );

    // a = b = 0, c != 0, no results
    res = diophantic_recursive(0, 0, 1);
    TEST_ASSERT_EQUAL( 1, res.r );

    // a = b = c = 0, infinite results
    res = diophantic_recursive(0, 0, 0);
    TEST_ASSERT_EQUAL( 2, res.r ); 
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_factorial_loop);
    RUN_TEST(test_factorial_recursive);
    RUN_TEST(test_GCD_loop);
    RUN_TEST(test_GCD_recursive);
    RUN_TEST(test_diophantic_loop);
    RUN_TEST(test_diophantic_recursive);
    return UNITY_END();
}
