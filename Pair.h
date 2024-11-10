#pragma once
#include <iostream>
using namespace std;

class Pair {
protected:
	int* a, * b;
public:
	Pair();
	Pair(int a, int b);
	Pair(const Pair& other);
	~Pair();
	int* getA() const;
	int* getB() const;
	void setA(int a);
	void setB(int b);
	
	virtual Pair* sum(const Pair* other)=0;
	virtual Pair* sub(const Pair* other)=0;
	Pair& operator=(const Pair& other);

	//умножение убрать, вычитание добавить
	//+ - в указатели
	friend ostream& operator<<(ostream& os, const Pair& tr);
};