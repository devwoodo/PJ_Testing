#include <vector>
#include <iostream>



//// case1 :test with default data type
//int main()
//{
//	// reserve(..)를 이용하는 경우 push_back() 시 vector size 변동
//	std::vector<int> vec1;
//	vec1.reserve(4);
//	vec1.push_back(0);
//	vec1.push_back(1);
//	vec1.push_back(2);
//	vec1.push_back(3);
//
//	std::cout << "vec1 size: " << vec1.size() << std::endl;
//	std::cout << "vec1 cap: " << vec1.capacity() << std::endl;
//
//	//for (int i = 0; i < 4;)
//	
//	// vector initializer 를 사용하는 경우 push_back() 시 vector size 변동
//	std::vector<int> vec2(4);
//	vec1.push_back(0);
//	vec1.push_back(1);
//	vec1.push_back(2);
//	vec1.push_back(3);
//
//	std::cout << "vec2 size: " << vec2.size() << std::endl;
//	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
//
//
//	return 0;
//}



// case2 :test with class type
//struct Test;	// error

struct Test
{
	int _i;

	Test() : _i(-1)
	{
		std::cout << "Test() called." << std::endl;
	}
	Test(int i) : _i(i)
	{
		std::cout << "Test(int) called." << std::endl;
	}
	~Test()
	{
		std::cout << "~Test() called. _i: " << _i << std::endl;
	}
};
int main()
{
	Test t0(0);
	Test t1(1);
	Test t2(2);
	Test t3(3);

	// reserve(..)를 이용하는 경우 push_back() 시 vector size 변동
	std::cout << "=========================" << std::endl;
	std::vector<Test> vec1;
	vec1.reserve(4);
	vec1.push_back(t0);
	vec1.push_back(t1);
	vec1.push_back(t2);
	vec1.push_back(t3);

	std::cout << "vec1 size: " << vec1.size() << std::endl;
	std::cout << "vec1 cap: " << vec1.capacity() << std::endl;

	// vector constructor 를 사용하는 경우 push_back() 시 vector size 변동
	std::cout << "=========================" << std::endl;
	std::vector<Test> vec2(4);
	std::cout << "=0" << std::endl;
	vec2.push_back(t0);
	std::cout << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
	//std::cout << "vec2[0]._i: " << vec2[0]._i << std::endl;
	std::cout << "=1" << std::endl;
	vec2.push_back(t1);
	std::cout << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
	std::cout << "=2" << std::endl;
	vec2.push_back(t2);
	std::cout << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
	std::cout << "=3" << std::endl;
	vec2.push_back(t3);
	std::cout << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;
	std::cout << "=4" << std::endl;

	std::cout << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec2 cap: " << vec2.capacity() << std::endl;

	// vector initializer 를 사용하는 경우
	std::cout << "=========================" << std::endl;


	return 0;
}

//struct Test
//{
//public:
//	Test()
//	{
//		std::cout << "Test() called." << std::endl;
//	}
//	Test(int i)
//	{
//		std::cout << "Test(int) called." << std::endl;
//	}
//	~Test()
//	{
//		std::cout << "~Test() called." << std::endl;
//	}
//};