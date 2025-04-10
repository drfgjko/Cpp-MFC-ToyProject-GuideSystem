#pragma once
#include "MyTools.h"
const int MaxSize = 30;

//邻接矩阵 P180
class MGraph
{
//成员变量和成员函数设置为public方便调用
public:
	MGraph();//构造函数
	~MGraph();//析构函数
	int find(string s) const;//返回顶点的数字下标
	void Floyd();//寻找两点最短路径
	void Change(int x);//读取别的txt（地图）重置数据 x为对应地图的标号
	void backTracing(int x);//利用回溯算法找到推荐路线
	string getRoad();//获取推荐路线->这个函数才会处理g数组
	string ShortPath(string x,string y);
	string getVertex();//获取景点
	string getArc();//获取边集
	string getPath();//获取path
	string getDist();//获取dist
	int getVertexNum();//获取dist
	string getTmp();//输出看一下数组是否正确构建了
	//string getG();//输出看一下数组是否正确构建了
	string getIn();//输出看一下数组是否正确构建了
	string getBest();//输出看一下数据是否正常
	string getLen();//输出看一下数据是否正常

	void setString(string s);//用于前台显示数据来检验算法是否有问题
	string s;//用于前台显示数据来检验算法是否有问题

	MyTools *p;

	string vertex[MaxSize];//顶点数组
	int arc[MaxSize][MaxSize];//边集，存放权值
	int vertexNum;//顶点个数
	int arcNum;//边数

	//调用Floyd后生成的数据
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];

	//回溯策略时使用的中间数组,可能走过的路线

	int tmp[MaxSize][MaxSize];

	int in[MaxSize];

	//推荐路线
	string road;
	//用于比较
	//对应路线的距离值
	int len;
	//最小距离值
	int best;
};
