#include <iostream>
#include <cmath>

#include "../include/gpop/Hist.hpp"

using namespace std;

double nd(double x) {
	return 1/(sqrt(2*M_PI))*exp(-(x*x)/2);
}

int main(int argc, char const* argv[])
{
	double res = 50;

	Hist plot;
	plot.set_line(true);
	plot.set_line(false);

	std::vector<double> vec;
	for (int i = -50; i < res; i++) {
		double x = (double)i/res;
		cout << "x = " << x << "pro = " << nd(x) << endl;
		vec.push_back(nd(x));
	}
	plot.plot(vec);
	plot.show();
	cin.get();

	return 0;
}
