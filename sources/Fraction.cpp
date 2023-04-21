#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace ariel;
int Fraction::gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
Fraction Fraction::operator+(const Fraction& other){
    int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator+(double num){
    int newNumerator = this->numerator + num * this->denominator;
    int newDenominator = this->denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator-(const Fraction& other){
    int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator-(double num){
    int newNumerator = this->numerator - num * this->denominator;
    int newDenominator = this->denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator*(const Fraction& other){
    int newNumerator = this->numerator * other.numerator;
    int newDenominator = this->denominator * other.denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator*(double num){
    int newNumerator = this->numerator * num;
    int newDenominator = this->denominator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator/(const Fraction& other){
    int newNumerator = this->numerator * other.denominator;
    int newDenominator = this->denominator * other.numerator;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
Fraction Fraction::operator/(double num){
    int newNumerator = this->numerator;
    int newDenominator = this->denominator * num;
    int gcd = this->gcd(newNumerator, newDenominator);
    return Fraction(newNumerator/gcd, newDenominator/gcd);
}
bool Fraction::operator==(const Fraction& other){
    return (this->numerator == other.numerator && this->denominator == other.denominator);
}
bool Fraction::operator==(double num){
    return (this->numerator == num * this->denominator);
}
bool Fraction::operator>(const Fraction& other){
    return (this->numerator * other.denominator > other.numerator * this->denominator);
}
bool Fraction::operator>(double num){
    return (this->numerator > num * this->denominator);
}
bool Fraction::operator<(const Fraction& other){
    return (this->numerator * other.denominator < other.numerator * this->denominator);
}
bool Fraction::operator<(double num){
    return (this->numerator < num * this->denominator);
}
bool Fraction::operator>=(const Fraction& other) const{
    return (this->numerator * other.denominator >= other.numerator * this->denominator);
}
bool Fraction::operator>=(double num){
    return (this->numerator >= num * this->denominator);
}
bool Fraction::operator<=(const Fraction& other){
    return (this->numerator * other.denominator <= other.numerator * this->denominator);
}
bool Fraction::operator<=(double num){
    return (this->numerator <= num * this->denominator);
}
Fraction Fraction::operator++(int){
    Fraction temp = *this;
    this->numerator += this->denominator;
    return temp;
}
Fraction& Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
}
Fraction Fraction::operator--(int){
    Fraction temp = *this;
    this->numerator -= this->denominator;
    return temp;
}
Fraction& Fraction::operator--(){
    this->numerator -= this->denominator;
    return *this;
}
ostream& Fraction::operator<<(ostream& os, const Fraction& other){
    os << other.numerator << "/" << other.denominator;
    return os;
}
istream& Fraction::operator>>(istream& is, Fraction& other){
    char c;
    is >> other.numerator >> c >> other.denominator;
    return is;
}


