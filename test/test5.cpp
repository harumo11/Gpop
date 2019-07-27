#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include <Gpop/Series.hpp>

int main(int argc, char const* argv[])
{
	
	Gpop::Series plot;

	std::vector<double> v;
	for (int i = 0; i < 180; i++) {
		v.push_back(std::cos(i*M_PI/180));
	}
	plot.plot(v);

	v.clear();
	for (int i = 0; i < 180; i++) {
		v.push_back(std::sin(i*M_PI/180));
	}
	plot.plot(v);
	plot.set_title("The 5th tutorial");
	plot.set_x_label("x");
	plot.set_y_label("y");
	plot.show();
	plot.save_as_png("test");

	std::cout << "Press Enter Key" << std::endl;
	std::string end;
	std::cin >> end;

	return 0;
}


