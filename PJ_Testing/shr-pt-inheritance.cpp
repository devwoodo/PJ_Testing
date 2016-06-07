#include <iostream>
//#include <utility>
#include <memory>

using std::cout;
using std::endl;

class First
{
public:
	int one_a;
public:
	virtual void func()
	{
		cout << "First::func() called." << endl;
	}
};

class Second : public First
{
public:
	int two_a;
public:
	virtual void func()
	{
		cout << "Second::func() called." << endl;
	}
};

int main()
{
	cout << "=====================" << endl;
	cout << "case 1: " << endl;
	std::shared_ptr<First> shrFpt = std::make_shared<Second>();
	//*(shrFpt).one_a;		// error "����� �����ϴ�."
	shrFpt->func();			// ok

	cout << "=====================" << endl;
	cout << "case 2: " << endl;
	First * Fpt = &(Second());
	//Fpt->two_b;		// error "����� �����ϴ�."
	
	auto dpt = dynamic_cast<Second *>(Fpt);
	dpt->two_a;		//ok

	cout << "=====================" << endl;
	cout << "case 3: " << endl;
	//auto shrdcast = dynamic_cast<std::shared_ptr<Second>>(shrFpt);	// error: "������ Ŭ���� ���Ŀ� ���� ������ �Ǵ� ���������մϴ�."
	auto shrdpcast = std::dynamic_pointer_cast<Second>(shrFpt);
	cout << shrdpcast->two_a << endl;

	return 0;
}