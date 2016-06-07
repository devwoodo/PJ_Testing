#include <iostream>
#include <vector>
#include <iomanip>

void print(const std::vector<std::vector<int>>& vec);

int main()
{
	// ========================
	// method1
	std::cout << "========================" << std::endl;
	std::vector<std::vector<int>> vec1;
	vec1.push_back(std::vector<int>());
	vec1.push_back(std::vector<int>());
	for (int i = 0; i < 3; ++i)
		vec1[0].push_back(i);
	for (int i = 0; i < 3; ++i)
		vec1[1].push_back(i+3);

	print(vec1);

	// ========================
	// method2
	std::cout << std::endl << "========================" << std::endl;
	std::vector<std::vector<int>> vec2{ {1,2,3}, {4,5,6} };	// initializer
	print(vec2);

	// ========================
	// method2
	std::cout << std::endl << "========================" << std::endl;
	std::vector<std::vector<int>> vec3(2, std::vector<int>(3));	// vec(row, std::vector<int>(col))
	print(vec3);

	return 0;
}

void print(const std::vector<std::vector<int>>& vec)
{
	for (auto& r : vec) {
		for (auto& c : r)
			std::cout << std::setw(4) << c;
	
		std::cout << std::endl;
	}

	return;
}
