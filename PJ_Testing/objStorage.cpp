#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

class Super
{
public:
	const int _id;

	virtual void print() const = 0;// { cout << "This is Super." << endl; }
	virtual std::shared_ptr<Super> clone() const = 0;// { return std::make_shared<Super>(); }
protected:
//public:
	Super() : _id(0) {};
	Super(int id) : _id(id) {};

	//friend class shared_ptr;

};

class Sub1 : public Super
{
public:
	Sub1() : Super(1) {};
	virtual void print() const
	{
		cout << "This is Sub1." << endl;
	}
	std::shared_ptr<Super> clone() const
	{
		return std::make_shared<Sub1>();
	}
};

class Sub2 : public Super
{
public:
	Sub2() : Super(2) {};
	virtual void print() const
	{
		cout << "This is Sub2." << endl;
	}
	std::shared_ptr<Super> clone() const
	{
		return std::make_shared<Sub2>();
	}
};

class Sub3 : public Super
{
public:
	Sub3() : Super(3) {};
	virtual void print()  const
	{
		cout << "This is Sub3." << endl;
	}
	std::shared_ptr<Super> clone() const
	{
		return std::make_shared<Sub3>();
	}
};

//class ClassStorage
//{
//public:
//	void addClassType(Super newType)	//? param.를 어떻게 줘야..?
//	{
//		//rev
//		vec.push_back(newType);
//	}
//
//	Super& getObject(int id)	//? ref return 이면 안되는데 어떻게..?
//	{
//
//	}
//
//private:
//	std::vector<Super&> vec;
//};

class ClassCast
{
public:
	static void addType(std::shared_ptr<Super> ptr)
	{
		_storage.insert(std::make_pair(ptr->_id, ptr));
	}
	static std::shared_ptr<Super> getType(int id)
	{
		return _storage.find(id)->second->clone();
	}

private:
	static std::unordered_map<int, std::shared_ptr<Super>> _storage;
};
std::unordered_map<int, std::shared_ptr<Super>> ClassCast::_storage;

int main()
{
	//ClassCast::addType(std::make_pair<int, std::shared_ptr<Super>>(1, std::make_shared<Sub1>()));
	ClassCast::addType(std::make_shared<Sub1>());
	ClassCast::addType(std::make_shared<Sub2>());
	ClassCast::addType(std::make_shared<Sub3>());

	auto ptr1 = ClassCast::getType(1);
	ptr1->print();
	
	return 0;
}