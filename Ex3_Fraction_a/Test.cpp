#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;
using namespace doctest;
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>

TEST_CASE("constructor"){
    Fraction a(1,2);
    Fraction b;
}




TEST_CASE("operator =="){
    Fraction a(5,3), b(5,3);
    for( int i=0; i<20; i++){
        CHECK(a == b);
    }
}

TEST_CASE("operator +"){
    Fraction a(5,3), b(14,21);
    CHECK(a+b == Fraction(49,21));
}

// TEST_CASE("operator -"){
//     Fraction a(5,3), b(14,21);
//     CHECK(a-b == Fraction(21,21));
// }

// TEST_CASE("operator *"){
//     Fraction a(5,3), b(14,21);
//     CHECK(a*b == Fraction(70,63));
// }

// TEST_CASE("operator /"){
//     Fraction a(5,3), b(14,21);
//     CHECK(a/b == Fraction(5,3)/Fraction(105,42));
// }

