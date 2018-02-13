#include <iostream>
#include <vector>
#include <cmath>
#include <gpop/Series.hpp>

int main(int argc, char const* argv[])
{

	const double t = 0.1;
	std::vector<double> vec;
	for (int step = 0; step < 100; step++) {
		vec.push_back(std::log(step*t));
	}

	Series plot;
	plot.plot(vec);
	plot.show();
	plot.save_as_png("demo2_log");
	return 0;
}
