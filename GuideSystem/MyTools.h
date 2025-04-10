#pragma once
#include <afx.h>
#include <iostream>
#include <sstream>
#include <fstream>

//存放一些辅助函数，或者作为前后的传输类
class MyTools
{
public:
	MyTools();
	~MyTools();
	int Pow(int x, int y);//求方
	string Mysplit(string s);//用来处理Floyd里面生成的path以保证输出两点最短距离时的路径里景点不会重复
	string Mysplit2(string s);//分割所有Road取最后一条为推荐路线

	//int Num(int x);//求组合数
	//接收MGraph里的顶点数字
	//int vertexNum;
	//void Change(int *x, int *y);//交换两数

};

