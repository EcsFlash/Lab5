#include "Money.h"

void Money::normalize()
{
    int part = *b / 100;
    *a += part;
    *b = *b % 100;
    if (*b < 0) {
        *b = 100 - *b;
        *a -= 1;
   }
}

Money::Money() : Pair()
{
}

Money::Money(int a, int b) : Pair(a, b)
{
}

Money::Money(const Money& other) :Pair(other)
{
}


Money* Money::sum(const Pair* other)
{
    Money* temp = new Money(*a + *other->getA(), *b + *other->getB());
    temp->normalize();
    cout << *temp << endl;
    return temp;
}

Money* Money::sub(const Pair* other)
{
    Money* temp = new Money(*a - *other->getA(),*b - *other->getB());
    temp->normalize();
    return temp;
}

Money* Money::multiply(int skolko)
{
    Money* temp = new Money(*a * skolko, *b * skolko);
    temp->normalize();
    return temp;
}
Money* Money::divide(int skolko)
{
    Money* temp = new Money(*a / skolko, *b / skolko);
    temp->normalize();
    return temp;
}
Money::~Money()
{
}
ostream& operator<<(ostream& os, Money& const tr)
{
    return os << *tr.a << "rub " << *tr.b << "copeek";
    
}
