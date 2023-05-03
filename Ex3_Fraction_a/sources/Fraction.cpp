#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
using namespace ariel;

Fraction ::Fraction(int numerator, int denominator){
    this->numerator =numerator;
    this-> denominator = denominator;
    cout << "exiting a: "<< this-> numerator << "," << this->denominator << endl;
    };

Fraction :: Fraction(){
    this->numerator =0;
    this->denominator = 1;
    cout << "exiting b: "<< this-> numerator << "," << this->denominator << endl;
}

ostream &operator<<(ostream &os, const Fraction &fraction)
{
    return os;
};

int Fraction :: findGCD(int a, int b){
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

Fraction Fraction ::operator+(const Fraction &other)
{
    Fraction f1;
    if(this->denominator == other.denominator){
        f1.numerator =this->numerator + other.numerator;
        f1.denominator =  this->denominator
        return f1;
    }
    else{
        Fraction fResult = Fraction(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
        int x = findGCD(fResult.numerator, fResult.denominator);
        return Fraction(fResult.numerator / x, fResult.denominator / x);  
    }
};

bool Fraction ::operator==(const Fraction &other)
{
    if (this->numerator != other.numerator || this->denominator != other.denominator)
        return false;
    return true;
};

// Fraction Fraction :: operator-(const Fraction& other){
//     return Fraction(1,1);
// };

// Fraction Fraction :: operator*(const Fraction& other){
//     return Fraction(1,1);
// };

// Fraction Fraction :: operator/(const Fraction& other){
//     return Fraction(1,1);
// };

