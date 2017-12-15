# Gpop | Pie

|[Home](./Pie.md) | [Tutorial](./Pie_tuto.md) | [API](./html/index.html)|
|-----------------|---------------------------|-------------------------|

## Introduction
Pieは円グラフを作成するものです．
他の描画クラスと同様に簡単に円グラフを作成することが可能です．

## Usage
下記の例のようにstd::vector<double>,もしくはdouble型の変数を
Gpop::Pie::plot()関数に渡すだけで描画することが可能です．

```cpp
#include <iostream>
#include <string>
#include <Gpop/Pie.hpp>

int main(void){
	Gpop::Pie plot;
	std::string str;

	//要素のラベルと値を入力
	plot.plot(30, "a");
	plot.plot(70, "b");
	
	//描画
	plot.show();
	
	//文字を入力するとプロットを閉じる
	std::cin >> str;
}
```
![Pie](./pie.png)

円グラフは各要素を１００分率で表したものです．
そのため，入力された要素のデータの合計が100に満たない場合
クラス内部で100分率に直されて表示されます．
これは，より直感的に円グラフを描画するように作用します．

つまり，もし要素が

```cpp
	plot.plot(30, "a");
	plot.plot(70, "b");
	plot.plot(70, "c");
```
というふうに入力された場合，各要素の合計は

$$$30+70+70=170$$$

となり，合計が100ではないため，クラス内部で再計算が行われます．
たとえば，a要素の場合は

$$$\frac (3)_(3)$$$

のような計算が行われ，それに対する面積が割り当てられます．