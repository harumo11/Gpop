#pragma once

#include <cstdio>
#include <memory>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <Logger/Logger.hpp>

class Gnuplot {
	public:


		Gnuplot();
		~Gnuplot();
		void write(std::string command);
		void write_command(std::string command);
		bool is_open();
		void flush();


	private:
		FILE* file_discripter;
		bool pipe_state = false;

		bool open_gnuplot();
		void close_gnuplot();
};
