namespace ariel{
    class Fraction
    {
    private:
        float val;
    public:
        Fraction(/* args */);
        ~Fraction();
        //sddd
        Fraction operator + (Fraction f);
        Fraction operator - (Fraction f);
        Fraction operator * (Fraction f);
        Fraction operator / (Fraction f);
        bool operator == (Fraction f);
        bool operator > (Fraction f);
        bool operator < (Fraction f);
        bool operator >= (Fraction f);
        bool operator <= (Fraction f);
        bool operator ++ ();
        bool operator -- ();

    };
    
    
}