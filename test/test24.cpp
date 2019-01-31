#include <iostream>
#include <random>
#include "Hist.hpp"

int main(int argc, char const* argv[])
{
	std::random_device rnd;
	std::normal_distribution<> dist;

	std::vector<double> data1, data2;
	for (int i = 0; i < 1000; i++) {
		data1.push_back(dist(rnd));
		data2.push_back(dist(rnd));
	}

	Hist plot;
	plot.plot(data1);
	plot.plot(data2);
	plot.show();
	std::cin.get();
	
	return 0;
}