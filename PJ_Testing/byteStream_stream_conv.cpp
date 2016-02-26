#include <iostream>
#include <sstream>


// case2
int main()
{
	// char arr -> stream
	std::stringstream sstrm;
	
	char cbuf1[] = "Piece1";
	char cbuf2[] = "Piece2";
	char cbuf3[] = "Piece3";

	sstrm << cbuf1 << '|' << cbuf2 << '|' << cbuf3;

	std::cout << sstrm.str() << std::endl;

	//std::string str;
	char cbuf[10];

	//sstrm.get(str, '|');	// error

	while (sstrm.get(cbuf, 3, '|'))		// sstrm���� delim�� �ձ��� one character �� �̾Ƴ��� ����Լ�
		std::cout << cbuf << ' ';
	std::cout << std::endl;

	sstrm.clear();		// ������ get(..) �Լ� ��� sstrm�� eof bit �� set��.
	sstrm.ignore(1);	// ������ get(..) �Լ��� | �ձ��� ���� ���¶� ��Ʈ���� ���� |�� �����־� �̸� ��������.
	while (sstrm.getline(cbuf, 10, '|'))
		std::cout << cbuf << ' ';	
	std::cout << std::endl;

	std::stringstream sstrm2;
	char * cbuf4 = "char pointer";
	char buffer[20];

	// stream -> byte stream(char array)
	sstrm2 << cbuf4;
	std::cout << "char pointer : " << cbuf4 << std::endl;	// ���: char pointer
	std::cout << "sstrm2 : " << sstrm2.str() << std::endl;	// ���: char pointer	
	sstrm2.read(buffer, 6);
	buffer[6] = '\0';
	std::cout << "buffer : " << buffer << std::endl;		// ���: char p
	std::cout << "sstrm2 : " << sstrm2.str() << std::endl;	// ���: char pointer
	std::cout << "rdbuf() : " << sstrm2.rdbuf() << std::endl;	// ���: ointer
	std::cout << std::endl;

	return 0;
}


//// case1
//int main()
//{
//	std::stringstream sstrm;
//
//	char cbuf[] = "Hello World!|Good to see you!";
//
//	sstrm << cbuf;
//
//	std::cout << "cbuf: " << cbuf << std::endl;
//	std::cout << "sstrm: " << sstrm.str() << std::endl;
//
//	return 0;
//}