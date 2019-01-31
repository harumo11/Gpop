#include <gpop/Series.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main(int argc, char const* argv[])
{
	
	Series plot;

	std::vector<double> v;
	for (int i = 0; i < 180; i++) {
		v.push_back(std::cos(i*M_PI/180));
	}
	plot.plot(v);
	plot.show();

	std::cout << "Press Enter Key" << std::endl;
	std::string end;
	std::cin >> end;

	return 0;
}

