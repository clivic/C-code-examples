//*******************************************************************************************************
// test for reference of function return value.cpp : Defines the entry point for the console application.
// this program is to test the reference of function value. The code is not written by my self but 
// referenced from an article.
//*******************************************************************************************************

#include "stdafx.h"
#include <iostream>

using namespace std;

float temp;				//����ȫ�ֱ���temp (ԭ��������)
float fn1(float r);		//��������fn1
float &fn2(float r);	//��������fn2

//*******************************************************************************************************

float fn1(float r)		//���庯��fn1�����Է���ֵ�ķ������غ���ֵ
{
  temp=(float)(r*r*3.14);
  return temp;
}

float &fn2(float r)		//���庯��fn2���������÷�ʽ���غ���ֵ
{
  temp=(float)(r*r*3.14);
  return temp;
}

void main(int argc, 
		  char* argv[])	//������
{
  float a=fn1(10.0);	//��1�������ϵͳ����Ҫ����ֵ�ĸ���������ʱ������
  //float &b=fn1(10.0);	//��2����������ܻ������ͬ C++ϵͳ�в�ͬ�涨���@�e�ͳ����}��
  //���ܴӱ��������з���һ����ʱ������ֲ�����������
  float c=fn2(10.0);	//��3�������ϵͳ�����ɷ���ֵ�ĸ���
  //���Դӱ��������з���һ��ȫ�ֱ���������
  float &d=fn2(10.0);	//��4�������ϵͳ�����ɷ���ֵ�ĸ���
  //���Դӱ��������з���һ��ȫ�ֱ���������
  cout << a << c << d;
}


