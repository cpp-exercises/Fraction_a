#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#pragma once
using namespace std;
namespace ariel{


    class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        int gcd(int a, int b);
        Fraction(int nume, int deno){
            if(deno == 0){
                throw std::invalid_argument("Math: can't devide by 0");
            }
            this->numerator = nume;
            this->denominator = deno;
        }
        Fraction operator+(const Fraction& other);
        Fraction operator+(double num);
        Fraction operator-(const Fraction& other);
        Fraction operator-(double num);
        Fraction operator*(const Fraction& other);
        Fraction operator*(double num);
        Fraction operator/(const Fraction& other);
        Fraction operator/(double num);

        bool operator==(const Fraction& other);
        bool operator==(double num);
        bool operator>(const Fraction& other);
        bool operator>(double num);
        bool operator<(const Fraction& other);
        bool operator<(double num);
        bool operator>=(const Fraction& other) const;
        bool operator>=(double num);
        bool operator<=(const Fraction& other);
        bool operator<=(double num);

        Fraction operator++(int); // postfix
        Fraction operator--(int); // postfix
        Fraction &operator++(); // prefix
        Fraction &operator--(); // prefix

        friend ostream& operator<<(ostream& ost, const Fraction& frc);
        friend istream& operator>>(istream& ist, Fraction& frc);

        int getNumerator() {
            return this->numerator;
        }
        int getDenominator() {
            return this->denominator;
        }
    };
}