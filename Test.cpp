#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
TEST_CASE("Correct Init"){
    Fraction a(5,3);
    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 3);
}
TEST_CASE("Correct Init with negative"){
    Fraction a(-5,3);
    CHECK(a.getNumerator() == -5);
    CHECK(a.getDenominator() == 3);
}
TEST_CASE("Correct Reduce"){
    Fraction a(10,5);
    CHECK(a.getNumerator() == 2);
    CHECK(a.getDenominator() == 1);
}
TEST_CASE("Denominator can't be 0"){
    CHECK_THROWS(Fraction(5,0));
}
TEST_CASE("Increment"){
    Fraction a(5,3);
    a++;
    CHECK(a.getNumerator() == 8);
    CHECK(a.getDenominator() == 3);
}
TEST_CASE("Decrement"){
    Fraction a(5,3);
    a--;
    CHECK(a.getNumerator() == 2);
    CHECK(a.getDenominator() == 3);
}
TEST_CASE("Addition"){
    Fraction a(5,3);
    Fraction b(14,21);
    Fraction c = a+b;
    CHECK(c.getNumerator() == 7);
    CHECK(c.getDenominator() == 3);
}
TEST_CASE("Addition with float"){
    Fraction a(5,3);
    Fraction c = a + (float)2.5;
    CHECK(c.getNumerator() == 25);
    CHECK(c.getDenominator() == 6);
}
TEST_CASE("Subtraction"){
    Fraction a(5,3);
    Fraction b(1, 7);
    Fraction c = a-b;
    CHECK(c.getNumerator() == 32);
    CHECK(c.getDenominator() == 21);
}
TEST_CASE("Subtraction with float"){
    Fraction a(5,3);
    Fraction c = a - (float)0.45;
    CHECK(c.getNumerator() == 73);
    CHECK(c.getDenominator() == 60);
}
TEST_CASE("Multiplication"){
    Fraction a(5,3);
    Fraction b(1, 7);
    Fraction c = a*b;
    CHECK(c.getNumerator() == 5);
    CHECK(c.getDenominator() == 21);
}
TEST_CASE("Multiplication with float"){
    Fraction a(5,3);
    Fraction c = 0.45 * a;
    CHECK(c.getNumerator() == 3);
    CHECK(c.getDenominator() == 4);
}