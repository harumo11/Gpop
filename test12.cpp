#include <iostream>
#include <vector>
#include <random>
#include "Bar.hpp"

int main(int argc, char const* argv[])
{
	Bar plot;
	std::random_device rnd;
	std::vector<double> vec;

	for (int i = 0; i < 100; i++) {
		vec.push_back(rnd());
	}
	plot.plot(vec);
	vec.clear();

	for (int i = 0; i < 100; i++) {
		vec.push_back(rnd());
	}
	plot.plot(vec);

	plot.show();
	std::cin.get();

	return 0;
}
