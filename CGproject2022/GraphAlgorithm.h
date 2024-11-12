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
//////接口函数
/////////---------直线的绘制----------------///
void DDA(QImage *image, QPointF bp, QPointF ep, QRgb value);
void MidF(QImage *image, QPointF bp, QPointF ep, QRgb value);
void Mid(QImage *image, int x1, int y1, int x2, int y2, QRgb value);
void Bresenham(QImage *image, QPointF bp, QPointF ep, QRgb value);
/////////---------圆的绘制----------------///
void MidCircle(QImage *image, QPointF cp, int r, QRgb value);
void BresenhamCircle(QImage *image, QPointF cp, int r, QRgb value);
void CirclePlot(QImage *image, int xc, int yc, int x, int y, QRgb value);
/////////---------椭圆的绘制----------------///
void MidEll(QImage *image, QPointF cp, int a, int b, QRgb value);
void EllipsePlot(QImage *image, int xc, int yc, int x, int y, QRgb value);
/////////---------反走样----------------///
void WuPlot(QImage *image, QPointF bp, QPointF ep, QRgb value);
/////////1---------扫描线填充----------------///
//-------------------找出扫描线与边界相交的点，并储存在suitable_x中，把相交的点数储存在n中--------------//
//x-----------顶点x坐标
//y-----------顶点y坐标
//N-------------顶点的个数
//now_y---------当前的扫描线y
//suitable_x[]--扫描线与边界相交的点的x坐标
//n-------------相交的点数
void SuitableX(double *x, double *y, int N, double now_y, double *suitable_x, int &n);
//------------------返回直线的y----------------------//
inline double SolveY(double k, double b, double x)
{
	return k * x + b;
}
//------------------返回直线的x----------------------//
inline double SolveX(double k, double b, double y)
{
	if (k == -9999)
		return b;
	return (y - b) / k;
}
void ScanLineFill(QImage *image, QPointF *point, QRgb value, int mlength);
/////////2---------有效边表填充----------------///
void EdgeFill(QImage *image, QPointF *point);
///////////
////////////////////////3---------种子填充----------------///
inline int get_pixel_index(QPointF a) { return a.y() * 400 + a.x(); }
void RegionFill(QImage *image, QRgb value);
/////////---------多边形的绘制----------------///
void DrawTriangle(QImage *image, QPointF *point, QRgb value, int mlength);
void Trans(QImage *image, QPointF *point, QRgb value, int mlength);
void Rot(QImage *image, QPointF *point, QRgb value, int mlength);
void Scale(QImage *image, QPointF *point, QRgb value, int mlength);
/////////---------裁剪----------------///
void CohenSutherlandClip(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value);
void Draw(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value);
QPointF findIntersection(QPointF p1, QPointF p2, Rectangle *rect);
void MidPointClip(Rectangle *rect, int x1, int y1, int x2, int y2);
int LBLineClipTest(float p, float q, float& umax, float& umin);
void LBLineClip(QImage *image, Rectangle *rect, float x1, float y1, float x2, float y2, QRgb value);
/////////---------自由曲线----------------///
void drawbz2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value,double delta_t);
void drawbz3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value,double delta_t);
void drawBSpline2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value,double delta_t);
void drawBSpline3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value, double delta_t);
#endif
