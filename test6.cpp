#include <iostream>
#include <string>
#include <unistd.h>
#include "Pie.hpp"

int main(int argc, char const* argv[])
{
	Pie plot;
	std::string str;
	
	plot.plot(30, "a");
	plot.plot(70, "b");
	plot.plot(70, "c");
	plot.show();
	std::cout << "1" << std::endl;
	std::cin >> str;

	plot.plot(10, "a");
	plot.plot(90, "b");
	plot.plot(70, "c");
	plot.show();
	std::cout << "2" << std::endl;
	std::cin >> str;

	return 0;
}
