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

// �Ʒ� �Լ��� shared ptr�� �Ű������� ���� �� ����.
// shared ptr�� polymorphism ���뵵 �翬�� �Ұ���
void callFunc(First * tar)		
{
	tar->func();
}

// �Ʒ� �Լ��� shared ptr�� �Ű������� ���� �� ����.
// shared ptr�� polymorphism ���뵵 ����!! 
//	(shared_ptr<Second> �� �Ű������� ���� �� ����)
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
	//callFunc(spf1);	// error �Ű������� shared ptr ���� �� ����

	std::cout << "-------------" << std::endl;
	callFuncShr(spf1);
	auto sps1 = std::make_shared<Second>();
	callFuncShr(sps1);

	return 0;
}