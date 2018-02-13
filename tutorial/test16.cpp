#include <iostream>
#include <vector>
#include <random>

#include "Bar.hpp"

int main(int argc, char const* argv[])
{
	Bar plot;
	std::random_device rnd;
	std::vector<double> vec;

	while (true) {
		for (int i = 0; i < 20; i++) {
			vec.push_back(rnd());
		}
		//plot.plot(vec);
		plot.pause(10);
		plot.show();
		vec.clear();
	}

	return 0;
}
