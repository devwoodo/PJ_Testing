#include <iostream>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

// std::stringstream::get(char)�� char�� ����ϴ� wrapping �Լ�
char getMyChar(std::stringstream& ss); 

/*********************************************************************
 * structure of stream buffer
	position:		0123456789		// position count�� 0���� ����.
	buffer ����:	asdfqwerzx
 *********************************************************************/

int main()
{
	// tellg() VS tellp()
	cout << "// tellg() VS tellp()" << endl;
	std::stringstream ss1;
	ss1 << "asdfqwerzx";
	cout << "ss1: " << ss1.str() << endl;
	cout << "tellg(): " << ss1.tellg() << endl;	// output: 0
	cout << "tellp(): " << ss1.tellp() << endl;	// output: 10

	cout << "get() 3 times: ";
	for (int i = 0; i < 3; ++i)
		cout << getMyChar(ss1);
	cout << endl;

	cout << "tellg(): " << ss1.tellg() << endl;	// output: 3
	cout << "tellp(): " << ss1.tellp() << endl;	// output: 10


	// seekg() VS seekp()
	cout << endl << "// seekg() VS seekp()" << endl;
	std::stringstream ss2;
	ss2 << "asdfqwerzx";
	cout << "ss2: " << ss2.str() << endl;	// output: d
	ss2.seekg(2);
	cout << "after seekg(2): " << getMyChar(ss2) << endl;

	ss2.seekp(0, std::ios_base::beg);	// �־��� dir ���� ss2.beg �� ����
	ss2 << '*';
	cout << "after seekp(0, io_base::beg): " << ss2.str() << endl;	// output: *sdfqwerzx
	
	ss2.seekp(0, ss2.end);
	ss2 << '*';
	cout << "after seekp(0, ss2.end): " << ss2.str() << endl;	// output: *sdfqwerzx*

	return 0;
}


char getMyChar(std::stringstream& ss)
{
	char c;
	ss.get(c);

	return c;
}