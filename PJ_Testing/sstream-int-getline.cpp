#include <iostream>
#include <sstream>

using std::cin;
using std::endl;
using std::cout;

void main()
{
	///////////////////////////////////////////
	// case1
	std::stringstream ss1;
	int i1 = 100;
	int i2 = 200;
	ss1 << i1 << i2;
	int res1;
	ss1 >> res1;
	cout << res1 << endl;
	
	// result
	//	1. stringstream >> int ������ �������� int���� �־����� �� �̸� ���� ����.
	///////////////////////////////////////////



	///////////////////////////////////////////
	// case2
	std::stringstream ss2;
	int i3 = 100;
	ss2 << i3 << '|';
	std::string token1;
	std::getline(ss2, token1, '|');
	cout << token1 << endl;
	// result
	//	1. stringstream�� �Էµ�int�� string ����̵Ǽ� getline + string token���� ���� ����.
	///////////////////////////////////////////
}