#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Test
{
public:
	Test() : uid(s_cid), cid(s_cid), valid(true)
	{
		s_cid++;
		cout << "Test() (uid: " << uid << ", cid: " << cid << ")" << endl;
	}
	Test(Test&& t) : uid(t.uid), cid(s_cid), valid(t.valid)
	{
		s_cid++;
		cout << "Test(&&) (uid: " << uid << ", cid: " << cid << ")" << endl;
	}
	~Test()
	{
		valid = false;
		cout << "~Test() (uid: " << uid << ", cid: " << cid << ")" << endl;
	}

	int uid;
	int cid;
	bool valid;

private:
	static int s_cid;
};
int Test::s_cid = 0;

Test rtnFunc1()
{
	Test t;
	return t;
}

Test rtnFunc2()
{
	return Test();
}

Test rtnFunc3(int ch)
{
	if (ch == 1)
		return Test();
	else
		return Test();
}

Test rtnFunc4(int ch)
{
	Test rtnT;
	
	if (ch == 1)
		return rtnT;
	else
		return rtnT;
}

Test& rtnRefFunc1()	// warning C4172: ���� ���� �Ǵ� �ӽ�: t�� �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�.
{
	Test t;

	return t;
}

Test& rtnRefFunc2()		// warning C4172: ���� ���� �Ǵ� �ӽ�: t�� �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�.
{
	return Test();
}

int main()
{
	// case1: RVO test. (�Լ� ���� �� ����/���Ϲ����� ����)
	cout << "====== case1 ======" << endl;
	Test mt1 = rtnFunc1();
	Test mt2 = rtnFunc2();

	// case2: RVO�� ref�� �ޱ�
	cout << endl << "====== case2 ======" << endl;
	Test mrt1 = rtnFunc1();
	cout << mrt1.valid << endl;

	// case3: if��
	cout << endl << "====== case3 ======" << endl;
	Test mt3 = rtnFunc3(3);		// RVO �۵�.

	// case4: if��2
	cout << endl << "====== case4 ======" << endl;
	Test mt4 = rtnFunc4(2);		// RVO �۵� X
	
	// case5: ref �����ϴ� func.
	cout << endl << "====== case5 ======" << endl;
	Test& mrt2 = rtnRefFunc1();
	cout << mrt2.valid << endl;		// output: 0(invalid)

	cout << endl << "Program ends." << endl;

	return 0;
}