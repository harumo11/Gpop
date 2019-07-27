#include <iostream>
#include <vector>

#include <gpop/Bar.hpp>

int main(int argc, char const* argv[])
{
	Bar plot;
	plot.plot(10, "good");
	plot.plot(24, "soso");
	plot.plot(6,  "nomal");
	plot.plot(4,  "notgood");
	plot.plot(1,  "bad");
	plot.show();
	std::cin.get();

	return 0;
}
