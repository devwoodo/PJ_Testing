#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main()
{
	std::string str_orig("string yes!");
	std::string str_dest;

	cout << "str_orig: " << str_orig << endl;
	cout << "str_dest: " << str_dest << endl;

	std::swap(str_orig, str_dest);

	cout << "str_orig: " << str_orig << endl;
	cout << "str_dest: " << str_dest << endl;

	str_dest.clear();

	cout << "str_orig: " << str_orig << endl;
	cout << "str_dest: " << str_dest << endl;

	return 0;
}