#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;

ariel::Fraction a(1,1);


namespace ariel{
    Fraction::Fraction(const int& num,const int& den):
        _num(num), _den(den){
        if (den == 0) {
            throw std::invalid_argument("denominator cannot be 0");
        }
    }

    // Setters
    void Fraction::setNum(int num) {
        _num = num;
    }

    void Fraction::setDen(int den) {
        _den = den;
    }
    
    Fraction Fraction::reduceFrac(Fraction& frac1){
        bool neg = false;
        int t_den = frac1.den();
        int t_num = frac1.num();
        //check if number is negative
        if(t_den < 0 && t_num < 0){
            t_den = -1 * t_den;
            t_num = -1 * t_num;
        }
        else if(t_den < 0){
            neg = true;
            t_den = -1 * t_den;
        }
        else if(t_num < 0){
            neg = true;
            t_num = -1 * t_num;
        }
        int minFrac = min(t_den, t_num);
        for (int i = minFrac; i > 0; i--)
        {
            if(t_den % i == 0 && t_num % i == 0){
                t_den = t_den / i;
                t_num = t_num / i;
            }
        }
        // if num is negative add the minus
        if(neg){
            t_num = -1 * t_num;
        }
        frac1 = Fraction(t_num, t_den);
        return frac1;
    }


    Fraction Fraction::float2fract(float& num){
        int n_den = 1000;
        int n_num = num * 1000;
        Fraction ans(n_num, n_den);
        return ans.reduceFrac(ans);
    }
    
//prefix addition
    Fraction& Fraction::operator++(){
        _num += _den;
        return *this;
    }

//postfix addition
    Fraction Fraction::operator++(int){
        Fraction tmp(_num, _den);
        _num += _den;
        return tmp;
    }

//prefix substraction
    Fraction& Fraction::operator--(){
        _num -= _den;
        return *this;
    }

//postfix substraction
    Fraction Fraction::operator--(int){
        Fraction tmp(_num, _den);
        _num -= _den;
        return tmp;
    }


//sum operators
    Fraction operator+(const Fraction& frac1, const Fraction& frac2){
        int new_num = (frac1.num() * frac2.den()) + (frac2.num() * frac1.den()); 
        int new_den = frac1.den() * frac2.den();
        Fraction ans = Fraction(new_num, new_den);
        return ans.reduceFrac(ans);
    }

    Fraction operator+(const Fraction& frac1, float frac2){
        Fraction n_frac = a.Fraction::float2fract(frac2);
        return frac1 + n_frac;
    }

    Fraction operator+(float frac1, const Fraction& frac2){
        Fraction n_frac = a.Fraction::float2fract(frac1);
        return frac2 + n_frac;
    }

//multiplication operators
    Fraction operator*(const Fraction& frac1, const Fraction& frac2){
        int new_num = frac1.num() * frac2.num(); 
        int new_den = frac1.den() * frac2.den();
        Fraction ans = Fraction(new_num, new_den);
        return ans.reduceFrac(ans);
    }

    Fraction operator*(const Fraction& frac1, float frac2){
        Fraction n_frac = a.Fraction::float2fract(frac2);
        return frac1 * n_frac;
    }

    Fraction operator*(float frac1, const Fraction& frac2){
        Fraction n_frac = a.Fraction::float2fract(frac1);
        return frac2 * n_frac;
    }

//subtraction operators
    Fraction operator-(const Fraction& frac1, const Fraction& frac2){
        int new_num = (frac1.num() * frac2.den()) - (frac2.num() * frac1.den()); 
        int new_den = frac1.den() * frac2.den();
        Fraction ans = Fraction(new_num, new_den);
        return ans.reduceFrac(ans);
    }

    Fraction operator-(const Fraction& frac1, float frac2){
        Fraction n_frac = a.Fraction::float2fract(frac2);
        return frac1 - n_frac;
    }

    Fraction operator-(float frac1, const Fraction& frac2){
        Fraction n_frac = a.Fraction::float2fract(frac1);
        return n_frac - frac2;
    }

//division operators
    Fraction operator/(const Fraction& frac1, const Fraction& frac2){
        int new_num = frac1.num() * frac2.den(); 
        int new_den = frac1.den() * frac2.num();
        Fraction ans = Fraction(new_num, new_den);
        return ans.reduceFrac(ans);
    }

    Fraction operator/(const Fraction& frac1, float frac2){
        Fraction n_frac = a.Fraction::float2fract(frac2);
        return frac1 / n_frac;
    }

    Fraction operator/(float frac1, const Fraction& frac2){
        Fraction n_frac = a.Fraction::float2fract(frac1);
        return n_frac / frac2;
    }

//comparison operators - equal
    bool operator==(const Fraction& frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.num() == 0){
            return true;
        }
        return false;
    }

    bool operator==(float frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.num() == 0){
            return true;
        }
        return false;
    }

    bool operator==(const Fraction& frac1, float frac2){
        Fraction ans = frac1 - frac2;
        if(ans.num() == 0){
            return true;
        }
        return false;
    }

//comparison operators - greater than
    bool operator>(const Fraction& frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

    bool operator>(float frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

    bool operator>(const Fraction& frac1, float frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

//comparison operators - less than
    bool operator<(const Fraction& frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() < 0){
            return true;
        }
        return false;
    }
 
    bool operator<(float frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() < 0){
            return true;
        }
        return false;
    }
 
    bool operator<(const Fraction& frac1, float frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() < 0){
            return true;
        }
        return false;;
    }
 
//comparison operators - greater than or equal to
    bool operator>=(const Fraction& frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

    bool operator>=(float frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

    bool operator>=(const Fraction& frac1, float frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() > 0 && ans.num() > 0){
            return true;
        }
        return false;
    }

//comparison operators -  less than or equal to
    bool operator<=(const Fraction& frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() <= 0){
            return true;
        }
        return false;
    }
 
    bool operator<=(float frac1, const Fraction& frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() <= 0){
            return true;
        }
        return false;
    }
 
    bool operator<=(const Fraction& frac1, float frac2){
        Fraction ans = frac1 - frac2;
        if(ans.den() < 0 && ans.num() < 0){
            return false;
        }
        else if(ans.den() < 0 || ans.num() <= 0){
            return true;
        }
        return false;
    }

    ostream &operator<<(ostream &out, const Fraction &other)
    {
        out << other.num() << "/" << other.den() << endl;
        return out;
    }
    // istream &operator>>(istream &into, Fraction &other)
    // {
    //     into >> other.num() >> other.den();
    //     return into;
    // }

}