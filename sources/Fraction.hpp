#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
using namespace std;

namespace ariel{
    class Fraction{
        private:
        int _num, _den; //numerator, denominator
        public:
        Fraction(const int& num,const int& den);
        //setters
        void setNum(int);
        void setDen(int);
        //getters
        int num() const{
            return _num;
        }
        int den() const{
            return _den;
        }
        Fraction reduceFrac(Fraction&);
        Fraction float2fract(float&);
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);
        // int getNum();
        // void setDen(int);
        // int getDen();
        //constuctor
    };
    Fraction operator+(const Fraction&, float);
    Fraction operator+(float, const Fraction&);
    Fraction operator+(const Fraction&, const Fraction&);
    Fraction operator-(const Fraction&, float);
    Fraction operator-(float, const Fraction&);
    Fraction operator-(const Fraction&, const Fraction&);
    Fraction operator*(const Fraction&, float);
    Fraction operator*(float, const Fraction&);
    Fraction operator*(const Fraction&, const Fraction&);
    Fraction operator/(const Fraction&, float);
    Fraction operator/(float, const Fraction&);
    Fraction operator/(const Fraction&, const Fraction&);
    bool operator==(const Fraction&, float);
    bool operator==(float, const Fraction&);
    bool operator==(const Fraction&, const Fraction&);
    bool operator>(const Fraction&, float);
    bool operator>(float, const Fraction&);
    bool operator>(const Fraction&, const Fraction&);
    bool operator<(const Fraction&, float);
    bool operator<(float, const Fraction&);
    bool operator<(const Fraction&, const Fraction&);
    bool operator>=(const Fraction&, float);
    bool operator>=(float, const Fraction&);
    bool operator>=(const Fraction&, const Fraction&);
    bool operator<=(const Fraction&, float);
    bool operator<=(float, const Fraction&);
    bool operator<=(const Fraction&, const Fraction&);
    ostream &operator<<(ostream &, const Fraction &);
    istream &operator>>(istream &, Fraction &);
}

#endif