#pragma once
#include <afx.h>
#include <iostream>
#include <sstream>
#include <fstream>

//���һЩ����������������Ϊǰ��Ĵ�����
class MyTools
{
public:
	MyTools();
	~MyTools();
	int Pow(int x, int y);//��
	string Mysplit(string s);//��������Floyd�������ɵ�path�Ա�֤���������̾���ʱ��·���ﾰ�㲻���ظ�
	string Mysplit2(string s);//�ָ�����Roadȡ���һ��Ϊ�Ƽ�·��

	//int Num(int x);//�������
	//����MGraph��Ķ�������
	//int vertexNum;
	//void Change(int *x, int *y);//��������

};

