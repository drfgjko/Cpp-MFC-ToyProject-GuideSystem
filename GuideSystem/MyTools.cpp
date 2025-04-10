#include "pch.h"
#include "MyTools.h"


MyTools::MyTools()
{
	//vertexNum = 0;
}


MyTools::~MyTools()
{
}

//求方
int MyTools::Pow(int x, int y)
{
	if (y == 0) {
		return 1;
	}

	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;

}

//以"->"分割s，并忽略开头的第一个景点
string MyTools::Mysplit(string s)
{
	int i = 0;
	char split = '-';
	istringstream iss(s);
	string str;//分割出来的
	string path;//要返回的
	while(getline(iss,str, split)) {
		if(i == 0){}
		else {
			if (i == 1) {
				path += str;
			}
			else {
				path += "-" + str;	
			}
			
		}
		i++;
	}
	return path;
}

//根据换行符分割，只取最后一行
string MyTools::Mysplit2(string s)
{
	istringstream iss(s);
	//定义要求一定要常数，而我又不确定是否能使用vector,所以我这里直接随便设了一个数
	string ss[100] = {};
	int i = 0;
	for (string road; getline(iss, road, '\n');) {
		ss[i] = road;
		i++;
	}
	int j =0;
	for (i = 0; i < 50; i++) {
		if (ss[i].empty()) {
			j = i;
			break;
		}
	}
	//从ss读取无效数据、为什么？
	//另设一个j接收下标i，并不能解决问题、不懂

	return ss[j-1];


}
