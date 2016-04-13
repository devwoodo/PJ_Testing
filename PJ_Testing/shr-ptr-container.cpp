#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;

class First
{
public:
	virtual void func()
	{
		cout << "First::func() called." << endl;
	}
};

class Second : public First
{
public:
	virtual void func()
	{
		cout << "Second::func() called." << endl;
	}
};

int main()
{
	std::vector<std::shared_ptr<First>> spvec;
	spvec.reserve(10);

	for (int i = 0; i < 5; ++i)
		spvec.push_back(std::make_shared<First>());
	for (int i = 0; i < 3; ++i)
		spvec.push_back(std::make_shared<Second>());

	spvec[0]->func();
	spvec[7]->func();

	cout << "----------------------" << endl;
	for (const auto& it : spvec)
		it->func();

	cout << endl << "======================" << endl;


	return 0;
}