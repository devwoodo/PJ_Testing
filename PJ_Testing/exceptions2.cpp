#include <iostream>
#include <vector>

class storage
{
public:
	std::vector<int> vec;

public:
	storage();
	storage(int);
	int search(int);

	
};

int main()
{
	storage store(10);
	
	for (int i = 0; i < 10; i++)
		store.vec.push_back(i);

	return 0;
}