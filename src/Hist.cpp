#include "../include/gpop/Hist.hpp"

Hist::Hist() : pipe() {

}

Hist::Hist(double relative_width) : pipe(){

	if (relative_width > 0) {
		this->relative_width = relative_width;
	}
	else {
		this->relative_width = 0.8;
	}

	//棒の幅を設定するコマンドを送る
	this->pipe.write_command("set boxwidth " + std::to_string(this->relative_width) + "relative");
}

Hist::~Hist() {

	this->pipe.write_command("quit");
}

void Hist::plot(double data) {

	this->data_container.push_back(data);
}

void Hist::plot(std::vector<double> &data) {

	this->data_container = std::move(data);
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
	this->pipe.write_command("plot '-'with boxes lw 1 notitle");

	for (auto&& e : this->data_container){
		std::string com = std::to_string(e);
		this->pipe.write_command(com);
	}

	//全てのデータの送信が終了したことをeを送ることで伝える
	this->pipe.write_command("e");
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
