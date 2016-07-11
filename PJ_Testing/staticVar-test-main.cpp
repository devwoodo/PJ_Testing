#include "staticVar-test.h"



// case7
class mTest
{
public:
	static mTest _t;
	int _val;
public:
private:
	//mTest();	// default ctor를 private하면 // error LNK1120: 1개의 확인할 수 없는 외부 참조입니다.
};
mTest mTest::_t;

int main()
{
	static int mVar1 = 10;

	printInt(mVar1);

	// case1
	//printMainStaticVar();		// error: LNK2001: "int mVar1" (?mVar1@@3HA) 외부 기호를 확인할 수 없습니다.

	//// case2
	//cout << "hVar1: " << hVar1 << endl;	// error C2065: 'hVar1': 선언되지 않은 식별자입니다.

	// case3
	cout << "hVar2: " << hVar2 << endl;		// ok

	// case4
	//cout << "hVar3: " << hVar3 << endl;	//  error LNK2001: "int hVar3" (?hVar3@@3HA) 외부 기호를 확인할 수 없습니다.

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
