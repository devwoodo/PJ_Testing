#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;



void printInt(int val);

//// case1 : static mVar1은 main file에서 선언, 정의. 이를 header file에서 call.
//void printMainStaticVar();	
//// error: LNK2001: "int mVar1" (?mVar1@@3HA) 외부 기호를 확인할 수 없습니다.

// case2 : static hVar1은 header implement file에만 선언, 정의.
//// error C2065 : 'hVar1' : 선언되지 않은 식별자입니다.

// case3 : static hVar2는 header file에만 선언, 정의.
static int hVar2 = 10;
// ok

//// case4 : static hVar3는 header file에 선언된 함수에 포함, implement file에 선언, 정의. 이를 main에서 call.
//extern int hVar3;
//void initHeadStaticVar();
//// error LNK2001: "int hVar3" (?hVar3@@3HA) 외부 기호를 확인할 수 없습니다.

// case5 : static hVar4는 header file에 선언, 정의. implement file에서 call.
static int hVar4 = 10;
void printhVar4();
// ok

// case6 : header에 class 선언. class static var 부르는 경우
class Test
{
public:
	static Test _t;
	int _val;
public:
};

// case7 : main에 class 선언, 정의. class static var 부르는 경우