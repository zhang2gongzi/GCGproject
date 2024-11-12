#ifndef _GENERALALGORITHM_H
#define _GENERALALGORITHM_H
#include <iostream>
#include <cmath>
#include "gsharp.h"
using namespace std;
//�������Ԫ��ֵ
double FindMax(double *elem, int N);
//�����С��Ԫ��ֵ
double FindMin(double *elem, int N);

//����
void SortMintoMax(double suitable_x[], int n);
//------------------��ⷽ�̵�k,bֵ---------------------//
void Functionline(double x1, double y1, double x2, double y2, double &k, double &b);
//�����ж�
int Encode(int x, int y, Rectangle *rect);
//��2��֮��ľ���
inline int Distance(QPointF p1, QPointF p2) { return  sqrt((p2.y() - p1.y())*(p2.y() - p1.y()) + (p2.x() - p1.x())*(p2.x() - p1.x())); }
#endif