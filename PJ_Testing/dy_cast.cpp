#include <iostream>
#include <memory>

class Base
{
public:
	Base() 
	{
		std::cout << "Base()" << std::endl;
	}
public:
	virtual void f() {}
	/*virtual*/ void func()
	{
		std::cout << "Base::func()" << std::endl;
	}
	~Base() 
	{
		std::cout << "~Base()" << std::endl;
	}
};

class Derive : public Base
{
public:
	Derive()
	{
		std::cout << "Derive()" << std::endl;
	}
	virtual void f() {}
	void func()
	{
		std::cout << "Derive::func()" << std::endl;
	}
	~Derive() 
	{
		std::cout << "~Derive()" << std::endl;
	}

	char _dChar;
};


int main()
{
	//Base * btodptr2 = new Derive;
	//btodptr2->func();
	//
	//Derive * p = dynamic_cast<Derive*>(btodptr2);
	//p->func();

	//delete btodptr2;

	//auto sp = std::make_shared<Base>(Derive());		// 런타임 error: 이 expression 끝나자마자 Derive 객체가 해제되버림
	//auto sp = std::make_shared<Base, Derive>(Derive

	auto sp = std::shared_ptr<Base>(new Derive);
	sp->func();
	//sp->_dChar;	// error
	
	auto dy_sp = std::dynamic_pointer_cast<Derive>(sp);
	dy_sp->func();
	std::cout << dy_sp->_dChar << std::endl;

	return 0;
}	