#include <iostream>
#include <random>
#include <vector>

#include "../include/gpop/Series.hpp"

int main(int argc, char const* argv[])
{
	std::random_device rnd;
	std::vector<double>  vec;
	for (int i = 0; i < 100; i++) {
		vec.push_back(rnd());
	}

	Series plot;
	plot.plot(vec, "t\"Main\"");
	plot.show();
	std::cin.get();
	return 0;
}
