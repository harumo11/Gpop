//#include "../include/gpop/Gnuplot.hpp"
#include "Gnuplot.hpp"


/**
 * @brief コンストラクター．
 *
 * Gnuplotとのパイプを接続する．もし，パイプが接続できない場合はエラーメッセージを表示する．
 */
Gnuplot::Gnuplot(){

	if (this->open_gnuplot() == false) {
		std::cout << Logger::error() << "Can not open a pipe. Have you already install gnuplot?" << std::endl;
		this->pipe_state = false;
	}
	else {

		//pipeのstateをtrueに設定
		this->pipe_state = true;
	}
}


/**
 * @brief デストラクタ．
 *
 * Gnuplotとのパイプを閉じる．エラーは発生しない．
 */
Gnuplot::~Gnuplot(){

	this->close_gnuplot();

}


/**
 * @brief Gnuplotとパイプで接続する．
 *
 * @return もし，パイプの接続がうまく行ったらtrueを返す．そうでない場合は，falseが帰る．
 */
bool Gnuplot::open_gnuplot(){

	errno = 0;
	//this->file_discripter = popen("gnuplot -persist", "w");
	this->file_discripter = popen("gnuplot", "w");

	if (errno == 0) {

		return true;

	}
	else {

		return false;

	}
}


/**
 * @brief パイプを通して，Gnuplotに命令を送る．
 *
 * コマンドは加工されずに，そのまま，パイプを通してGnuplotに送られる．
 *
 * @param command コマンド（末尾に"\n"が必要）
 */
void Gnuplot::write(std::string command){

	fprintf(this->file_discripter, "%s", command.c_str());

}


/**
 * @brief パイプを通して，Gnuplotに命令を送る.
 *
 * 引数のcommandの末尾に"\n"が自動的につく．
 *
 * @param command コマンド(末尾に"\n"が自動で挿入される）
 */
void Gnuplot::write_command(std::string command){

	command += "\n";
	fprintf(this->file_discripter, "%s", command.c_str());

}


/**
 * @brief パイプを閉じで，Gnuplotとの接続を切る．
 */
void Gnuplot::close_gnuplot(){

	pclose(this->file_discripter);
	this->pipe_state = false;

}


bool Gnuplot::is_open(){
	
	return this->pipe_state;
}

void Gnuplot::flush(){

	//pipeのファイルをフラッシュする（強制的に書き出す）
	fflush(this->file_discripter);
}

void Gnuplot::util_set_x_label(std::string label){

	std::string com = "\"" + label + "\"";
	this->write_command("set xl " + com);
}

void Gnuplot::util_set_y_label(std::string label){

	std::string com = "\"" + label + "\"";
	this->write_command("set yl " + com);
}

void Gnuplot::util_set_window_size(unsigned int width, unsigned int height){

	std::string com = "set term qt size ";
	com += std::to_string(width);
	com += ", ";
	com += std::to_string(height);

	this->write_command(com);
}

void Gnuplot::util_set_x_range(double min, double max){

	this->write_command("set xrange["
			            + std::to_string(min)
						+ ":"
						+ std::to_string(max)
						+ "]");
}

void Gnuplot::util_set_y_range(double min, double max){

	this->write_command("set yrange["
			            + std::to_string(min)
						+ ":"
						+ std::to_string(max)
						+ "]");
}


