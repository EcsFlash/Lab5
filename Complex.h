#pragma once
#include "Pair.h"

class Complex : public Pair {
public:
	Complex();
	Complex(int a, int b);
	Complex(const Complex& other);

	Complex* multiply(const Complex& other);
	Complex* divide(const Complex& other);
	Complex* sum(const Pair* other) override;
	Complex* sub(const Pair* other) override;
	Complex* conj();

	friend ostream& operator<<(ostream& os, Complex& const tr);
	
	~Complex();
};