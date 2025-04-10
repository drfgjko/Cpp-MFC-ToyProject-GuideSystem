#include "pch.h"
#include "MGraph.h"

//���캯������ɳ�ʼ�����ļ���ȡ���������Ȩͼ
MGraph::MGraph()
{
	//��ʵ����Ϊ��Ҳ���ԣ���Ϊÿ��button�������change()

	vertexNum = 0, arcNum = 0;
	MyTools MyTools;//������
	p = &MyTools;
	string path = "map03.txt";//Ĭ��Ϊ�����ŵ�ͼ

	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "OPEN FILE FAILED" << endl;
	}

	//��ȡ�������
	int i = 0, j = 0;
	char s[5];
	inputFile.getline(s, 5);

	//ת����int
	while (s[i] != '\0') {
		i++;
	}
	int length = i;

	int x = length;//10��x�η�
	for (i = 0; i < length; i++) {
		int tmp = s[i] - '0';
		vertexNum += tmp * p->Pow(10, x - 1);
		x--;
	}

	//�������������������ҲҪ���ú�
	//p->vertexNum = vertexNum;
	
	////�Ե��ʼ��
	for (i = 0; i < vertexNum; i++) {
		vertex[i] = "";
	}

	//�Ա߳�ʼ��
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			arc[i][j] = 20000;//Ȩ�����ֵ
		}
	}

	//��ȡ����
	string str;
	getline(inputFile, str);
	stringstream ss(str);
	
	i = 0;
	//��֤����Ψһ
	string pot;
	while (ss >> pot) {
		if (find(pot) == -1) {
			vertex[i] = pot;
			i++;
		}

	}

	//��ȡ·��
	string s1, s2;
	int index1, index2, dist;
	while (inputFile >> s1 >> s2 >> dist) {
		index1 =find(s1);
		index2 =find(s2);

		//�鿴�Ƿ�������ȡ
		/*MyTools.setIndex1(index1);
		MyTools.setIndex2(dist);*/
		
		//����ͼ�Գ�
		arc[index1][index2] = dist;
		arc[index2][index1] = dist;

	}

	//�ر��ļ�
	inputFile.close();

	//����Floyd����path��dist���飬ΪѰ���������·��ʱʹ��
	Floyd();

	//��ʼ���м�����
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

//����Ϊ��
MGraph::~MGraph()
{
}

//���ض���������±� ->�����޸ģ�ֻ����� ->const
int MGraph::find(string s) const
{
	int i = 0;
	for (i = 0; i < vertexNum; i++) {
		if (s == vertex[i]) {
			return i;
		}
	}
	return -1;//û�ҵ�����-1

}

//�����鱾P200
//FLoyd����������·������
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

	//��ʼ������dist��path
	for (i = 0; i < vertexNum; i++)
	{
		for (j = 0; j < vertexNum; j++)
		{
			dist[i][j] = arc[i][j];
			if (dist[i][j] != 20000)//Ȩ�����ֵ
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

//��ȡ���txt����ͼ��
void MGraph::Change(int x)
{
	vertexNum = 0, arcNum = 0;

	//��ȡ��Ӧ·��
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
	case(4)://���ű������������˵ĳ������Ƚϼ�������Ƿ���ȷ��<-���Ը����˵�ͼһ����ʵ��ʹ��ʱ������4�ǲ���ʹ�õ�
		path = "map04.txt";
		break;
	}

	ifstream inputFile(path);
	if (!inputFile.is_open()) {
		cout << "OPEN FILE FAILED" << endl;
	}

	//�޸�����
	//��ȡ�������
	int i = 0, j = 0;
	char s[5];
	inputFile.getline(s, 5);

	//ת����int
	while (s[i] != '\0') {
		i++;
	}
	int length = i;

	int num = length;//10��x�η�
	for (i = 0; i < length; i++) {
		int tmp = s[i] - '0';
		vertexNum += tmp * p->Pow(10, num - 1);
		num--;
	}

	//�������������������ҲҪ���ú�
	//p->vertexNum = vertexNum;

	//�Ե��ʼ��
	for (i = 0; i < MaxSize; i++) {
		vertex[i] = "";
	}

	//�Ա߳�ʼ��
	for (i = 0; i < MaxSize; i++) {
		for (j = 0; j < MaxSize; j++) {
			arc[i][j] = 20000;//Ȩ�����ֵ
			tmp[i][j] = 20000;
		}
	}

	//��ȡ����
	string str;
	getline(inputFile, str);
	stringstream ss(str);

	i = 0;
	//��֤����Ψһ
	string pot;
	while (ss >> pot) {
		if (find(pot) == -1) {
			vertex[i] = pot;
			i++;
		}

	}

	//��ȡ·��
	string s1, s2;
	int index1, index2, dist;
	while (inputFile >> s1 >> s2 >> dist) {
		index1 = find(s1);
		index2 = find(s2);

		arc[index1][index2] = dist;
		arc[index2][index1] = dist;
	}

	//�ر��ļ�
	inputFile.close();

	//��������path��dist����
	Floyd();


	//��ʼ���м�����
	for (i = 0; i < MaxSize; i++) {
		in[i] = 0;
	}
	for (i = 1; i <= vertexNum; i++) {
		in[i] = i;
	}

	int k =0,t = 0;
	//tmp��������׹����
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

//�ݹ���������·�߼���̾���
void MGraph::backTracing(int x)
{
	//��ֹ���� ���������һ������
	if (x > vertexNum) {
		
		//arc[][]��=20000 ���һ������ص���һ��������·
		//��·���ܳ��ȼ������һ�Σ������һ������ص���һ������ľ��룬С��best
		if(tmp[in[x-1]][1] != 20000 && (len + tmp[in[x-1]][1] )<best) {
			best = len + tmp[in[x - 1]][1];
			//road += " in[x - 1]:" + to_string(in[x - 1]) + " in[x] : " + to_string(in[x]);
			//�������ݼ�
			for (int i = 1; i <= vertexNum; i++) {
				//����·��
				road += vertex[(in[i])-1 ] + "-";
			}
			//�������
			road += vertex[0] + "\n";
		}

		return;
	}
	else
	{
		//���ڵ㿪ʼ������Ԫ��
		for (int i = x; i <= vertexNum; i++) {
			//����ڵ�
			//��һ�ڵ���ýڵ���·����·������
			if (tmp[in[x - 1]][in[i]] != 20000 && (len + tmp[in[x - 1]][in[i]]) < best) {
				
				len += tmp[in[x - 1]][in[i]];
				swap(in[x], in[i]);
				//����ݹ�
				backTracing(x+1);

				//���� ->��������
				len -= tmp[in[x - 1]][in[x]];
				swap(in[x], in[i]);

				//in �� x���� ��g����
				//road += "g����:"+ to_string(g[in[x - 1]][in[x]])+"\n";
				//road += " in[x - 1]:" + to_string(in[x - 1]) +" in[x] : "+ to_string(in[x]);
				//road += "x:" + to_string(x) + " ";
				 
				//road += "len:" + to_string(len) + " best:" + to_string(best) + "\n";
			}
		}
	}	

}

//��ȡ���·�� 
string MGraph::getRoad()
{
	//����
	
	backTracing(2);
	//�������ݼ�
	//ÿ��ͼ����Ȩֵ���������ᳬ��20000
	if (best > 20000) {
		return "����������һ��·��";
	}
	else {
		return road;
	}
}


//��ȡ��������
string MGraph::getVertex()
{
	string pots;
	pots = "��ͼ������:\n";
	int i = 0;
	for (i = 0; i < vertexNum; i++) {
		pots += vertex[i]+ " ";
	}
	return pots;
}


//��ȡ������
string MGraph::getArc()
{
	string arcs;
	int i = 0, j = 0;
	for (i = 0; i < vertexNum; i++) {
		for (j = 0; j < vertexNum; j++) {
			if (arc[i][j] != 20000) {
				//arcs+= "��"+(to_string(i)) + "-��" + (to_string(j)) + ":" + (to_string(arc[i][j])) + (" ");
				arcs +=   (to_string(arc[i][j])) + (" ");
			}
		}
		arcs+=("\n");
		
	}
	return arcs;
}

//��ȡpath����
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

//��ȡDist
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

//���ݵݹ���Ҫ����һ������������Ŀ�����飨����Ҫ����ģ����һ�¿�һ���Ƿ���ȷ����
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

//��ȡ�м�����in
string MGraph::getIn()
{
	string ins;
	int i = 0, j = 0;
	for (i = 1; i <= vertexNum; i++) {
		ins += to_string(in[i]) + " ";
	}
	return ins;
}

//��ȡ��̾���best
string MGraph::getBest()
{
	return to_string(best);
}

//����ʱʹ�õ����ĳ��·�ߵĵ�ǰ����
string MGraph::getLen()
{
	return to_string(len);
}

//����ʱʹ�õ������ַ���
void MGraph::setString(string s)
{
	this->s = s;
}


//�����������������·�ߣ���Ҫ��ʾ����
string MGraph::ShortPath(string x,string y)
{
	string paths;
	int index1 = find(x);
	int index2 = find(y);

	if (index1>vertexNum || index1<0 || index2>vertexNum || index2 < 0) {
		return "������������";
	}
	else if (index1 == index2) {
		return vertex[index1] + "\n��̾���Ϊ��0";//���ر���
	}
	else if (dist[index1][index2] == 20000) {
		return "�����㲻�ɴ�";
	}
	else{
		paths = path[index1][index2];
	}
	return paths +"\n��̾���Ϊ��"+ to_string(dist[index1][index2]);
}
