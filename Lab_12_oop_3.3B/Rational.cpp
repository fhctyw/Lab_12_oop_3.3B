#include "Rational.h"
#include <iostream>
#include <sstream>

Rational::Rational(const Rational& r)
{
    *this = r;
}

Rational& Rational::operator=(const Rational& r)
{
    setPair(r);
    return *this;
}

Rational::operator string() const
{
    stringstream ss;
    ss << getA() << '/' << getB();
    return ss.str();
}

void Rational::Reduce()
{
    int i, a = getA(), b = getB();
    do {
        for (i = abs(std::min(a, b)); i > 0; i--)
        {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                break;
            }
        }
    } while (i != 1);
    setA(a); setB(b);
}

ostream& operator<<(ostream& out, const Rational& r)
{
    out << (string)r;
    return out;
}

istream& operator>>(istream& in, Rational& r)
{
    int a, b;
    cout << "���������: "; cin >> a;
    cout << "���������: "; cin >> b;
    r.setA(a); r.setB(b);
    return in;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational r(r1.getA() * r2.getB(), r2.getA() * r1.getB());
    r.Reduce();
    return r;
}

bool operator==(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.getA() == r22.getA() && r11.getB() == r22.getB();
}

bool operator<(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.value() < r22.value();
}

bool operator>(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.value() > r22.value();
}
