#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::stringstream ss1;
	std::stringstream ss2;

	char * buf1 = "20|hello1";
	char buf2[9] = { '2', '0', '|', 'h', 'e', 'l', 'l', 'o','2' };

	cout << "=== case1 ===" << endl;
	cout << buf1[9] << endl;
	cout << buf2[8] << endl;
	
	cout << endl << "=== case2 ===" << endl;
	ss1 << buf1 << endl;
	ss2 << buf2 << endl;

	cout << ss1.str() << endl;
	cout << ss2.str() << endl;

	cout << endl << "=== case3 ===" << endl;
	std::stringstream ss3;
	ss3.write(buf2, 9);
	cout << ss3.str() << endl;

	return 0;
}