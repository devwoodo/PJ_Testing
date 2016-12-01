#include <iostream>
#include <string>

int main()
{
	std::ostream * postrm;
	std::string str;

	std::cout << "Input>>";
	postrm = std::cin.tie(0);
	//std::getline(std::cin, str);	//
	std::cin >> str;				//
	std::cout << "Output>>" << str << std::endl;
	*postrm << "Output>>postrm" << std::endl;
	//std::cout.flush();
	std::cin.clear();

	std::cout << "Input>>";
	std::cin.tie(postrm);
	std::getline(std::cin, str);
	std::cout << "Output>>" << str << std::endl;

	std::cout << "Input>>";
	std::getline(std::cin, str);
	std::cout << "Output>>" << str << std::endl;

	std::cout << "Program ends." << std::endl;

	return 0;
}