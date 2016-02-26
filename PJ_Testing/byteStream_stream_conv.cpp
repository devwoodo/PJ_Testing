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

	while (sstrm.get(cbuf, 3, '|'))		// sstrm에서 delim의 앞까지 one character 씩 뽑아내는 멤버함수
		std::cout << cbuf << ' ';
	std::cout << std::endl;

	sstrm.clear();		// 위에서 get(..) 함수 결과 sstrm에 eof bit 이 set됨.
	sstrm.ignore(1);	// 위에서 get(..) 함수가 | 앞까지 읽은 상태라 스트림에 아직 |가 남아있어 이를 제거해줌.
	while (sstrm.getline(cbuf, 10, '|'))
		std::cout << cbuf << ' ';	
	std::cout << std::endl;

	std::stringstream sstrm2;
	char * cbuf4 = "char pointer";
	char buffer[20];

	// stream -> byte stream(char array)
	sstrm2 << cbuf4;
	std::cout << "char pointer : " << cbuf4 << std::endl;	// 출력: char pointer
	std::cout << "sstrm2 : " << sstrm2.str() << std::endl;	// 출력: char pointer	
	sstrm2.read(buffer, 6);
	buffer[6] = '\0';
	std::cout << "buffer : " << buffer << std::endl;		// 출력: char p
	std::cout << "sstrm2 : " << sstrm2.str() << std::endl;	// 출력: char pointer
	std::cout << "rdbuf() : " << sstrm2.rdbuf() << std::endl;	// 출력: ointer
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