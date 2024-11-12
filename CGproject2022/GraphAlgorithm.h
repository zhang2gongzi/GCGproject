/**
* GraphAlgorithm.h
* Computer graphics algorithms
* 2022 v1
*/
#ifndef _GRAPHALGORITHM_H
#define _GRAPHALGORITHM_H
#include <QPainter>
#include "gsharp.h"

#include <queue>
#include <map>
//////�ӿں���
/////////---------ֱ�ߵĻ���----------------///
void DDA(QImage *image, QPointF bp, QPointF ep, QRgb value);
void MidF(QImage *image, QPointF bp, QPointF ep, QRgb value);
void Mid(QImage *image, int x1, int y1, int x2, int y2, QRgb value);
void Bresenham(QImage *image, QPointF bp, QPointF ep, QRgb value);
/////////---------Բ�Ļ���----------------///
void MidCircle(QImage *image, QPointF cp, int r, QRgb value);
void BresenhamCircle(QImage *image, QPointF cp, int r, QRgb value);
void CirclePlot(QImage *image, int xc, int yc, int x, int y, QRgb value);
/////////---------��Բ�Ļ���----------------///
void MidEll(QImage *image, QPointF cp, int a, int b, QRgb value);
void EllipsePlot(QImage *image, int xc, int yc, int x, int y, QRgb value);
/////////---------������----------------///
void WuPlot(QImage *image, QPointF bp, QPointF ep, QRgb value);
/////////1---------ɨ�������----------------///
//-------------------�ҳ�ɨ������߽��ཻ�ĵ㣬��������suitable_x�У����ཻ�ĵ���������n��--------------//
//x-----------����x����
//y-----------����y����
//N-------------����ĸ���
//now_y---------��ǰ��ɨ����y
//suitable_x[]--ɨ������߽��ཻ�ĵ��x����
//n-------------�ཻ�ĵ���
void SuitableX(double *x, double *y, int N, double now_y, double *suitable_x, int &n);
//------------------����ֱ�ߵ�y----------------------//
inline double SolveY(double k, double b, double x)
{
	return k * x + b;
}
//------------------����ֱ�ߵ�x----------------------//
inline double SolveX(double k, double b, double y)
{
	if (k == -9999)
		return b;
	return (y - b) / k;
}
void ScanLineFill(QImage *image, QPointF *point, QRgb value, int mlength);
/////////2---------��Ч�߱����----------------///
void EdgeFill(QImage *image, QPointF *point);
///////////
////////////////////////3---------�������----------------///
inline int get_pixel_index(QPointF a) { return a.y() * 400 + a.x(); }
void RegionFill(QImage *image, QRgb value);
/////////---------����εĻ���----------------///
void DrawTriangle(QImage *image, QPointF *point, QRgb value, int mlength);
void Trans(QImage *image, QPointF *point, QRgb value, int mlength);
void Rot(QImage *image, QPointF *point, QRgb value, int mlength);
void Scale(QImage *image, QPointF *point, QRgb value, int mlength);
/////////---------�ü�----------------///
void CohenSutherlandClip(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value);
void Draw(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value);
QPointF findIntersection(QPointF p1, QPointF p2, Rectangle *rect);
void MidPointClip(Rectangle *rect, int x1, int y1, int x2, int y2);
int LBLineClipTest(float p, float q, float& umax, float& umin);
void LBLineClip(QImage *image, Rectangle *rect, float x1, float y1, float x2, float y2, QRgb value);
/////////---------��������----------------///
void drawbz2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value,double delta_t);
void drawbz3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value,double delta_t);
void drawBSpline2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value,double delta_t);
void drawBSpline3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value, double delta_t);
#endif
