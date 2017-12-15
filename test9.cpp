#include <iostream>
#include "Vector.hpp"
#include <unistd.h>

int main(int argc, char const* argv[])
{
	Vector plot;
	plot.set_x_label("X label");
	plot.set_y_label("Y label");
	plot.set_window_size(300, 300);
	plot.plot(0,0,1,0);
	plot.plot(1,0,0,1);
	plot.plot(1,1,-1,0);
	plot.plot(0,1,0,-1);
	plot.plot(-1,-1,1,1);
	plot.show();

	sleep(3);

	return 0;
}
