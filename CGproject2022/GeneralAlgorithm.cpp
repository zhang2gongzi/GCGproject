#include "GeneralAlgorithm.h"
double FindMax(double *elem, int N) //输出最大的元素值
{
	double max = elem[0];
	for (int i = 0; i < N; i++)
	{
		if (elem[i] > max)
		{
			max = elem[i];
		}
	}
	return max;
}
double FindMin(double *elem, int N) //输出最小的元素值
{
	double min = elem[0];
	for (int i = 0; i < N; i++)
	{
		if (elem[i] < min)
		{
			min = elem[i];
		}
	}
	return min;
}
void SortMintoMax(double suitable_x[], int n) //排序----从小到大排序
{
	double temp;	for (int i = 0; i < n - 1; i++)

	{
		for (int j = i + 1; j < n; j++) {
			if (suitable_x[i] > suitable_x[j]) {
				double temp = suitable_x[i];
				suitable_x[i] = suitable_x[j];
				suitable_x[j] = temp;
			}
		}
	}
}
void Functionline(double x1, double y1, double x2, double y2, double &k, double &b)
{
	if (x2 - x1 == 0) {
		k = -9999;
		b = x1;
		return;
	}
	k = (y2 - y1) / (x2 - x1);
	b = y1 - k * x1;
}
int Encode(int x, int y, Rectangle *rect)
{
	int code = 0x0;

	if (x < rect->xmin)
		code = code | 0x1;
	if (x > rect->xmax)
		code = code | 0x2;
	if (y < rect->ymin)
		code = code | 0x4;
	if (y > rect->ymax)
		code = code | 0x8;

	return code;
}