#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <functional>

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 ranNum(seed);
	std::uniform_int_distribution<int> dist(0, 99);
	auto generator = std::bind(dist, ranNum);

	std::cout << "0~99 ������ ���� ���� 100�� ����" << std::endl;

	for (int r = 0; r < 10; ++r) {
		for (int c = 0; c < 10; ++c)
			std::cout << std::setw(3) << generator()%100;
		std::cout << std::endl;
	}
	std::cout << std::endl;




	return 0;
}