#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string charTConv(const std::wstring&);
std::wstring charTConv(const std::string&);

int main()
{
	std::string str1 = "asdf";
	std::wstring wstr1 = charTConv(str1);
	
	cout << "str1: " << str1 << endl;
	std::wcout << "wstr1: " << wstr1 << endl;

	//std::wstring wstr2 = "1234";	//error
	std::wstring wstr2 = L"1234";
	std::string str2 = charTConv(wstr2);
	std::wcout << "wstr2: " << wstr2 << endl;
	cout << "str2: " << str2 << endl;

	return 0;
}

std::string charTConv(const std::wstring & wstr)
{
	return std::string(wstr.cbegin(), wstr.cend());
}

std::wstring charTConv(const std::string &str)
{
	return std::wstring(str.cbegin(), str.cend());
}
