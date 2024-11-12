#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CGproject2022.h"
#include <QPainter>
#include "gsharp.h"
enum DrawType
{
	NODRAW,
	DDALINE_DRAW,
	MIDLINE_DRAW,
	BRESENHAMLINE_DRAW,
	MIDCIR_DRAW,
	MIDELLIPSE_DRAW,
	BRESENHAMCIR_DRAW,
	WU_DRAW,
	FILLSCANLINE_DRAW,
	FILLEDGE_DRAW,
	FLOODFILL_DRAW,
	DRAW_GRAPHICAL,
	TRANSLATION,
	ROTATE,
	ZOOM,
	CS_LINECLIP,
	MID_LINECLIP,
	BARSKEY_LINECLIP,
	SECONDORDERBEZIER,
	THIEDORDERBEZIER,
	SECONDORDERBSPLINE,
	THIEDORDERBSPLINE
};
class CGproject2022 : public QMainWindow
{
    Q_OBJECT

public:
    CGproject2022(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent*);
private:
    Ui::CGproject2022Class ui;
	void initialize();
	QPainter *paint;
	QPointF mBeginPoint, mEndPoint, mCentPoint;
	QPointF mPoint[10];
	QPointF ptwo[3],pthree[4];
	Rectangle rect;
	int state;
public slots:
	void DDALine();//DDA算法绘制直线
	void MidLine();//中点算法绘制直线
	void BresenhamLine();//Bresenham算法绘制直线
	void MidCir();//中点算法绘制圆
	void BresenhamCir();//Bresenham算法绘制圆
	void MidEllipse();//中点算法绘制椭圆
	void Wu();//Wu算法反走样
	void FillScanLine();//扫描线填充算法
	void FillEdge();//边表填充算法
	void Flood();//种子填充算法
	void DrawGraph();//绘制多边形
	void Translation();//平移
	void Rotate();//旋转
	void Zoom();//缩放
	void CSClip();//CohenSutherland方法裁剪
	void MidClip();//中点方法裁剪
	void BarskeyClip();//Barskey方法裁剪
	void DrawBezier2();//二次贝塞尔曲线
	void DrawBezier3();//三次贝塞尔曲线
	void DrawBSpline2();//二次B样条曲线
	void DrawBSpline3();//三次B样条曲线
};
