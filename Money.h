#pragma once
#include "Pair.h"

class Money : public Pair {
	void normalize();
public:
	Money();
	Money(int a, int b);
	Money(const Money& other);

	Money* sum(const Pair* other) override;
	Money* sub(const Pair* other) override;
	Money* multiply(int skolko);
	Money* divide(int skolko);

	friend ostream& operator<<(ostream& os, Money& const tr);

	~Money();
};