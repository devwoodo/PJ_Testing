#include <iostream>

class Singleton
{
public:
	static Singleton& instance()
	{
		static Singleton _instance;
		return _instance;
	}
public:
	int a;
private:
	Singleton()
	{}
private:
	static Singleton _instance;
};
Singleton Singleton::_instance;		// Instance() 안이나 여기, 둘 중 한군데에만 static 변수 정의있으면 ok


int main()
{
	std::cout << Singleton::instance().a << std::endl;
	Singleton::instance().a = 10;
	std::cout << Singleton::instance().a << std::endl;

	return 0;
}