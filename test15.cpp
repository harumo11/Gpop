#include <iostream>
#include <cmath>
#include <vector>
#include <unistd.h>
#include "Bar.hpp"

int main(int argc, char const* argv[])
{
	Bar plot;
	for (int i = 0; i < 100; i++) {
		double good_data = std::cos(i*0.01);
		double bad_data  = std::sin(i*0.01);
		plot.plot(good_data, "good");
		plot.plot(bad_data,  "bad");
		plot.show();
		usleep(100000);
	}
	return 0;
}
