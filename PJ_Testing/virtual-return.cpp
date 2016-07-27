#include <iostream>

class Base
{
public:
	virtual Base * getThis()
	{
		std::cout << "Base * getThis()" << std::endl;
		return this;
	}
	void print()
	{
		std::cout << "This is Base." << std::endl;
	}
};

class Derived1 : public Base
{
public:
	Derived1 * getThis()
	{
		std::cout << std::endl << "Derived1 * getThis()" << std::endl;
		return this;
	}
	void print()
	{
		std::cout << "This is Derived1." << std::endl;
	}
};

class Derived2 : public Base
{
public:
	Derived2 * getThis()
	{
		std::cout << "Derived2 * getThis()" << std::endl;
		return this;
	}
	void print()
	{
		std::cout << "This is Derived2." << std::endl;
	}
};

int main()
{
	Base * pbOb1 = new Base;
	Base * pbOd1 = new Derived1;

	pbOb1->print();
	pbOd1->print();

	dynamic_cast<Derived1*>(pbOd1)->print();
	(pbOd1->getThis())->print();	// Derived1 * getThis() 실행되긴 하지만 리턴 타입은 Base * 로 출력.

	delete pbOb1;
	delete pbOd1;

	return 0;
}