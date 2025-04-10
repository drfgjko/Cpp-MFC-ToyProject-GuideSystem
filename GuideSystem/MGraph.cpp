#include "pch.h"
#include "MGraph.h"

//构造函数，完成初始化和文件读取生成无向带权图
MGraph::MGraph()
{
	//其实构造为空也可以，因为每次button都会调用change()

	vertexNum = 0, arcNum = 0;
	MyTools MyTools;//工具类
	p = &MyTools;
	string path = "map03.txt";//默认为第三张地图

	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "OPEN FILE FAILED" << endl;
	}

	//读取景点个数
	int i = 0, j = 0;
	char s[5];
	inputFile.getline(s, 5);

	//转换成int
	while (s[i] != '\0') {
		i++;
	}
	int length = i;

	int x = length;//10的x次方
	for (i = 0; i < length; i++) {
		int tmp = s[i] - '0';
		vertexNum += tmp * p->Pow(10, x - 1);
		x--;
	}

	//辅助工具类里的数组数也要设置好
	//p->vertexNum = vertexNum;
	
	////对点初始化
	for (i = 0; i < vertexNum; i++) {
		vertex[i] = "";
	}

	//对边初始化
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			arc[i][j] = 20000;//权的最大值
		}
	}

	//读取景点
	string str;
	getline(inputFile, str);
	stringstream ss(str);
	
	i = 0;
	//保证景点唯一
	string pot;
	while (ss >> pot) {
		if (find(pot) == -1) {
			vertex[i] = pot;
			i++;
		}

	}

	//读取路径
	string s1, s2;
	int index1, index2, dist;
	while (inputFile >> s1 >> s2 >> dist) {
		index1 =find(s1);
		index2 =find(s2);

		//查看是否正常读取
		/*MyTools.setIndex1(index1);
		MyTools.setIndex2(dist);*/
		
		//无向图对称
		arc[index1][index2] = dist;
		arc[index2][index1] = dist;

	}

	//关闭文件
	inputFile.close();

	//调用Floyd生成path和dist数组，为寻找两点最短路径时使用
	Floyd();

	//初始化中间数组
	for (i = 0; i < MaxSize; i++) {
		in[i] = 0;
	}
	for (i = 1; i <= vertexNum; i++) {
		in[i] = i;
	}
	for (i = 1; i <= vertexNum; i++) {
		for (j = 1; j <= vertexNum; j++) {
			tmp[i][j] = arc[i-1][j-1];
		}
	}
	best = 20000;
	len = 0;
	road = "";

}

//析构为空
MGraph::~MGraph()
{
}

//返回顶点的数字下标 ->不做修改，只是输出 ->const
int MGraph::find(string s) const
{
	int i = 0;
	for (i = 0; i < vertexNum; i++) {
		if (s == vertex[i]) {
			return i;
		}
	}
	return -1;//没找到返回-1

}

//参照书本P200
//FLoyd解决两点最短路径问题
void MGraph::Floyd()
{
	int i, j, k;

	for (i = 0; i < MaxSize; i++)
	{
		for (j = 0; j < MaxSize; j++)
		{
			dist[i][j] = 20000;
			path[i][j] = "";
		}
	}

	//初始化矩阵dist和path
	for (i = 0; i < vertexNum; i++)
	{
		for (j = 0; j < vertexNum; j++)
		{
			dist[i][j] = arc[i][j];
			if (dist[i][j] != 20000)//权的最大值
			{
				path[i][j] += vertex[i] + "- " + vertex[j];
			}
			else
			{
				path[i][j] = "";
			}
		}
	}

	
	for (k = 0; k < vertexNum; k++)
	{
		for (i = 0; i < vertexNum; i++)
		{
			for (j = 0; j < vertexNum; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] +"-" + p->Mysplit(path[k][j]);
					
				}
			}
		}
	}
}

//读取别的txt（地图）
void MGraph::Change(int x)
{
	vertexNum = 0, arcNum = 0;

	//读取对应路径
	string path;
	switch (x)
	{
	case(1):
		path = "map01.txt";
		break;
	case(2):
		path = "map02.txt";
		break;
	case(3):
		path = "map03.txt";
		break;
	case(4)://这张表是用来跟别人的程序做比较检验程序是否正确的<-所以跟别人的图一样，实际使用时，数字4是不能使用的
		path = "map04.txt";
		break;
	}

	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "OPEN FILE FAILED" << endl;
	}

	//修改数据
	//读取景点个数
	int i = 0, j = 0;
	char s[5];
	inputFile.getline(s, 5);

	//转换成int
	while (s[i] != '\0') {
		i++;
	}
	int length = i;

	int num = length;//10的x次方
	for (i = 0; i < length; i++) {
		int tmp = s[i] - '0';
		vertexNum += tmp * p->Pow(10, num - 1);
		num--;
	}

	//辅助工具类里的数组数也要设置好
	//p->vertexNum = vertexNum;

	//对点初始化
	for (i = 0; i < MaxSize; i++) {
		vertex[i] = "";
	}

	//对边初始化
	for (i = 0; i < MaxSize; i++) {
		for (j = 0; j < MaxSize; j++) {
			arc[i][j] = 20000;//权的最大值
			tmp[i][j] = 20000;
		}
	}

	//读取景点
	string str;
	getline(inputFile, str);
	stringstream ss(str);

	i = 0;
	//保证景点唯一
	string pot;
	while (ss >> pot) {
		if (find(pot) == -1) {
			vertex[i] = pot;
			i++;
		}

	}

	//读取路径
	string s1, s2;
	int index1, index2, dist;
	while (inputFile >> s1 >> s2 >> dist) {
		index1 = find(s1);
		index2 = find(s2);

		arc[index1][index2] = dist;
		arc[index2][index1] = dist;
	}

	//关闭文件
	inputFile.close();

	//重新生成path和dist数组
	Floyd();


	//初始化中间数组
	for (i = 0; i < MaxSize; i++) {
		in[i] = 0;
	}
	for (i = 1; i <= vertexNum; i++) {
		in[i] = i;
	}

	int k =0,t = 0;
	//tmp数组很容易构造错
	for (i = 0; i <= vertexNum; i++) {
		k = 0;
		for (j = 0; j <= vertexNum; j++) {
			if (i == 0) {
				tmp[i][j] = 20000;
			}
			else if(i != 0 && j==0){
				tmp[i][j] = 20000;
			}
			else {
				tmp[i][j] = arc[t][k];
				k++;
			}
		}
		if (i != 0){
			t++;
		}
		
	}


	best = 0x3f3f3f3f;
	len = 0;
	
	road = "";
}

//递归回溯求可能路线及最短距离
void MGraph::backTracing(int x)
{
	//终止条件 遍历到最后一个景点
	if (x > vertexNum) {
		
		//arc[][]！=20000 最后一个景点回到第一个景点有路
		//该路径总长度加上最后一次，从最后一个景点回到第一个景点的距离，小于best
		if(tmp[in[x-1]][1] != 20000 && (len + tmp[in[x-1]][1] )<best) {
			best = len + tmp[in[x - 1]][1];
			//road += " in[x - 1]:" + to_string(in[x - 1]) + " in[x] : " + to_string(in[x]);
			//返回数据集
			for (int i = 1; i <= vertexNum; i++) {
				//处理路径
				road += vertex[(in[i])-1 ] + "-";
			}
			//接上起点
			road += vertex[0] + "\n";
		}

		return;
	}
	else
	{
		//本节点开始的所有元素
		for (int i = x; i <= vertexNum; i++) {
			//处理节点
			//上一节点与该节点有路径且路径更多
			if (tmp[in[x - 1]][in[i]] != 20000 && (len + tmp[in[x - 1]][in[i]]) < best) {
				
				len += tmp[in[x - 1]][in[i]];
				swap(in[x], in[i]);
				//进入递归
				backTracing(x+1);

				//回溯 ->撤销操作
				len -= tmp[in[x - 1]][in[x]];
				swap(in[x], in[i]);

				//in 和 x正常 ，g正常
				//road += "g数组:"+ to_string(g[in[x - 1]][in[x]])+"\n";
				//road += " in[x - 1]:" + to_string(in[x - 1]) +" in[x] : "+ to_string(in[x]);
				//road += "x:" + to_string(x) + " ";
				 
				//road += "len:" + to_string(len) + " best:" + to_string(best) + "\n";
			}
		}
	}	

}

//获取浏览路线 
string MGraph::getRoad()
{
	//处理
	
	backTracing(2);
	//返回数据集
	//每张图所有权值加起来不会超过20000
	if (best > 20000) {
		return "不存在这样一条路线";
	}
	else {
		return road;
	}
}


//获取顶点数组
string MGraph::getVertex()
{
	string pots;
	pots = "该图景点有:\n";
	int i = 0;
	for (i = 0; i < vertexNum; i++) {
		pots += vertex[i]+ " ";
	}
	return pots;
}


//获取边数组
string MGraph::getArc()
{
	string arcs;
	int i = 0, j = 0;
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			if (arc[i][j] != 20000) {
				//arcs+= "点"+(to_string(i)) + "-点" + (to_string(j)) + ":" + (to_string(arc[i][j])) + (" ");
				arcs +=   (to_string(arc[i][j])) + (" ");
			}
		}
		arcs+=("\n");
		
	}
	return arcs;
}

//获取path数组
string MGraph::getPath()
{
	string paths;
	int i = 0, j = 0;
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			paths += path[i][j] + " ";
		}
		paths += "\n";
	}
	return paths;
}

//获取Dist
string MGraph::getDist()
{
	string dists;
	int i = 0, j = 0;
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			dists += to_string(dist[i][j]) + " ";
		}
		dists += "\n";
	}
	return dists;
}

int MGraph::getVertexNum()
{
	return vertexNum;
}

//回溯递归需要借助一个数组来构建目标数组（真正要处理的）输出一下看一下是否正确构建
string MGraph::getTmp()
{
	string tmps;
	int i = 0, j = 0;
	for (i = 0; i <= vertexNum; i++) {
		for (j = 0; j <= vertexNum; j++) {
			if (tmp[i][j] != 20000) {
				tmps += to_string(tmp[i][j]) + " ";
			}
		}
		tmps += "\n";
	}
	return tmps;
}

//获取中间数组in
string MGraph::getIn()
{
	string ins;
	int i = 0, j = 0;
	for (i = 1; i <= vertexNum; i++) {
		ins += to_string(in[i]) + " ";
	}
	return ins;
}

//获取最短距离best
string MGraph::getBest()
{
	return to_string(best);
}

//测试时使用的输出某条路线的当前长度
string MGraph::getLen()
{
	return to_string(len);
}

//测试时使用的设置字符串
void MGraph::setString(string s)
{
	this->s = s;
}


//查找两个顶点间的最短路线，需要显示距离
string MGraph::ShortPath(string x,string y)
{
	string paths;
	int index1 = find(x);
	int index2 = find(y);

	if (index1>vertexNum || index1<0 || index2>vertexNum || index2 < 0) {
		return "景点名称有误";
	}
	else if (index1 == index2) {
		return vertex[index1] + "\n最短距离为：0";//返回本身
	}
	else if (dist[index1][index2] == 20000) {
		return "两景点不可达";
	}
	else{
		paths = path[index1][index2];
	}
	return paths +"\n最短距离为："+ to_string(dist[index1][index2]);
}
