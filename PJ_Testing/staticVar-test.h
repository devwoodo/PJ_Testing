#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;



void printInt(int val);

//// case1 : static mVar1�� main file���� ����, ����. �̸� header file���� call.
//void printMainStaticVar();	
//// error: LNK2001: "int mVar1" (?mVar1@@3HA) �ܺ� ��ȣ�� Ȯ���� �� �����ϴ�.

// case2 : static hVar1�� header implement file���� ����, ����.
//// error C2065 : 'hVar1' : ������� ���� �ĺ����Դϴ�.

// case3 : static hVar2�� header file���� ����, ����.
static int hVar2 = 10;
// ok

//// case4 : static hVar3�� header file�� ����� �Լ��� ����, implement file�� ����, ����. �̸� main���� call.
//extern int hVar3;
//void initHeadStaticVar();
//// error LNK2001: "int hVar3" (?hVar3@@3HA) �ܺ� ��ȣ�� Ȯ���� �� �����ϴ�.

// case5 : static hVar4�� header file�� ����, ����. implement file���� call.
static int hVar4 = 10;
void printhVar4();
// ok

// case6 : header�� class ����. class static var �θ��� ���
class Test
{
public:
	static Test _t;
	int _val;
public:
};

// case7 : main�� class ����, ����. class static var �θ��� ���