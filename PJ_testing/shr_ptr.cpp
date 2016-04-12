#include <iostream>
#include <utility>
#include <memory>

class First
{
public:
public:
	virtual void func()
	{
		std::cout << "First func() called." << std::endl;
	}
};

class Second : public First
{
public:
public:
	virtual void func()
	{
		std::cout << "Second func() called." << std::endl;
	}
};

// 아래 함수는 shared ptr을 매개변수로 받을 수 없음.
// shared ptr의 polymorphism 적용도 당연히 불가능
void callFunc(First * tar)		
{
	tar->func();
}

// 아래 함수는 shared ptr을 매개변수로 받을 수 있음.
// shared ptr의 polymorphism 적용도 가능!! 
//	(shared_ptr<Second> 를 매개변수로 받을 수 있음)
void callFuncShr(std::shared_ptr<First> shr)
{
	shr->func();
}

int main()
{
	auto spf1 = std::make_shared<First>();
	auto ps1 = new Second();

	spf1->func();
	callFunc(ps1);
	//callFunc(spf1);	// error 매개변수로 shared ptr 받을 수 없음

	std::cout << "-------------" << std::endl;
	callFuncShr(spf1);
	auto sps1 = std::make_shared<Second>();
	callFuncShr(sps1);

	return 0;
}