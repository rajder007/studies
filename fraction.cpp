#include <iostream>
#include <vector> // zadanie 3
#include <algorithm> // std::sort() zadanie 3
using namespace std;

class Fraction
{
    int numerator, denominator;
public:
    /// i., oraz ii.:
    Fraction(int numerator=1, int denominator=1) : numerator(numerator), denominator(denominator)
    {
        exercise3_addFraction2Vector();
    }
//    /// alternatywnie:
//    /// i.:
//    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
//    { exercise3_addFraction2Vector(); }
//    /// ii.:
//    Fraction() : numerator(1), denominator(1)
//    { exercise3_addFraction2Vector(); }

    /// iii.:
    int getNumerator() const
    {
        return numerator;
    }
    void setNumerator(int value)
    {
        numerator = value;
    }
    int getDenominator() const
    {
        return denominator;
    }
    void setDenominator(int value)
    {
        denominator = value;
    }

    /// iv.:
    void print() const
    {
        cout << getNumerator() << "/" << getDenominator() << endl;
    }
//    /// alternatywna, bardziej wypasiona wersja:
//    void print(ostream& stream = std::cout) const
//    {
//        stream << getNumerator() << "/" << getDenominator() << endl;
//    }

    /// zadanie 2:
    Fraction operator*(const Fraction& anotherFraction) const
    {
        return Fraction(getNumerator()   * anotherFraction.getNumerator(),
                        getDenominator() * anotherFraction.getDenominator());
    }
    Fraction operator+(const Fraction& anotherFraction) const
    {
        const Fraction fraction1(getNumerator() * anotherFraction.getDenominator(),
                                 getDenominator() * anotherFraction.getDenominator());
        const Fraction fraction2(anotherFraction.getNumerator() * getDenominator(),
                                 anotherFraction.getDenominator() * getDenominator());

        return Fraction(fraction1.getNumerator()   + fraction2.getNumerator(),
                        fraction1.getDenominator() + fraction2.getDenominator());
    }

    std::string toString() const
    {
        return to_string(getNumerator()) + "/" + to_string(getDenominator());
    }

    /// zadanie 3:
    static vector<Fraction> allCreatedFractions;

    void exercise3_addFraction2Vector()
    {
        allCreatedFractions.push_back(*this);
        sort(allCreatedFractions.begin(), allCreatedFractions.end());
    }

    bool operator<(const Fraction& anotherFraction) const
    {
        const double fraction1Value = static_cast<double>(getNumerator())/getDenominator();
        const double fraction2Value = static_cast<double>(anotherFraction.getNumerator())/anotherFraction.getDenominator();
        return fraction1Value < fraction2Value;
    }
};

vector<Fraction> Fraction::allCreatedFractions; // zadanie 3

int main()
{
    Fraction ulamek(3,4);
    ulamek.print();
    Fraction u1(5,4);
    /*for(const auto &i: Fraction.allCreatedFractions)
        cout<*i;*/
    return 0;
}
