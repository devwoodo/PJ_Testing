#include <iostream>
#include <memory>	

using std::cin;
using std::cout;
using std::endl;

class Test
{
public:
	Test() : val(-1) {};
	Test(int i) : val(i) {};
	~Test() {};

	void Foo() { cout << val << endl; }

	int val;
};

void Foo2(std::shared_ptr<Test> sh)
{
	if (sh == nullptr)
		cout << "Foo2(nullptr)" << endl;
	else
		cout << "Foo2(shared_ptr)" << endl;
}

void main()
{
	///////////////////////////////////////////////////////////////////////////////
	// case1
	cout << endl << "Case 1 >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	auto sh1 = std::shared_ptr<Test>();		// nullptr
	//auto sh1 = std::shared_ptr<Test>(10);		// error
	auto sh2 = std::shared_ptr<Test>(new Test(10));	//
	auto null1 = std::shared_ptr<Test>(nullptr);	// nullptr

	//sh1->Foo();	// error
	sh2->Foo();
	//null1->Foo();	// error
	if (sh1 == nullptr)
		cout << "sh1 is nullptr" << endl;
	if (null1 == nullptr)
		cout << "null1 is nullptr" << endl;
	
	

	///////////////////////////////////////////////////////////////////////////////
	// case2
	cout << endl << "Case 2 >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	//auto msh1 = std::make_shared(Test());	// error
	auto msh1 = std::make_shared<Test>();
	auto msh2 = std::make_shared<Test>(10);
	//auto n_msh1 = std::make_shared<Test>(nullptr);	// error in compile.
	//auto n_msh2 = std::make_shared<Test>(nullptr_t);	// error
	auto n_msh3 = std::make_shared<nullptr_t>();

	msh1->Foo();
	msh2->Foo();
	//n_msh1->Foo();
	Foo2(msh1);
	//Foo2(n_msh3);	// error: 사용자 변환이 적절치 않습니다

	cout << "Program end line." << endl;
}