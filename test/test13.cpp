#include <iostream>
#include "Pie.hpp"

int main(int argc, char const* argv[])
{
	Pie plot;

	plot.plot(30, "a");
	plot.plot(70, "b");

	plot.show();

	std::cin.get();
	return 0;
}
