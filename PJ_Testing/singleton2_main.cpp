#include "singleton2_header.h"

int main()
{
	std::cout << &(Singleton::instance()) << std::endl;
	std::cout << Singleton::instance().a << std::endl;
	Singleton::instance().a = 15;
	std::cout << Singleton::instance().a << std::endl;
	std::cout << &(Singleton::instance()) << std::endl;

	return 0;
}