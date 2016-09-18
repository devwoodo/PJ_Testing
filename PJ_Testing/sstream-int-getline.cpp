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
	//	1. stringstream >> int 연산은 연속으로 int값이 넣어졌을 때 이를 구분 못함.
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
	//	1. stringstream에 입력된int는 string 취급이되서 getline + string token으로 추출 가능.
	///////////////////////////////////////////
}