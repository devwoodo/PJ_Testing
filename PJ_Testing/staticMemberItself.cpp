#include <iostream>

class Test
{
	virtual void foo() {};
};

class DerivedTest : public Test
{
public:
	static const DerivedTest _NullObject;

	int _val;
public:
	DerivedTest() : _val(-1)
	{}
	DerivedTest(int val) : _val(val)
	{}

	virtual void foo() {};
};
//const DerivedTest DerivedTest::_NullObject = DerivedTest(1);	// ok. _val: 1
//const DerivedTest DerivedTest::_NullObject;		// ok. _val: -1
const DerivedTest DerivedTest::_NullObject(10);	// ok. _val: 10

class DDerivedTest : public DerivedTest
{
public:
	DDerivedTest() : DerivedTest(), tRef(DerivedTest::_NullObject) {}
	DDerivedTest(DDerivedTest& ddTest) : DerivedTest(), tRef(ddTest) {}

public:
	const DerivedTest& tRef;
};


int main()
{
	const DerivedTest& nullT = DerivedTest::_NullObject;
	
	// case1
	// DerivedTest::_NullObject test
	std::cout << "DerivedTest::_NullObject test" << std::endl;
	std::cout << "DerivedTest::_NullObject._val: " << DerivedTest::_NullObject._val << std::endl;
	std::cout << "nullT._val: " << nullT._val << std::endl;

	// case2
	// DerivedTest::_NullObject address test
	std::cout << std::endl << "DerivedTest::_NullObject address test" << std::endl;
	DerivedTest t1(10);
	std::cout << "Address of DerivedTest::_NullObject: " << &DerivedTest::_NullObject << std::endl;
	std::cout << "Address of Test t1: " << &t1 << std::endl;
	std::cout << "Address of nullT: " << &nullT << std::endl;

	// case3
	// DerivedTest::_NullObject inheritancy test 1
	std::cout << std::endl << "DerivedTest::_NullObject inheritancy test 1" << std::endl;
	const Test& t2 = DerivedTest::_NullObject;
	std::cout << "t2._val: " << (dynamic_cast<const DerivedTest&>(t2))._val << std::endl;
	std::cout << "Address of Test& t2: " << &t2 << std::endl;

	// case4
	// DerivedTest::_NullObject inheritancy test 2
	std::cout << std::endl << "DerivedTest::_NullObject inheritancy test 2" << std::endl;
	DDerivedTest ddT1;
	std::cout << "ddT1.tRef._val: " << ddT1.tRef._val << std::endl;
	std::cout << "ddT1._val: " << ddT1._val << std::endl;

	return 0;
}