#include <iostream>

class Test
{
private:
	static int s_cid;
	//static int 
public:
	Test() 
	{
		val = -1;
		cid = s_cid++;
		id = cid;
		std::cout << "#" << cid << " Test() created." << std::endl;
	}
	Test(int val) : val(val)
	{
		cid = s_cid++;
		id = cid;
		std::cout << "#" << cid << " Test(" << val << ") created." << std::endl;
	};
	Test(const Test& t)
	{
		cid = s_cid++;
		id = t.id;
		val = t.val;
		std::cout << "#" << cid << " Test(const Test&) called." << std::endl;
	}
	Test(Test&& t)
	{
		cid = s_cid++;
		id = t.id;
		val = t.val;
		std::cout << "#" << cid << " Test(Test&&) called." << std::endl;
	}
	~Test()
	{
		std::cout << "#" << cid << " Test object deleted." << std::endl;
	}
public:
	int cid;
	int id;
	int val;
};
int Test::s_cid = 0;

Test rvoFunc()
{
	return Test();		// rvo test
}

Test rvoFunc2()
{
	Test rtnTest;
	
	return rtnTest;
}

int main()
{
	Test obj1;
	//Test obj2();	// 잘못된 사용. (compiler warning)
	Test obj3(1);

	std::cout << std::endl << "=====case1-1: Test& tr1=====" << std::endl;
	Test& tr1 = rvoFunc();	// ok	//? 이거 안되는거 아닌가..?
	std::cout << "value received." << std::endl;
	std::cout << "val: " << tr1.val << std::endl;
	tr1.val = 10;
	std::cout << "val: " << tr1.val << std::endl;

	std::cout << std::endl << "=====case1-2: Test t1=====" << std::endl;
	Test t1 = rvoFunc();	// ok
	std::cout << "value received." << std::endl;
	std::cout << "val: " << t1.val << std::endl;
	
	std::cout << std::endl << "=====case1-3: const Test& tcr1=====" << std::endl;
	const Test& tcr1 = rvoFunc();	// ok
	std::cout << "value received." << std::endl;
	std::cout << "val: " << tcr1.val << std::endl;
	//tcr1.val = 3;	// error: 식이 수정할 수 있는 lvalue여야 합니다.


	/********* rvoFunc2() Test *********/
	std::cout << std::endl << "=====case2-1: Test& tr2=====" << std::endl;
	Test& tr2 = rvoFunc2();	// ok	//? 이거 안되는거 아닌가..?
	std::cout << "value received." << std::endl;
	std::cout << "val: " << tr2.val << std::endl;
	tr2.val = 10;
	std::cout << "val: " << tr2.val << std::endl;

	std::cout << std::endl << "=====case2-2: Test t2=====" << std::endl;
	Test t2 = rvoFunc2();	// ok. but 바로 deleted
	std::cout << "value received." << std::endl;
	std::cout << "val: " << t2.val << std::endl;

	std::cout << std::endl << "=====case2-3: const Test& tcr2=====" << std::endl;
	const Test& tcr2 = rvoFunc2();	// ok
	std::cout << "value received." << std::endl;
	std::cout << "val: " << tcr2.val << std::endl;
	//tcr1.val = 3;	// error: 식이 수정할 수 있는 lvalue여야 합니다.

	std::cout << std::endl << "=====Program ends=====" << std::endl;

	return 0;
}