#include <iostream>
#include <vector>

int main()
{
	std::cout << "Program starts." << std::endl;
	std::vector<int> vec(10);

	for (int i = 10; i < 20; i++)
		vec.push_back(i);

	try {
		auto it = find(vec.begin(), vec.end(), 9);

		if (it == vec.end())
			throw - 1;
	}
	catch (int ex) {
		std::cout << "No result. Error code : " << ex << std::endl;
	}

	std::cout << "Program ends." << std::endl;

	return 0;
}