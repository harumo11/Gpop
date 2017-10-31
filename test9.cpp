#include <iostream>
#include "Vector.hpp"
#include <unistd.h>

int main(int argc, char const* argv[])
{
	Vector plot;
	plot.plot(0,0,1,0);
	plot.plot(1,0,0,1);
	plot.plot(1,1,-1,0);
	plot.plot(0,1,0,-1);
	plot.show();

	sleep(3);

	return 0;
}
