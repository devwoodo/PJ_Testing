#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Test
{
	static int _cNum;
public:
	int _cid;
	int _uid;
	std::string _str;

public:
	Test()
	{
		_uid = _cid = _cNum++;
		cout << "Test() called. (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;
	}
	Test(const std::string& str)
	{
		_uid = _cid = _cNum++;
		_str = str;

		cout << "Test(const string&) called. (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl; 
	}
	Test(const Test& t)
	{
		_cid = _cNum++;
		_uid = t._uid;
		_str = t._str;
		cout << "Test(const Test&) called. (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;
	}
	Test(Test&& t)
	{
		_cid = _cNum++;
		_uid = t._uid;
		std::swap(_str, t._str);
		cout << "Test(Test&&) called. (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;

		//t.~Test();	//? explicitly destructor calling �� �ʿ��Ѱ�?
	}
	//// operator=(Test&&) �� ����� �ߺ� ������ move constructor
	//Test(Test&& _t)
	//{
	//	_cid = _cNum++;
	//	*this = std::move(_t);		//rev �³�?
	//	//_t.~Test;		//? explicitly destructor calling �� �ʿ��Ѱ�?
	//
	//	cout << "Test(Test&&) called on Test object(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;
	//}

	//Test& operator= (Test t)
	//{
	//	cout << "operator=(Test) called by (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << "). ";
	//	_uid = t._uid;
	//	_str = t._str;
	//	cout << "result(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;
	//
	//	return *this;
	//}
	Test& operator= (Test& t)
	{
		cout << "operator=(Test&) called by (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << "). ";
		_uid = t._uid;
		_str = t._str;
		cout << "result(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;

		return *this;
	}
	Test& operator= (const Test& t)
	{
		cout << "operator=(const Test&) called by (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << "). ";
		_uid = t._uid;
		_str = t._str;
		cout << "result(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;

		return *this;
	}
	Test& operator= (Test&& t)
	{
		if (this != &t)
		{
			cout << "operator=(const Test&) called by (cid: " << _cid << ", uid: " << _uid << ", str: " << _str << "). ";
			// t resource �Ҵ� ����
			// t._str.clear();	//? �� ���� ������ �ٲ� obj�� string�� ���� �ƴϴ� destructor�� �ȺҸ���?
			_uid = t._uid;
			std::swap(_str, t._str);
			cout << "result(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ")" << endl;
		}

		return *this;
	}
	~Test()
	{
		cout << "~Test(cid: " << _cid << ", uid: " << _uid << ", str: " << _str << ") deleted." << endl;
	}
};
int Test::_cNum = 0;
Test gt("gt");

std::ostream& operator<<(std::ostream& os, const Test& t)
{
	os << "Test " << t._str << "(cid: " << t._cid << ", uid : " << t._uid << ", str : " << t._str << ")" << endl;
	return os;
}

void func1(Test t)
{
	cout << "func1(Test) called." << endl;
	//t.~Test();
	cout << t;
	cout << "func1(Test) return." << endl;
	return;
}
void func1b(Test t)
{
	cout << "func1b(Test) called." << endl;
	//t.~Test();
	gt = t;
	cout << t;
	cout << "func1b(Test) return." << endl;
	return;
}

void func2(Test&& t)
{
	cout << "func2(Test&&) called." << endl;
	cout << t;
	cout << "func2(Test&&) return." << endl;
	return;
}

void func2b(Test&& t)
{
	cout << "func2b(Test&&) called." << endl;
	cout << t;
	gt = t;
	cout << "func2b(Test&&) return." << endl;
	return;
}


//// case 1
//int main()
//{
//	cout << "Program starts." << endl;
//	Test t0;
//	Test t1("t1");
//	Test t2("t2");
//
//	t0 = std::move(t1);
//	Test t3(std::move(t2));
//	
//	cout << "Program ends." << endl;
//
//	return 0;
//}
//// move constructor �� move assignment operator �� �θ� �� �̵��� object�� ������ ��Ÿ���� ����.


//// case 2
//int main()
//{
//	cout << "Program starts." << endl;
//
//	//std::vector<Test> tvec(5);		// reserve()�� �ٸ�. Test object�� Test() �� 10�� ������ vector�� ����.
//	std::vector<Test> tvec;
//	tvec.reserve(5);
//
//	tvec.push_back(Test("t1"));		// 1
//	tvec.push_back(Test("t2"));		// 2
//
//	Test t3("t3");
//	tvec.push_back(std::move(t3));	// 3
//
//	cout << "Program ends." << endl;
//
//	return 0;
//}
//// move constructor �� move assignment operator �� �θ� �� �̵��� object�� ������ ��������� �������� �ʾ������� 
////	vector�� push_back() ���� �� �̵��� object�� �ڵ����� ���� �Ǵ� ���� Ȯ��. 
////? �̵��� object�� push_back()�� �����ִ°� �ƴұ�..?
////	-> no. 1, 2���� �ڵ����� ����������, 3������ ���� ����. �̴� 1, 2������ �ӽ� ��ü�� ������ move constructor�� �ҷ��� �� 
////	�ӽ� ��ü�� out of scope�� �����Ǳ� ����. push_back(..)�̳� move constructor�� ���� ������ ���� ���� �ƴ�.


// case 3
int main()
{
	cout << "Program starts." << endl;
	
	Test t0("f1_1");
	Test t1("f2_1");	cout << endl;

	func1(t0); cout << endl;	// 1 error "func1(const Test&) (�Ͻ������� �����) �� ������ �������ϴ�. ������ �Լ��Դϴ�."
	func1(std::move(t0)); cout << endl;	// 2
	func1(Test("f1_2")); cout << endl;	// 3
	func1b(Test("f1_3")); cout << endl; // 3b

	//func2(t1);	// 4 error "rvalue ������ lvalue�� ���ε��� �� �����ϴ�."
	func2(std::move(t1)); cout << endl;	// 5
	func2(Test("f2_2")); cout << endl;	// 6
	func2b(Test("f2_3")); cout << endl; // 6b

	cout << "Program ends." << endl;

	return 0;
}
//? move semantic �� ����� class �� �Լ��� param.�� ���� ��� �� �Լ����� �̵��� object�� ��������� �������� �ʾƵ� �ڵ����� �����ɱ�?
//? func1�� move semantic�� ��������� ���ǵ��� ���� �Լ��ε� move semantic �� ����ɱ�?
// 
// func1(Test)�� move semantic�� ��������� �������� �ʾ������� param.�� momve semantic�� �����. �׷��� �̵��� obj�� �ڵ����� ���������� ����.
// func2(Test&&)�� Ư���ѵ�, �Լ��� move semantic�� ��������� �����ϰ� rvalue�� �Ѱ����� Test(Test&&)������ �������� �ʰ� param.�� �ٷ� �Ѿ.



//// case 
//int main()
//{
//	cout << "Program starts." << endl;
//
//	cout << "Program ends." << endl;
//
//	return 0;
//}