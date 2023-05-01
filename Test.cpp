
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE("Create fractions") {
    Fraction a(1,2), b(2,4);
    CHECK_EQ(a, b);
    Fraction c(0,3);
    CHECK_EQ(c, 0);
    CHECK_THROWS_AS(Fraction(2, 0), std::invalid_argument);

}

TEST_CASE("Check sum"){
    float x = -5.324563;
    Fraction a(1, 2), b(2, 4), c(17, 17);
    CHECK_EQ(a+b, c);
    Fraction e(-2, -4);
    CHECK_EQ(a+e, c);
    Fraction f(-1, 2);
    CHECK_EQ(f+e, 0);
}


TEST_CASE("Check sum"){
    Fraction a(1, 2), b(2, 4), c(17, 17);
    CHECK_EQ(a+b, c);
    Fraction e(-2, -4);
    CHECK_EQ(a+e, c);
    Fraction f(-1, 2);
    CHECK_EQ(f+e, 0);
}


TEST_CASE("Check sum"){
    Fraction a(1, 2), b(2, 4), c(17, 17);
    CHECK_EQ(a+b, c);
    Fraction e(-2, -4);
    CHECK_EQ(a+e, c);
    Fraction f(-1, 2);
    CHECK_EQ(f+e, 0);
}


TEST_CASE("Check subtract"){
    Fraction a(1, 5), b(2, 10), c(0, 5);
    CHECK_EQ(a-b, c);
    Fraction e(-5, 25), d(2, 5);
    CHECK_EQ(a-e, d);
    CHECK_EQ(c-e, a);
}


TEST_CASE("Check multiply"){
    Fraction a(1, 2), b(2, 4), c(1, 4);
    CHECK_EQ(a*b, c);
    Fraction d(1, -4), e(-2, 4);
    CHECK_EQ(a*e, d);
    Fraction f(0, 2);
    CHECK_EQ(f*e, 0);
}

TEST_CASE("Check divide"){
    Fraction a(1, 2), b(2, 4), c(1, 4);
    CHECK_EQ(a/b, 1);
    CHECK_EQ(b/c, 2);
    Fraction d(1, -4), e(-2, 4), f(0, 2);
    CHECK_EQ(f/e, 0);
    CHECK_EQ(d/0.5, e);
}

TEST_CASE("Check booleans"){
    Fraction a(1, 2), b(2, 4), c(1, 4);
    CHECK_EQ(a>b, false);
    CHECK_EQ(a<b, false);
    CHECK_EQ(a==b, true);
    CHECK_EQ(b>=c, true);
    Fraction d(1, -4), e(-2, 4), f(0, 2), g(2,-4);
    CHECK_EQ(e==g, true);
    CHECK_EQ(d<=f, true);
    CHECK_EQ(f==0, true);
    CHECK_EQ(-1*e==b, true);
}

TEST_CASE("Check addition or substraction of 1"){
    Fraction a(1, 2), b(2, 4), c(1, 4);
    CHECK_EQ(a/b, 1);
    CHECK_EQ(b/c, 2);
    Fraction d(1, -4), e(-2, 4), f(0, 2);
    CHECK_EQ(f/e, 0);
    CHECK_EQ(d/0.5, e);
}

TEST_CASE("Check addition or substraction of 1"){
    Fraction a(1, 2), b(2, 4), c(755, 900);

    Fraction d(1, -4), e(-2, 4), f(0, 2);
    CHECK_EQ(f/e, 0);
    CHECK_EQ(d/0.5, e);
}


TEST_CASE("Check addition or substraction of 1"){
    Fraction a(1, 2), b(-1, 2), c(3,2);
    Fraction d(-1, 4), e(-5, 4), f(3,4);
    // Fraction ans = a++;
    CHECK_EQ(--a, b);
    a++;
    CHECK_EQ(++a, c);
    CHECK_EQ(--d, e);
    d++;
    CHECK_EQ(++d, f);
}

