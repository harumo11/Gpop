# gpop

## TODO list

- [Hist,Bar]Histはヒストグラムをする（Opencv）Barは棒グラフ．明確な差異がある
- [Hist] 透明設定ができるように
- [Hist] 枠の設定ができるように
- [Hist] ヒストグラム作成ができるように
- [Bar] リアルタイムプロットしても，プロット毎にプロットが消えるように

---

## NOTE list
- [setting] Setting - window - behavior 
	Prevent focus stealing - ON

# Gnu Plot on Pipe Library

簡単にデータをC++11プロットするライブラリです．
できるだけ簡単にプロットすることに注力しています．

現在，使用可能なプロットの種類は以下のとおりです．

- [Serise](./docs/Series.md)
- [Pie](./docs/Pie.md)
- [Vector](./docs/Vector.md)
- Histogram
- Bar

また，プロットする機能以外にPNGファイルとして保存したり，逐次データを更新してリアルタイムプロットを行うこともできます．下の表で表記がNoとなっていてもPNGの保存はGUIから行うことが可能であり，またEPSもGUIから保存可能です．

|Name|Save as PNG|Real time plot|
|:----:|:-----------:|:--------------:|
|Serise|OK       |OK            |
|Pie|  OK        |OK            |
|Vector|NO       |NO            |
|Histogram|  OK  |OK      |
|Bar| OK        |OK             |

## Dependency

- gnuplot
- ubuntu
- C++11

## Instalation

Install gnuplot
```sh
sudo apt-get install gnuplot
```

Build gpop
```sh
cd gpop
mkdir build
cd build
cmake ../
make -j
sudo make install
```

## Sample
わずか数行でプロットすることが可能なことが以下のプログラムを見るとわかるでしょう．

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Gpop/Series.hpp"

int main(void){
	//描画データ作成
	std::vector<double> v;
	for(int i = 0; i < 180; i++){
		v.push_back(std::cos(i*M_PI/180));
	}

	//描画
	Gpop::Series plot;
	plot.plot(v);
	plot.show();

	//終了処理．エンターを押すと，プロットウィンドウが閉じます
	std::cout << "Press Enter Key" << std::endl;
	std::string end;
	std::cin >> end;
	return 0;
}
```

他にもサンプルがあります．

|Name|Discription|Used class name|
|:----:|:---------:|:-------------:|
|test0     |とりあえずプロット|Series|
|test1     |gnuplotを直に使う|Gnuplot|
|test2     |複数のデータのプロット|Series|
|test3     |リアルタイムプロット|Series|
|test4     |複数のデータのリアルタイムプロット|Series|
|test5     |タイトル＆ラベル設定|Series|
|test6     |円グラフ|Pie|
|test7     |複数ウィンドウのリアルタイムプロット|Series|
|test8     |ウィンドウサイズの変更|Series|
|test9     |ベクター図の作成|Vector|
|test10    |リアルタイム円グラフ|Pie|
|test11    |正規分布の棒グラフ|Hist|
|test12    |ランダムな値のヒストグラム|Bar|
|test13    |合計が100となる入力の円グラフのプロット|Pie|
|test14    |test13の内容をpngとして保存するもの|Pie|
|test15    |最小構成のランダムな値の棒グラフ|Bar|
|test16    |棒グラフをリアルタイムプロットする棒グラフ|Bar|
|test17    |描画設定込みでのプロット1|Series|
|test18    |描画設定込みでのプロット2|Series|




