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