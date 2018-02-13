#include <iostream>
#include <vector>
#include <cmath>
#include <gpop/Series.hpp>

using namespace std;

double f(double x){
	return 1/(std::sqrt(2*M_PI)) * std::exp((-x*x)/2);
}

int main(int argc, char const* argv[])
{

	std::vector<double> result;

	double count = 100;
	for(double x = -1.0; x < 1; x += (1/count)){
		result.push_back(f(x));
		cout << "x = " << x << endl;
	}

	Series graph("gaussian");
	graph.plot(result);
	graph.show();
	cin.get();
	
	return 0;
}
