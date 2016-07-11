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
Singleton Singleton::_instance;		// Instance() ���̳� ����, �� �� �ѱ������� static ���� ���������� ok


int main()
{
	std::cout << Singleton::instance().a << std::endl;
	Singleton::instance().a = 10;
	std::cout << Singleton::instance().a << std::endl;

	return 0;
}