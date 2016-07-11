#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;


typedef class Super
{
public:
	Super() : uid(s_cid), cid(s_cid), valid(true)
	{
		s_cid++;
		cout << "Super() (uid: " << uid << ", cid: " << cid << ")" << endl;
	}
	Super(const Super& src) : uid(src.uid), cid(s_cid), valid(src.valid)
	{
		s_cid++;
		cout << "Super(const Super&) (uid: " << uid << ", cid: " << cid << ")" << endl;
	}
	Super(Super&& t) : uid(t.uid), cid(s_cid), valid(t.valid)
	{
		s_cid++;
		cout << "Super(&&) (uid: " << uid << ", cid: " << cid << ")" << endl;
	}
	~Super()
	{
		valid = false;
		cout << "~Super() (uid: " << uid << ", cid: " << cid << ")" << endl;
	}

	int uid;
	int cid;
	bool valid;

private:
	static int s_cid;
} *PSuper;
int Super::s_cid = 0;

Super& func1()	// X
{

	return Super();
}

Super&& func2()	// X
{

	return Super();
}

Super& func3()	// X
{
	return *(std::make_shared<Super>());
}

std::shared_ptr<Super> func4()
{
	return std::make_shared<Super>();
}

Super& func5()	// X
{
	return *(std::make_shared<Super>().get());
}

Super func6()
{
	return *(std::make_shared<Super>().get());
}


//template <class t>
//typedef std::shared_ptr<t> *pshd;
//typedef *pshr std::shared_ptr<t>;

typedef std::shared_ptr<Super> SupShr;
typedef std::shared_ptr<Super> * pSupShr;
typedef int myint;

int main()
{
	//std::shared_ptr<Super> sp1 = new Super();	// error
	auto sp1 = std::shared_ptr<Super>(new Super);
	//std::shared_ptr<Super> sp2;				// error
	std::shared_ptr<Super> sp2(new Super);
	std::shared_ptr<Super> sp3 = std::shared_ptr<Super>(new Super);
	auto sp4 = std::make_shared<Super>();

	//
	cout << endl << "case1: func1()" << endl;
	Super& s1 = func1();
	cout << s1.valid << endl;

	//
	cout << endl << "case2: func2()" << endl;
	Super& s2 = func2();
	cout << s2.valid << endl;

	//
	cout << endl << "case3: func3()" << endl;
	Super& s3 = func3();
	cout << s3.valid << endl;

	//
	cout << endl << "case4: func4()" << endl;
	auto s4 = func4();
	cout << s4->valid << endl;

	//
	cout << endl << "case5" << endl;
	Super * ps1 = s4.get();
	PSuper ps2 = s4.get();
	cout << ps2->valid << endl;

	//
	cout << endl << "case6: func5()" << endl;
	Super& rs1 = func5();
	cout << rs1.valid << endl;

	//
	cout << endl << "case7: func6()" << endl;
	Super& rs2 = func6();
	cout << rs2.valid << endl;
	Super rs3 = func6();
	cout << rs3.valid << endl;

	cout << "Program ends." << endl;
	return 0;
}