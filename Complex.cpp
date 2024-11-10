#include "Complex.h"

Complex::Complex() : Pair()
{
}

Complex::Complex(int a, int b) : Pair(a, b)
{
}

Complex::Complex(const Complex& other) :Pair(other)
{
}


Complex* Complex::multiply(const Complex& other)
{
    cout << *a << '\t' << *(other.b) << '\t' << *b << '\t' << *(other.a) << endl;
    return  new Complex(*a * *(other.a) - *b * *(other.b), *a * *(other.b) + *b * *(other.a));
}

Complex* Complex::divide(const Complex& other)
{
    return new Complex((*a * *(other.a) + *b * *(other.b)) / (*other.a * *other.a + *other.b * *other.b), (*other.a * *b - *a * *other.b) / (*other.a * *other.a + *other.b * *other.b));
}
Complex* Complex::sub(const Pair* other)
{
    return new Complex(*a - *(other->getA()), *b - *(other->getB()));
}

Complex* Complex::sum(const Pair* other)
{
    return new Complex(*a + *(other->getA()), *b + *(other->getB()));
}

Complex* Complex::conj()
{
    return new Complex(*a, -*b);
}

ostream& operator<<(ostream& os, Complex& const tr)
{
    return os << *tr.a << " + " << *tr.b << "i";
    // TODO: insert return statement here
}

Complex::~Complex() {

}