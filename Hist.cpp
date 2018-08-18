#include <algorithm>
#include <cmath>
#include "Hist.hpp"

Hist::Hist() : pipe() {

}

Hist::Hist(const unsigned int bin_number){

	this->bin_number = bin_number;

}

Hist::~Hist() {

	this->pipe.write_command("quit");
}


/**
 * @brief ヒストグラムを作成するための生データを入力する
 * ための関数．
 *
 * @param data
 */
void Hist::plot(std::vector<double> &data){

	std::cout << "debug0" << std::endl;
	this->bin_container.push_back(this->make_hist(data));

}

/**
 * @brief 指定範囲内にある要素の数を計算する
 *
 * @param data 元のデータ
 * @param first_number 調べたい範囲の最小値
 * @param end_number 調べたい範囲の最大値
 *
 * first_number <= x < end_number
 * の値をカウントする
 *
 * @return 範囲内に存在するデータの数
 */
unsigned int Hist::count_elements(std::vector<double> data, double first_number, double end_number){

	unsigned int counted_number = 0;

	for (auto&& e : data){
		if ((first_number <= e) && (e < end_number)) {
			counted_number++;
		}
	}

	std::cout << "debug1" << std::endl;
	return counted_number;
}


std::vector<Bin> Hist::make_hist(std::vector<double> data){

	std::vector<Bin> bin_vec;

	//dataの最大値を抽出
	double max = *std::max_element(data.begin(), data.end());
	double min = *std::min_element(data.begin(), data.end());

	//bin_widthを決めるために最大値をbin_numberで割る
	this->bin_width = std::abs(max - min) / this->bin_number;

	//範囲内の要素の数を数える
	for (unsigned int i = 0; i < this->bin_number; i++) {
		Bin bin;
		//binの中央値を計算
		double first_number = min + i * this->bin_width;
		double end_number = first_number + this->bin_width;
		bin.x = first_number + this->bin_width / 2.0;
		bin.y = this->count_elements(data, first_number, end_number); 
		bin_vec.push_back(bin);
	}

	std::cout << "debug2" << std::endl;
	return bin_vec;
}

void Hist::show() {

	//棒グラフを色で埋めることをgnuplotに伝える
	if (this->trasnparency > 0) {
		this->pipe.write_command("set style fill transparent solid 0.7");
	}
	else {
		this->pipe.write_command("set style fill solid");
	}

	//棒グラフに枠を付ける
	if (this->is_line) {
		this->pipe.write_command("set style fill solid border lc rgb \"black\"");
	}

	//これからインラインモードでデータを入力することをgnuplotに伝える
	//this->pipe.write_command("plot '-'with boxes lw 1 notitle");
	this->pipe.write_command(this->make_command());

	for (auto&& vec : this->bin_container){
		for (auto&& e : vec){
			std::string com = std::to_string(e.x) + "\t" + std::to_string(e.y);
			std::cout << com << std::endl;
			this->pipe.write_command(com);
		}
		//ひとつの行が終わったことをeを送ることで伝える．
		std::cout << std::endl;
		this->pipe.write_command("e");
	}

	//全てのデータの送信が終了したことをeを送ることで伝える
	this->pipe.flush();
}

void Hist::set_line(bool shoule_use_line){

	if (shoule_use_line) {
		this->is_line = true;
	}
	else {
		this->is_line = false;
	}
}

std::string Hist::make_command(){
	
	std::string command = "plot ";

	//bin_containerのデータの種類だけ<plot '-'with boxes lw 1 notitle"
	for (int i = 0; i < (int)this->bin_container.size(); i++) {
		command += "'-' w boxes lw 1 notitle , ";
	}

	return command;
}

void Hist::set_x_label(std::string label){
	this->pipe.util_set_x_label(label);
}

void Hist::set_y_label(std::string label){
	this->pipe.util_set_y_label(label);
}

void Hist::set_x_range(double min, double max){
	this->pipe.util_set_x_range(min, max);
}

void Hist::set_y_range(double min, double max){
	this->pipe.util_set_y_range(min, max);
}

void Hist::set_window_size(unsigned int width, unsigned int height){
	this->pipe.util_set_window_size(width, height);
}

void Hist::set_autoscale(bool should_autoscale){
		this->pipe.util_set_autoscale(should_autoscale);
}

