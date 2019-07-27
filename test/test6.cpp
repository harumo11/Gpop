#include <iostream>
#include <string>
#include <unistd.h>

#include <gpop/Pie.hpp>

int main(int argc, char const* argv[])
{
	Pie plot;
	std::string str;
	
	plot.plot(30, "a");
	plot.plot(70, "b");
	plot.plot(70, "c");
	plot.show();

	std::cin >> str;

	return 0;
}
