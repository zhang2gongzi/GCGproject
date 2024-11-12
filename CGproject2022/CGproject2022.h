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
	void DDALine();//DDA�㷨����ֱ��
	void MidLine();//�е��㷨����ֱ��
	void BresenhamLine();//Bresenham�㷨����ֱ��
	void MidCir();//�е��㷨����Բ
	void BresenhamCir();//Bresenham�㷨����Բ
	void MidEllipse();//�е��㷨������Բ
	void Wu();//Wu�㷨������
	void FillScanLine();//ɨ��������㷨
	void FillEdge();//�߱�����㷨
	void Flood();//��������㷨
	void DrawGraph();//���ƶ����
	void Translation();//ƽ��
	void Rotate();//��ת
	void Zoom();//����
	void CSClip();//CohenSutherland�����ü�
	void MidClip();//�е㷽���ü�
	void BarskeyClip();//Barskey�����ü�
	void DrawBezier2();//���α���������
	void DrawBezier3();//���α���������
	void DrawBSpline2();//����B��������
	void DrawBSpline3();//����B��������
};
