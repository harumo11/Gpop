#include <iostream>
#include "Pie.hpp"

int main(int argc, char const* argv[])
{
	Pie plot;
	

	plot.set_window_size(300, 300);

	for (int i = 0; i < 100; i++) {
		plot.plot(i, "a");
		plot.plot(50, "b");
		plot.pause(100);
	}

	plot.save_as_png("test10");
	return 0;
}
