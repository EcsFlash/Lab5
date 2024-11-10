#pragma once
#include "Pair.h"



Pair::Pair(int a, int b) {
	this->a = new int(a);
	this->b = new int(b);
}

Pair::Pair(const Pair& other)
{
	this->a = new int(*other.a);
	this->b = new int(*other.b);
}

Pair::Pair() {
	a = new int(0);
	b = new int(0);
}
Pair::~Pair() {
	delete a;
	delete b;
}

int* Pair::getA() const
{
	return a;
}

int* Pair::getB() const
{
	return b;
}

void Pair::setA(int a)
{
	*(this->a) = a;
}

void Pair::setB(int b)
{
	*(this->b) = b;
}

Pair& Pair::operator=(const Pair& other)
{
	*a = *other.a;
	*b = *other.b;
	return *this;
}

ostream& operator<<(ostream& os, const Pair& tr)
{
	return os << *tr.a << '\t' << *tr.b << endl;
}

