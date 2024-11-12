#ifndef _GENERALALGORITHM_H
#define _GENERALALGORITHM_H
#include <iostream>
#include <cmath>
#include "gsharp.h"
using namespace std;
//输出最大的元素值
double FindMax(double *elem, int N);
//输出最小的元素值
double FindMin(double *elem, int N);

//排序
void SortMintoMax(double suitable_x[], int n);
//------------------求解方程的k,b值---------------------//
void Functionline(double x1, double y1, double x2, double y2, double &k, double &b);
//编码判断
int Encode(int x, int y, Rectangle *rect);
//求2点之间的距离
inline int Distance(QPointF p1, QPointF p2) { return  sqrt((p2.y() - p1.y())*(p2.y() - p1.y()) + (p2.x() - p1.x())*(p2.x() - p1.x())); }
#endif