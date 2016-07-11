#include "staticVar-test.h"



void printInt(int val)
{
	cout << "printInt(..): " << val << endl;

	return;
}

//// case1
//extern int mVar1;
//void printMainStaticVar()		// error: LNK2001: "int mVar1" (?mVar1@@3HA) 외부 기호를 확인할 수 없습니다.
//{
//	cout << "printStaticVar(): " << mVar1 << endl;
//	return;
//}

//// case2
//static int hVar1 = 10;

//// case3


//// case4
//void initHeadStaticVar()
//{
//	static int hVar3 = 10;
//}

// case5
void printhVar4()
{
	cout << "hVar4: " << hVar4 << endl;
}

// case6
//Test Test::_t;