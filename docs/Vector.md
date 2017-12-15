# Gpop | Vector

| [Home](./Vector.md) | [Tutorial](./Vector.md) | [API](./html/index.html)|
|---------------------|-------------------------|-------------------------|

## Introduction
Vectorはベクトル図をプロットするものです．
１つの矢印をプロットするために必要な情報を以下に示します．

0. x | 開始点のx座標
1. y | 開始点のy座標
2. dx|開始点からのx座標の変位
3. dy|開始点からのy座標の変位

## Usage 
下記の例のように,矢印の描画に必要な４つの情報を
Gpop::Vector::plot()関数に渡すと１つの矢印が描画できます．

```cpp
#include <iostream>
#include <Gpop/Vector.hpp>

int main(void)
{
	Gpop::Vector plot;

	//サイズとラベルをお好みで調整
	plot.set_x_label("X label");
	plot.set_y_label("Y label");
	plot.set_window_size(300, 300);

	plot.plot(0,0,1,0);
	plot.plot(1,0,0,1);
	plot.plot(1,1,-1,0);
	plot.plot(0,1,0,-1);
	plot.plot(-1,-1,1,1);
	plot.show();

	std::cin.get();
}
```
