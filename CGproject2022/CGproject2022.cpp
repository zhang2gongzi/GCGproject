#include "CGproject2022.h"
#include "GraphAlgorithm.h"
CGproject2022::CGproject2022(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setMaximumSize(QSize(800, 600));
	connect(ui.actionDDALine, SIGNAL(triggered()), this, SLOT(DDALine()));
	connect(ui.actionMidLine, SIGNAL(triggered()), this, SLOT(MidLine()));
	connect(ui.actionBresenhamLine, SIGNAL(triggered()), this, SLOT(BresenhamLine()));
	connect(ui.actionMidCir, SIGNAL(triggered()), this, SLOT(MidCir()));
	connect(ui.actionBresenhamCir, SIGNAL(triggered()), this, SLOT(BresenhamCir()));
	connect(ui.actionMidEllipse, SIGNAL(triggered()), this, SLOT(MidEllipse()));
	connect(ui.actionWu, SIGNAL(triggered()), this, SLOT(Wu()));
	connect(ui.actionScanLine, SIGNAL(triggered()), this, SLOT(FillScanLine()));
	connect(ui.actionEdgeFill, SIGNAL(triggered()), this, SLOT(FillEdge()));
	connect(ui.actionFloodFill, SIGNAL(triggered()), this, SLOT(Flood()));
	connect(ui.actionDraw, SIGNAL(triggered()), this, SLOT(DrawGraph()));
	connect(ui.actionTranslation, SIGNAL(triggered()), this, SLOT(Translation()));
	connect(ui.actionRotate, SIGNAL(triggered()), this, SLOT(Rotate()));
	connect(ui.actionZoom, SIGNAL(triggered()), this, SLOT(Zoom()));
	connect(ui.actionCohen_Sutherland, SIGNAL(triggered()), this, SLOT(CSClip()));
	connect(ui.actionMidLineClipping, SIGNAL(triggered()), this, SLOT(MidClip()));
	connect(ui.actionBarskey, SIGNAL(triggered()), this, SLOT(BarskeyClip()));
	connect(ui.actionSecondOrderBezier, SIGNAL(triggered()), this, SLOT(DrawBezier2()));
	connect(ui.actionThirdOrderBezier, SIGNAL(triggered()), this, SLOT(DrawBezier3()));
	connect(ui.actionSecondOrderBSpline, SIGNAL(triggered()), this, SLOT(DrawBSpline2()));
	connect(ui.actionThirdOrderBSpline, SIGNAL(triggered()), this, SLOT(DrawBSpline3()));
	initialize();
}
void CGproject2022::initialize()
{
	mBeginPoint = QPointF(0, 0);
	mEndPoint = QPointF(0, 0);
	mCentPoint = QPointF(0, 0);
	mPoint[0] = QPointF(0, 0);
	mPoint[1] = QPointF(0, 0);
	mPoint[2] = QPointF(0, 0);
	mPoint[3] = QPointF(0, 0);
	mPoint[4] = QPointF(0, 0);
	mPoint[5] = QPointF(0, 0);
	mPoint[6] = QPointF(0, 0);
	mPoint[7] = QPointF(0, 0);
	mPoint[8] = QPointF(0, 0);
	ptwo[0] = QPointF(50, 300);
	ptwo[1] = QPointF(350, 50);
	ptwo[2] = QPointF(500, 350);
	pthree[0] = QPointF(500, 300);
	pthree[1] = QPointF(200, 100);
	pthree[2] = QPointF(350, 100);
	pthree[3] = QPointF(500, 350);
	state = 0;
	rect.xmin = 200;
	rect.ymin = 200;
	rect.xmax = 400;
	rect.ymax = 400;
}
void CGproject2022::paintEvent(QPaintEvent*)
//The paintevent function is automatically called by the system, so we don't need to call it manually.
{
	QImage image(800, 600, QImage::Format_RGB32);
	paint = new QPainter;
	paint->begin(this);
	switch (state)
	{
	case DDALINE_DRAW:
		DDA(&image, mBeginPoint, mEndPoint, qRgb(255, 0, 0));
		break;
	case MIDLINE_DRAW:
		MidF(&image, mBeginPoint, mEndPoint, qRgb(0, 255, 0));
		break;
	case BRESENHAMLINE_DRAW:
		Bresenham(&image, mBeginPoint, mEndPoint, qRgb(0, 0, 255));
		break;
	case MIDCIR_DRAW:
		MidCircle(&image, mCentPoint, 50, qRgb(204, 255, 255));
		break;
	case BRESENHAMCIR_DRAW:
		BresenhamCircle(&image, mCentPoint, 50, qRgb(0, 255, 255));
		break;
	case MIDELLIPSE_DRAW:
		MidEll(&image, mCentPoint, 50, 30, qRgb(255, 0, 0));
		break;
	case WU_DRAW:
		WuPlot(&image, mBeginPoint, mEndPoint, qRgb(0, 255, 255));
		break;
	case FILLSCANLINE_DRAW:
		ScanLineFill(&image, mPoint, qRgb(0, 255, 255),9);
		break;
	case FILLEDGE_DRAW:
		EdgeFill(&image, mPoint);
		break;
	case FLOODFILL_DRAW:
		RegionFill(&image, qRgb(0, 255, 255));
		break;
	case DRAW_GRAPHICAL:
		DrawTriangle(&image, mPoint, qRgb(0, 255, 255),3);
		break;
	case TRANSLATION:
		Trans(&image, mPoint, qRgb(0, 255, 255),3);
		break;
	case ROTATE:
		Rot(&image, mPoint, qRgb(0, 255, 255),3);
		break;
	case ZOOM:
		Scale(&image, mPoint, qRgb(0, 255, 255), 3);
		break;
	case CS_LINECLIP:
		CohenSutherlandClip(&image, &rect, 50, 50, 480, 450, qRgb(0, 255, 255));
		break;
	case MID_LINECLIP:
		Draw(&image, &rect, 50, 50, 480, 450, qRgb(0, 0, 255));
		break;
	case BARSKEY_LINECLIP:
		LBLineClip(&image, &rect, 50, 50, 480, 450, qRgb(0, 0, 255));
		break;
	case SECONDORDERBEZIER:
		Mid(&image, ptwo[0].x(), ptwo[0].y(), ptwo[1].x(), ptwo[1].y(), qRgb(255, 0, 0));
		Mid(&image, ptwo[1].x(), ptwo[1].y(), ptwo[2].x(), ptwo[2].y(), qRgb(255, 0, 0));
		drawbz2(&image, ptwo[0], ptwo[1], ptwo[2], qRgb(255, 0, 0),0.0001);
		break;
	case THIEDORDERBEZIER:
		Mid(&image, pthree[0].x(), pthree[0].y(), pthree[1].x(), pthree[1].y(), qRgb(255, 0, 0));
		Mid(&image, pthree[1].x(), pthree[1].y(), pthree[2].x(), pthree[2].y(), qRgb(255, 0, 0));
		Mid(&image, pthree[2].x(), pthree[2].y(), pthree[3].x(), pthree[3].y(), qRgb(255, 0, 0));
		drawbz3(&image, pthree[0], pthree[1], pthree[2], pthree[3],qRgb(255, 0, 0), 0.0001);
		break;
	case SECONDORDERBSPLINE:
		Mid(&image, ptwo[0].x(), ptwo[0].y(), ptwo[1].x(), ptwo[1].y(), qRgb(255, 0, 0));
		Mid(&image, ptwo[1].x(), ptwo[1].y(), ptwo[2].x(), ptwo[2].y(), qRgb(255, 0, 0));
		drawBSpline2(&image, ptwo[0], ptwo[1], ptwo[2], qRgb(255, 0, 0), 0.0001);
		break;
	case THIEDORDERBSPLINE:
		Mid(&image, pthree[0].x(), pthree[0].y(), pthree[1].x(), pthree[1].y(), qRgb(255, 0, 0));
		Mid(&image, pthree[1].x(), pthree[1].y(), pthree[2].x(), pthree[2].y(), qRgb(255, 0, 0));
		Mid(&image, pthree[2].x(), pthree[2].y(), pthree[3].x(), pthree[3].y(), qRgb(255, 0, 0));
		drawBSpline3(&image, pthree[0], pthree[1], pthree[2], pthree[3], qRgb(255, 0, 0), 0.0001);
	default:
		break;
	}
	paint->drawImage(0, 0, image);
	paint->end();
}
///DDA方法绘制直线
void CGproject2022::DDALine()
{
	state = DDALINE_DRAW;
	mBeginPoint = QPointF(120, 120);
	mEndPoint = QPointF(300, 150);
	repaint();
}
void CGproject2022::MidLine()
{
	state = MIDLINE_DRAW;
	mBeginPoint = QPointF(120, 120);
	mEndPoint = QPointF(300, 150);
	repaint();
}
void CGproject2022::BresenhamLine()
{
	state = BRESENHAMLINE_DRAW;
	mBeginPoint = QPointF(120, 120);
	mEndPoint = QPointF(300, 150);
	repaint();
}
void CGproject2022::MidCir()
{
	state = MIDCIR_DRAW;
	mCentPoint = QPointF(200, 200);
	repaint();
}
void CGproject2022::BresenhamCir()
{
	state = BRESENHAMCIR_DRAW;
	mCentPoint = QPointF(200, 200);
	repaint();
}
void CGproject2022::MidEllipse()
{
	state = MIDELLIPSE_DRAW;
	mCentPoint = QPointF(200, 200);
	repaint();
}
void CGproject2022::Wu()
{
	state = WU_DRAW;
	mBeginPoint = QPointF(120, 120);
	mEndPoint = QPointF(300, 150);
	repaint();
}
void CGproject2022::FillScanLine()
{
	state = FILLSCANLINE_DRAW;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::FillEdge()
{
	state = FILLEDGE_DRAW;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::Flood()
{
	state = FLOODFILL_DRAW;
	repaint();
}
void CGproject2022::DrawGraph()
{
	state = DRAW_GRAPHICAL;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::Translation()
{
	state = TRANSLATION;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::Rotate()
{
	state = ROTATE;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::Zoom()
{
	state = ZOOM;
	mPoint[0] = QPointF(200, 200);
	mPoint[1] = QPointF(100, 300);
	mPoint[2] = QPointF(150, 400);
	mPoint[3] = QPointF(170, 250);
	mPoint[4] = QPointF(400, 350);
	mPoint[5] = QPointF(350, 300);
	mPoint[6] = QPointF(300, 250);
	mPoint[7] = QPointF(250, 100);
	mPoint[8] = QPointF(270, 270);
	repaint();
}
void CGproject2022::CSClip()
{
	state = CS_LINECLIP;
	repaint();
}
void CGproject2022::MidClip()
{
	state = MID_LINECLIP;
	repaint();
}
void CGproject2022::BarskeyClip()
{
	state = BARSKEY_LINECLIP;
	repaint();
}
void CGproject2022::DrawBezier2()
{
	state = SECONDORDERBEZIER;
	ptwo[0] = QPointF(50, 300);
	ptwo[1] = QPointF(350, 50);
	ptwo[2] = QPointF(500, 350);
	repaint();
}
void CGproject2022::DrawBezier3()
{
	state = THIEDORDERBEZIER;
	pthree[0] = QPointF(50, 300);
	pthree[1] = QPointF(200, 100);
	pthree[2] = QPointF(350, 100);
	pthree[3] = QPointF(500, 350);
	repaint();
}
void CGproject2022::DrawBSpline2()
{
	state = SECONDORDERBSPLINE;
	ptwo[0] = QPointF(50, 300);
	ptwo[1] = QPointF(350, 50);
	ptwo[2] = QPointF(500, 350);
	repaint();
}
void CGproject2022::DrawBSpline3()
{
	state = THIEDORDERBSPLINE;
	pthree[0] = QPointF(50, 300);
	pthree[1] = QPointF(200, 100);
	pthree[2] = QPointF(350, 100);
	pthree[3] = QPointF(500, 350);
	repaint();
}