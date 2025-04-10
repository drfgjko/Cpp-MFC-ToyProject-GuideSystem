#pragma once
#include "MyTools.h"
const int MaxSize = 30;

//�ڽӾ��� P180
class MGraph
{
//��Ա�����ͳ�Ա��������Ϊpublic�������
public:
	MGraph();//���캯��
	~MGraph();//��������
	int find(string s) const;//���ض���������±�
	void Floyd();//Ѱ���������·��
	void Change(int x);//��ȡ���txt����ͼ���������� xΪ��Ӧ��ͼ�ı��
	void backTracing(int x);//���û����㷨�ҵ��Ƽ�·��
	string getRoad();//��ȡ�Ƽ�·��->��������Żᴦ��g����
	string ShortPath(string x,string y);
	string getVertex();//��ȡ����
	string getArc();//��ȡ�߼�
	string getPath();//��ȡpath
	string getDist();//��ȡdist
	int getVertexNum();//��ȡdist
	string getTmp();//�����һ�������Ƿ���ȷ������
	//string getG();//�����һ�������Ƿ���ȷ������
	string getIn();//�����һ�������Ƿ���ȷ������
	string getBest();//�����һ�������Ƿ�����
	string getLen();//�����һ�������Ƿ�����

	void setString(string s);//����ǰ̨��ʾ�����������㷨�Ƿ�������
	string s;//����ǰ̨��ʾ�����������㷨�Ƿ�������

	MyTools *p;

	string vertex[MaxSize];//��������
	int arc[MaxSize][MaxSize];//�߼������Ȩֵ
	int vertexNum;//�������
	int arcNum;//����

	//����Floyd�����ɵ�����
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];

	//���ݲ���ʱʹ�õ��м�����,�����߹���·��

	int tmp[MaxSize][MaxSize];

	int in[MaxSize];

	//�Ƽ�·��
	string road;
	//���ڱȽ�
	//��Ӧ·�ߵľ���ֵ
	int len;
	//��С����ֵ
	int best;
};
