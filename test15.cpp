#include <iostream>
#include <cmath>
#include <vector>
#include <unistd.h>
#include "Bar.hpp"

int main(int argc, char const* argv[])
{
	Bar plot;
	for (double i = 0; i < M_PI/2; i+=0.03) {
		double good_data = std::cos(i);
		double bad_data  = 1-std::sin(i);
		plot.plot(good_data, "good");
		plot.plot(bad_data,  "bad");
		usleep(1000000);
		plot.show();
	}
	return 0;
}
