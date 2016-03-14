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

		//t.~Test();	//? explicitly destructor calling 이 필요한가?
	}
	//// operator=(Test&&) 형 사용해 중복 제거한 move constructor
	//Test(Test&& _t)
	//{
	//	_cid = _cNum++;
	//	*this = std::move(_t);		//rev 맞나?
	//	//_t.~Test;		//? explicitly destructor calling 이 필요한가?
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
			// t resource 할당 해제
			// t._str.clear();	//? 이 구문 없으면 바뀐 obj의 string이 빈값이 아니니 destructor가 안불릴까?
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
//// move constructor 나 move assignment operator 를 부른 후 이동된 object의 해제가 나타나지 않음.


//// case 2
//int main()
//{
//	cout << "Program starts." << endl;
//
//	//std::vector<Test> tvec(5);		// reserve()와 다름. Test object를 Test() 로 10개 생성해 vector에 저장.
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
//// move constructor 나 move assignment operator 를 부른 후 이동된 object의 해제를 명시적으로 지정하지 않았음에도 
////	vector의 push_back() 연산 시 이동된 object가 자동으로 해제 되는 것을 확인. 
////? 이동된 object는 push_back()이 지워주는게 아닐까..?
////	-> no. 1, 2에선 자동으로 해제되지만, 3에서는 해제 없음. 이는 1, 2에서는 임시 객체가 생성돼 move constructor를 불러온 후 
////	임시 객체가 out of scope로 해제되기 때문. push_back(..)이나 move constructor에 해제 과정이 들어가는 것이 아님.


// case 3
int main()
{
	cout << "Program starts." << endl;
	
	Test t0("f1_1");
	Test t1("f2_1");	cout << endl;

	func1(t0); cout << endl;	// 1 error "func1(const Test&) (암시적으로 선언됨) 을 참조할 수없습니다. 삭제된 함수입니다."
	func1(std::move(t0)); cout << endl;	// 2
	func1(Test("f1_2")); cout << endl;	// 3
	func1b(Test("f1_3")); cout << endl; // 3b

	//func2(t1);	// 4 error "rvalue 참조를 lvalue에 바인딩할 수 없습니다."
	func2(std::move(t1)); cout << endl;	// 5
	func2(Test("f2_2")); cout << endl;	// 6
	func2b(Test("f2_3")); cout << endl; // 6b

	cout << "Program ends." << endl;

	return 0;
}
//? move semantic 이 적용된 class 가 함수에 param.로 들어가는 경우 기 함수에서 이동된 object를 명시적으로 해제하지 않아도 자동으로 해제될까?
//? func1은 move semantic이 명시적으로 정의되지 않은 함수인데 move semantic 이 적용될까?
// 
// func1(Test)에 move semantic을 명시적으로 정의하지 않았음에도 param.에 momve semantic이 적용됨. 그러나 이동된 obj가 자동으로 해제되지는 않음.
// func2(Test&&)는 특이한데, 함수에 move semantic을 명시적으로 정의하고 rvalue를 넘겨주자 Test(Test&&)조차도 생성되지 않고 param.가 바로 넘어감.



//// case 
//int main()
//{
//	cout << "Program starts." << endl;
//
//	cout << "Program ends." << endl;
//
//	return 0;
//}