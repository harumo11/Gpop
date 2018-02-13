#include <iostream>
#include <gpop/Pie.hpp>

int main(int argc, char const* argv[])
{
	Pie plot;

	plot.plot(30, "a");
	plot.plot(70, "b");

	plot.show();

	plot.save_as_png("This_is_pie_tutorial");

	std::cin.get();
	return 0;
}
