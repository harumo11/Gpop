#include <iostream>
#include "Pie.hpp"

int main(int argc, char const* argv[])
{
	Pie plot;
	

	for (int i = 0; i < 100; i++) {
		plot.plot(i, "a");
		plot.plot(50, "b");
		plot.pause(100);
	}
	return 0;
}
