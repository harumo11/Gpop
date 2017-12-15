#pragma once

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <utility>
#include <unistd.h>
#include "Gnuplot.hpp"
#include <Logger/Logger.hpp>

/**
 * @brief ２次元座標を表すクラス
 */
class XY {
	public :
		double x = 0;
		double y = 0;
};

/**
 * @brief ２次元のプロットのクラス
 */
class Series {
	public:
		Series();
		Series(std::string title);
		Series(std::string title, unsigned int width, unsigned int height);
		~Series();

		void plot(std::vector<double> &data);
		void plot(std::vector<double> &data, const std::string property);
		void plot(double data);
		void plot(double data, const std::string property);
		void show();
		void pause(int msec);
		void set_x_range(double min, double max);
		void set_y_range(double min, double max);
		void set_title(std::string title);
		void limit_max_number(int number);
		void set_x_label(std::string label);
		void set_y_label(std::string label);
		void save_as_png(std::string title);
		void set_window_size(unsigned int width, unsigned int height);

	private:
		std::string make_command();
		void resize_data_container();
		Gnuplot pipe;
		std::vector<std::list<XY>> data_container;
		unsigned int window_height = 640;
		unsigned int window_width  = 480;


		/**
		 * @brief data_containerにデータを渡す用の1次元配列
		 *
		 * size()がプロットされる値の種類になる．
		 * plot()でdata_containerに入れて，show()でdata_containerに移す
		 */
		std::list<double> data_buffer;


		/**
		 * @brief xの範囲を格納する変数
		 */
		std::pair<double, double> x_range;


		/**
		 * @brief yの範囲を格納する変数
		 */
		std::pair<double, double> y_range;


		/**
		 * @brief data_containerの最大サイズを格納する変数
		 */
		int max_number = 10000;

		/**
		 * @brief 線の種類，大きさ，色などの指定を保存する変数
		 */
		std::vector<std::string> data_property;

		/**
		 * @brief pause(),show()が呼ばれた時，data_propertyに内容を移す
		 */
		std::vector<std::string> data_property_buffer;
};



