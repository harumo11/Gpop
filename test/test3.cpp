#include "Series.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char const* argv[])
{
	
	Series plot;
	double data = 0;

	plot.limit_max_number(50);
	plot.set_y_range(-1.2,1.2);

	////make data
	for (int i = 0; i < 1000; i++) {
		data = sin(i * M_PI / 180);

		plot.plot(data);
		plot.pause(10);
	}

	return 0;
}

