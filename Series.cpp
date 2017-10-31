#include "Series.hpp"


/**
 * @brief コンストラクタ 1 of 2
 */
Series::Series() : pipe()
{
}


/**
 * @brief コンストラクタ 2 of 2
 *
 * @param title プロットのタイトル
 */
Series::Series(std::string title) : pipe()
{
	this->set_title(title);
}


Series::Series(std::string title, unsigned int width, unsigned int height) : pipe()
{
	this->set_title(title);
	this->set_window_size(width, height);
}


/**
 * @brief デストラクタ
 */
Series::~Series()
{
	this->pipe.write_command("quit");
}

/**
 * @brief windowのサイズを変更する関数.
 * コンストラクタでもウィンドウのサイズは設定可能
 * デフォルトのサイズは640x480
 *
 * @param width ウィンドウの横幅
 * @param height ウィンドウの高さ
 */
void Series::set_window_size(unsigned int width, unsigned int height)
{
	this->window_height = height;
	this->window_width  = width;

	std::string com = "set term qt size ";
	com += std::to_string(this->window_width);
	com += ", ";
	com += std::to_string(this->window_height);

	this->pipe.write_command(com);
}


/**
 * @brief プロットするベクターデータを加える 1 of 2
 *
 * 一度に全部のデータを入力する場合は，この関数を使用して一気に追加する
 * x座標のデータを使用しないため，x座標は連続した整数が用いられる
 *
 * @param data プロットしたいデータ
 */
void Series::plot(std::vector<double> &data)
{
	std::list<XY> coordinate_list;
	XY coorinate;

	//x軸のデータが与えられないので，
	//0からdata.size()個だけx軸のデータを作成する．
	//同時に与えられたy軸のデータを格納する
	for (int i = 0; i < (int)data.size() ; i++) {

		//座標を作成
		coorinate.x = i;
		coorinate.y = data[i];

		//作成した座標をベクターに格納
		coordinate_list.push_back(coorinate);
	}

	//作成したxy座標のベクターを保存
	this->data_container.push_back(coordinate_list);
}


/**
 * @brief プロットしたいデータを加える 2 of 2
 *
 * リアルタイムプロットの場合は，この関数を使用してデータを逐次追加する
 *
 * @param data 追加するデータ
 */
void Series::plot(double data){

	//data_bufferに新しいdataを追加する
	this->data_buffer.push_back(data);

}


/**
 * @brief gnuplotに送るようのコマンドを作成する関数
 *
 * @return コマンド
 */
std::string Series::make_command(){

	std::string command = "plot ";

	//data_containerのデータの種類だけ<"-" w lp,>を作成する．
	for (int i = 0; i < (int)this->data_container.size(); i++) {
		command += "'-' w lp,";
	}
	
	return command;
}


/**
 * @brief plotのタイトルを設定する関数
 *
 * @param title グラフのタイトル
 */
void Series::set_title(std::string title)
{
	std::string com = "\"" + title + "\"";
	this->pipe.write_command("set title " + com);
}




/**
 * @brief プロットを描画する
 * 
 * 全てのデータを一気に表示するときに使用する 
 */
void Series::show()
{

	//これからインラインモードでデータを入力することをgnuplotに伝える．
	this->pipe.write_command(this->make_command());

	//pipeでgnuplotに描画する．
	for (auto&& vec : this->data_container){
		for (auto&& elem : vec){

			//座標を基にコマンドを作成
			std::string command = std::to_string(elem.x) + "\t" + std::to_string(elem.y); 

			//コマンドをgnuplotに送る
			this->pipe.write_command(command);
		}

		//ひとつの行が終わったことをeを送ることで伝える．
		this->pipe.write_command("e");
	}
	//強制的にpipeの内容データを書き出し
	this->pipe.flush();
}


/**
 * @brief x軸の範囲を設定する
 *
 * @param min x軸の最小値
 * @param max x軸の最大値
 */
void Series::set_x_range(double min, double max)
{
	this->pipe.write_command("set xrange["
			                 + std::to_string(min)
							 + ":"
							 + std::to_string(max)
							 + "]");
}


/**
 * @brief y軸の範囲を設定する
 *
 * @param min y軸の最小値
 * @param max y軸の最小値
 */
void Series::set_y_range(double min, double max)
{
	this->pipe.write_command("set yrange["
			                 + std::to_string(min)
							 + ":"
							 + std::to_string(max)
							 + "]");
}


void Series::resize_data_container()
{
	for(auto&& vec : this->data_container){
		if ((int)vec.size() > this->max_number) {
			while ((int)vec.size() != this->max_number) {
				vec.pop_front();
			}
		}
	}
}


/**
 * @brief リアルタイムで追加されたデータのプロットを描画する
 *
 * wheleループの最後で使用される
 *
 * @param msec ポーズする時間の指定，0以上の値を設定する．
 *
 */
void Series::pause(int msec = 1){


	//もし最大表示個数が設定されていたら，その分だけ，data_containerを整理する．
	if (this->max_number != 0) {
		this->resize_data_container();
	}

	//最初の一回だけx=0,y=data_bufferの座標をdata_containerに代入する
	if (this->data_container.empty()) {
		//for (int i = 0; i < (int)this->data_buffer.size(); i++) {
		for(auto&& elem_buffer : this->data_buffer){
			//代入する座標作成
			XY coorinate;
			coorinate.x = 0;
			//coorinate.y = this->data_buffer[i];
			coorinate.y = elem_buffer;

			//data_containerに代入
			this->data_container.push_back({coorinate});
		}
	}

	//data_containerにdata_bufferを追加する
	int i = 0;
	for(auto&& elem_buffer : this->data_buffer){

		//追加する座標を作成する
		XY coorinate;
		coorinate.y = elem_buffer;
		coorinate.x = this->data_container[i].back().x + 1;

		//data_containerに作成した座標を追加する
		this->data_container[i].push_back(coorinate);

		//iteretorを更新
		i++;
	}


	//gnuplotにdata_containerのデータを転送する
	this->pipe.write_command(this->make_command());

	//pipeでgnuplotに描画する．
	for (auto&& vec : this->data_container){
		for (auto&& elem : vec){

			//座標を基にコマンドを作成
			std::string command = std::to_string(elem.x) + "\t" + std::to_string(elem.y); 

			//コマンドをgnuplotに送る
			this->pipe.write_command(command);
		}

		//ひとつの行が終わったことをeを送ることで伝える．
		this->pipe.write_command("e");
	}

	//data_bufferを空にする
	this->data_buffer.clear();

	//autoscaleを設定
	this->pipe.write_command("set autoscale");

	//pipeを強制的に書き出す．
	this->pipe.flush();

	//sleep
	usleep(msec*1000);
}

/**
 * @brief 表示する最大のデータ数を設定する．
 *
 * @param number 表示する最大のデータ数
 *
 *  デフォルトではnumber = 10000となっている．
 *  リアルタム描画の時に最新の１０個のデータだけを表示したい場合
 *  limit_max_number(10)と設定することにより最新の１０個のデータのみを
 *  表示することができる．
 */
void Series::limit_max_number(int number){

	this->max_number = number;
}


/**
 * @brief x軸の名称を設定する
 *
 * @param label x軸の名称
 */
void Series::set_x_label(std::string label)
{
	std::string com = "\"" + label + "\"";

	this->pipe.write_command("set xl " + com);
}


/**
 * @brief y軸の名称を設定する
 *
 * @param label y軸の名称
 */
void Series::set_y_label(std::string label)
{
	std::string com = "\"" + label + "\"";

	this->pipe.write_command("set yl " + com);
}


void Series::save_as_png(std::string title)
{
	title += ".png";
	this->pipe.write_command("set terminal png");
	std::string com = "set output \'" + title + '\'';
	this->pipe.write_command(com);
	this->pipe.write_command("replot");
	this->pipe.write_command("set terminal x11");
	this->pipe.write_command("set output");
}
