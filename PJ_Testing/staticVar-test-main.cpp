#include "staticVar-test.h"



// case7
class mTest
{
public:
	static mTest _t;
	int _val;
public:
private:
	//mTest();	// default ctor�� private�ϸ� // error LNK1120: 1���� Ȯ���� �� ���� �ܺ� �����Դϴ�.
};
mTest mTest::_t;

int main()
{
	static int mVar1 = 10;

	printInt(mVar1);

	// case1
	//printMainStaticVar();		// error: LNK2001: "int mVar1" (?mVar1@@3HA) �ܺ� ��ȣ�� Ȯ���� �� �����ϴ�.

	//// case2
	//cout << "hVar1: " << hVar1 << endl;	// error C2065: 'hVar1': ������� ���� �ĺ����Դϴ�.

	// case3
	cout << "hVar2: " << hVar2 << endl;		// ok

	// case4
	//cout << "hVar3: " << hVar3 << endl;	//  error LNK2001: "int hVar3" (?hVar3@@3HA) �ܺ� ��ȣ�� Ȯ���� �� �����ϴ�.

	// case5
	printhVar4();
	hVar4 = 14;
	cout << "main hVar4: " << hVar4 << endl;

	// case6
	cout << "Test::_t::_val: " << Test::_t._val << endl;

	// case7
	cout << "mTest::_t::_val: " << mTest::_t._val << endl;



	return 0;
}
