#include "pch.h"
#include "MyTools.h"


MyTools::MyTools()
{
	//vertexNum = 0;
}


MyTools::~MyTools()
{
}

//��
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

//��"->"�ָ�s�������Կ�ͷ�ĵ�һ������
string MyTools::Mysplit(string s)
{
	int i = 0;
	char split = '-';
	istringstream iss(s);
	string str;//�ָ������
	string path;//Ҫ���ص�
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

//���ݻ��з��ָֻȡ���һ��
string MyTools::Mysplit2(string s)
{
	istringstream iss(s);
	//����Ҫ��һ��Ҫ�����������ֲ�ȷ���Ƿ���ʹ��vector,����������ֱ���������һ����
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
	//��ss��ȡ��Ч���ݡ�Ϊʲô��
	//����һ��j�����±�i�������ܽ�����⡢����

	return ss[j-1];


}
