#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Gnuplot.hpp"

class Element {
	public:
		double x;
		double y;
};

class Hist {
	public:
		Hist();
		Hist(double relative_width);
		~Hist();
		void plot(double data);
		void plot(double x, double y);
		void plot(std::vector<double> &data);
		void show();
		void set_line(bool should_use_line);
		void set_x_label(std::string label);
		void set_y_label(std::string label);
		void set_window_size(unsigned int width, unsigned int height);
		void set_x_range(double min, double max);
		void set_y_range(double min, double max);


	private:
		std::vector<double> data_container;
		Gnuplot pipe;
		bool is_line  = false;
		double trasnparency = 0;
		double relative_width;
};
