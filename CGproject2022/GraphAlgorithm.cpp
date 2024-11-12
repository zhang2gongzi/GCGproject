#include "GraphAlgorithm.h"
#include "GeneralAlgorithm.h"
#include "Fill.h"
#include "GMatrix.h"
map<int, bool> is_edge;
map<int, bool> visited;
#include <vector>
using std::vector;
vector<QPointF> vector1;
vector<QPointF> vector2;
void DDA(QImage *image, QPointF bp, QPointF ep, QRgb value)
{
	float dx, dy, x, y, k1, k2;
	float x1,y1,x2,y2;
	if (bp.x() > ep.x())
	{
		x1 = ep.x();
		x2 = bp.x();
		y1 = ep.y();
		y2 = bp.y();
	}
	else
	{
		x1 = bp.x();
		x2 = ep.x();
		y1 = bp.y();
		y2 = ep.y();
	}
	dx = x2 - x1;	dy = y2 - y1;
	x = x1;	y = y1;
	if (dx == 0)
		if (y1 < y2)
			for (int y0 = y1; y0 <= y2; y0++)
				image->setPixel(x1, y0, value);
		else
			for (int y0 = y2; y0 <= y1; y0++)
				image->setPixel(x1, y0, value);
	else if (dy == 0)
		for (int x0 = x1; x0 <= x2; x0++)
			image->setPixel(x0, y1, value);
	else if (abs(dx) > abs(dy))
	{
		k1 = dy / dx;
		for (int x0 = x1; x0 <= x2; x0++)
		{
			image->setPixel(x0, int(y + 0.5), value);
			y = y + k1;
		}
	}
	else
	{
		k2 = dx / dy;
		if (y1 < y2)
			for (int y0 = y1; y0 <= y2; y0++)
			{
				image->setPixel(int(x + 0.5), y0, value);
				x = x + k2;
			}
		else
		{
			x = x2;
			for (int y0 = y2; y0 <= y1; y0++)
			{
				image->setPixel(int(x + 0.5), y0, value);
				x = x + k2;
			}
		}
	}
}
void MidF(QImage *image, QPointF bp, QPointF ep, QRgb value)
{
	float dx, dy;
	float x1, y1, x2, y2;
	if (bp.x() > ep.x())
	{
		x1 = ep.x();
		x2 = bp.x();
		y1 = ep.y();
		y2 = bp.y();
	}
	else
	{
		x1 = bp.x();
		x2 = ep.x();
		y1 = bp.y();
		y2 = ep.y();
	}
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0)
	{
		if (y1 < y2)
			for (float y = y1; y <= y2; y++)
				image->setPixel(x1, y, value);
		else
			for (float y = y2; y <= y1; y++)
				image->setPixel(x1, y, value);
	}
	else if (dy == 0)
		for (float x = x1; x <= x2; x++)
			image->setPixel(x, y1, value);
	else
	{
		float a, b, d1, d2, d, x, y, c;
		a = y1 - y2;
		b = x2 - x1;
		float k = dy / dx;
		x = x1;
		y = y1;
		image->setPixel(x, y, value);
		if (k > 0 && k <= 1)
		{
			d = a + 0.5 * b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					y++;
					d += a + b;
				}
				else
				{
					x++;
					d += a;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k >= -1 && k < 0)
		{
			d = a - 0.5 * b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					d += a;
				}
				else
				{
					x++;
					y--;
					d += a - b;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k > 1)
		{
			d = a * 0.5 + b;
			while (x < x2)
			{
				if (d < 0)
				{
					y++;
					d += b;
				}
				else
				{
					x++, y++;
					d += a + b;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k < -1)
		{
			d = a * 0.5 - b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					y--;
					d += a - b;
				}
				else
				{
					y--;
					d += -b;
				}
				image->setPixel(x, y, value);
			}
		}
	}
}
void Mid(QImage *image, int x1, int y1, int x2, int y2, QRgb value)
{
	float dx, dy;
	if (x1 > x2)std::swap(x1, x2), std::swap(y1, y2);
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0)
	{
		if (y1 < y2)
			for (float y = y1; y <= y2; y++)
				image->setPixel(x1, y, value);
		else
			for (float y = y2; y <= y1; y++)
				image->setPixel(x1, y, value);
	}
	else if (dy == 0)
		for (float x = x1; x <= x2; x++)
			image->setPixel(x, y1, value);
	else
	{
		float a, b, d1, d2, d, x, y, c;
		a = y1 - y2;
		b = x2 - x1;
		float k = dy / dx;
		x = x1;
		y = y1;
		image->setPixel(x, y, value);
		if (k > 0 && k <= 1)
		{
			d = a + 0.5 * b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					y++;
					d += a + b;
				}
				else
				{
					x++;
					d += a;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k >= -1 && k < 0)
		{
			d = a - 0.5 * b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					d += a;
				}
				else
				{
					x++;
					y--;
					d += a - b;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k > 1)
		{
			d = a * 0.5 + b;
			while (x < x2)
			{
				if (d < 0)
				{
					y++;
					d += b;
				}
				else
				{
					x++, y++;
					d += a + b;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k < -1)
		{
			d = a * 0.5 - b;
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					y--;
					d += a - b;
				}
				else
				{
					y--;
					d += -b;
				}
				image->setPixel(x, y, value);
			}
		}
	}

}
void Bresenham(QImage *image, QPointF bp, QPointF ep, QRgb value)
{
	double x0, x1, y0, y1;
	x0 = ep.x();
	x1 = bp.x();
	y0 = ep.y();
	y1 = bp.y();
	int deltaX;
	int deltaY;
	double k;

	int d0 = 0;
	int d;
	int x;
	int y;

	if (x0 > x1)
	{
		int temp;
		temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	deltaX = x1 - x0;
	deltaY = y1 - y0;
	k = (1.0 * deltaY) / (1.0 * deltaX);

	if (deltaX == 0)
	{
		if (y0 > y1)
		{
			int temp = y0;
			y0 = y1;
			y1 = temp;
		}
		for (int y = y0; y <= y1; y++)
		{
			image->setPixel(x0, y, value);
		}
	}
	else
	{
		if (k == 0)
		{
			for (int x = x0; x <= x1; x++)
			{
				image->setPixel(x, y0, value);
			}
		}
		else if (0 < k && k <= 1)
		{
			d0 = deltaX - 2 * deltaY;
			d = d0;
			x = x0;
			y = y0;

			image->setPixel(x0, y0, value);
			for (int x = x0 + 1; x <= x1; x++)
			{
				if (d >= 0)
				{
					d = d - 2 * deltaY;
				}
				else
				{
					y++;
					d = d + 2 * deltaX - 2 * deltaY;
				}
				image->setPixel(x, y, value);
			}

		}
		else if (k > 1.0)
		{
			d0 = 2 * deltaX - deltaY;
			d = d0;
			x = x0;
			y = y0;

			image->setPixel(x0, y0, value);
			for (int y = y0 + 1; y <= y1; y++)
			{
				if (d >= 0)
				{
					x++;
					d = d + 2 * deltaX - 2 * deltaY;
				}
				else
				{
					d = d + 2 * deltaX;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (-1.0 <= k && k < 0.0)
		{
			d0 = -1 * deltaX - 2 * deltaY;
			d = d0;
			x = x0;
			y = y0;

			image->setPixel(x0, y0, value);
			for (int x = x0 + 1; x <= x1; x++)
			{
				if (d >= 0)
				{
					y--;
					d = d - 2 * deltaX - 2 * deltaY;
				}
				else
				{
					d = d - 2 * deltaY;
				}
				image->setPixel(x, y, value);
			}
		}
		else if (k < -1.0)
		{
			d0 = -2 * deltaX - deltaY;
			d = d0;
			x = x0;
			y = y0;

			image->setPixel(x0, y0, value);
			for (int y = y0 - 1; y >= y1; y--)
			{
				if (d > 0)
				{
					d = d - 2 * deltaX;
				}
				else
				{
					x++;
					d = d - 2 * deltaX - 2 * deltaY;
				}
				image->setPixel(x, y, value);
			}
		}
	}
}
void CirclePlot(QImage *image, int xc, int yc, int x, int y, QRgb value)
{
	image->setPixel(xc + x, yc + y, value);
	image->setPixel(xc - x, yc + y, value);
	image->setPixel(xc + x, yc - y, value);
	image->setPixel(xc - x, yc - y, value);
	image->setPixel(xc + y, yc + x, value);
	image->setPixel(xc - y, yc + x, value);
	image->setPixel(xc + y, yc - x, value);
	image->setPixel(xc - y, yc - x, value);
}
void MidCircle(QImage *image, QPointF cp, int r, QRgb value)
{
	double xc, yc;
	xc = cp.x();
	yc = cp.y();
	double x, y, e;
	x = 0; y = r; e = 1 - r;
	CirclePlot(image, xc, yc, x, y, value);
	while (x <= y)
	{
		if (e < 0)
			e += 2 * x + 3;
		else
		{
			e += 2 * (x - y) + 5;
			y--;
		}
		x++;
		CirclePlot(image, xc, yc, x, y, value);
	}
}
void BresenhamCircle(QImage *image, QPointF cp, int r, QRgb value)
{
	double xc, yc;
	xc = cp.x();
	yc = cp.y();
	double x = 0, y = r, yi, d;
	d = 3 - 2 * r;
	while (x <= y)
	{
		CirclePlot(image, xc, yc, x, y, value);
		if (d < 0)
		{
			d = d + 4 * x + 6;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}
void EllipsePlot(QImage *image, int xc, int yc, int x, int y, QRgb value)
{
	image->setPixel(xc + x, yc + y, value);
	image->setPixel(xc + x, yc - y, value);
	image->setPixel(xc - x, yc + y, value);
	image->setPixel(xc - x, yc - y, value);
}
void MidEll(QImage *image, QPointF cp, int a, int b, QRgb value)
{
	double xc, yc;
	xc = cp.x();
	yc = cp.y();
	double x = 0, y = b;
	double aa = a * a, bb = b * b;
	double d = (int)(bb + aa * (-b + 0.25) + 0.5);    //初始值
	EllipsePlot(image, xc, yc, x, y, value);
	while (bb*x < aa*y)                     //四分之一圆的上半部分
	{
		if (d < 0)
		{
			d += bb * (2 * x + 3);
			x++;
		}
		else
		{

			d += bb * (2 * x + 3) + aa * (-2 * y + 2); y--; x++;
		}
		EllipsePlot(image, xc, yc, x, y, value);
	}
	d = (int)(bb*(x + 0.5)*(x + 0.5) + aa * (y - 1)*(y - 1) - aa * bb + 0.5);
	while (y > 0)
	{                                //四分之一圆的下半部分
		if (d > 0)
		{
			d += aa * (-2 * y + 3);
			y--;
		}
		else
		{
			d += bb * (2 * x + 2) + aa * (-2 * y + 3);
			x++; y--;
		}
		EllipsePlot(image, xc, yc, x, y, value);
	}
}
void WuPlot(QImage *image, QPointF bp, QPointF ep, QRgb value)
{
	QPointF temp;
	double ax, ay;
	double dx = ep.x() - bp.x();
	double dy = ep.y() - bp.y();
	double k = (dy*1.00) / (dx*1.00);//计算斜率
	if (dx == 0)//垂线
	{
		if (dy < 0)//起点在上方，调换
		{
			temp = bp;
			bp = ep;
			ep = temp;
		}
		for (ay = bp.y(), ax = bp.x(); ay < ep.y(); ay++)//主移动方向->y,不包括p1
		{
			image->setPixel(ax, ay, qRgb(0, 0, 0));
		}
	}
	else
	{
		double e = 0.00;//增量

		if (k >= 0 && k <= 1)
		{
			if (dx < 0)//p1在左侧，调换
			{
				temp = bp;
				bp = ep;
				ep = temp;
			}//p0在左下
			for (ay = bp.y(), ax = bp.x(); ax < ep.x(); ax++)//主移动方向->x,不包括p1
			{
				image->setPixel(ax, ay, qRgb(e * 255, e * 255, e * 255));
				image->setPixel(ax, ay + 1, qRgb((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
				e += k;

				if (e >= 1.0)
				{
					ay++;
					e -= 1;
				}
			}
		}
		else if (k > 1)
		{
			if (dy < 0)//p1在左侧，调换
			{
				temp = bp;
				bp = ep;
				ep = temp;
			}//p0在下方
			for (ay = bp.y(), ax = bp.x(); ay < ep.y(); ay++)//主移动方向->y,不包括p1
			{
				image->setPixel(ax, ay, qRgb(e * 255, e * 255, e * 255));
				image->setPixel(ax + 1, ay, qRgb((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
				e += 1.00 / (k*1.00);

				if (e >= 1.0)
				{
					ax++;
					e -= 1;
				}
			}
		}

		else if (k >= -1 && k < 0)
		{
			e = 0.00;
			if (dx < 0)//p1在左上，调换
			{
				temp = bp;
				bp = ep;
				ep = temp;
			}//p0在左上
			for (ay = bp.y(), ax = bp.x(); ax < ep.x(); ax++)//主移动方向->x,不包括p1
			{
				image->setPixel(ax, ay, qRgb(-1 * e * 255, -1 * e * 255, -1 * e * 255));
				image->setPixel(ax, ay - 1, qRgb((1 + e) * 255, (1 + e) * 255, (1 + e) * 255));
				e += k;

				if (e <= -1.0)
				{
					ay--;
					e += 1.0;
				}
			}
		}

		else if (k < -1)
		{
			if (dy > 0)//p1在上方，调换
			{
				temp = bp;
				bp = ep;
				ep = temp;
			}//p0在上
			for (ay = bp.y(), ax = bp.x(); ay < ep.y(); ay--)//主移动方向->y,不包括p1
			{
				image->setPixel(ax, ay, qRgb(e * 255, e * 255, e * 255));
				image->setPixel(ax + 1, ay, qRgb((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
				e += -1.0 / (k*1.0);

				if (e >= 1.0)
				{
					ax++;
					e -= 1;
				}
			}
		}
	}
}
void ScanLineFill(QImage *image, QPointF *point, QRgb value, int mlength)
{
	double  *x,*y;//顶点坐标动态数组
	x = new double[mlength];//创建一维动态数组
	y = new double[mlength];//创建一维动态数组
	for (int i = 0; i < mlength; i++)
	{
		x[i] = point[i].x();
		y[i] = point[i].y();
	}
	int N = 9;
	int n = 0;
	double suitable_x[10];
	double min_y = FindMin(y, N), max_y = FindMax(y, N);
	for (int now_y = min_y; now_y <= max_y; now_y++)
	{
		SuitableX(x, y, N, now_y, suitable_x, n);
		SortMintoMax(suitable_x, n); //从小到大排序
		for (int i = 0; i < n; i += 2)
		{
			for (int now_x = suitable_x[i]; now_x < suitable_x[i + 1]; now_x++)//确定在扫描线上，要填充的范围
			{
				image->setPixel(now_x, now_y, value);
			}
		}
	}
	delete[] x;
	delete[] y;
}
void SuitableX(double *x, double *y, int N, double now_y, double *suitable_x, int &n)
{
	n = 0;
	int t = 0;
	double k, b;
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			if (y[i] < now_y&& now_y <= y[0] || y[0] < now_y&& now_y <= y[i])//判断直线是否过最后一条直线
			{
				Functionline(x[0], y[0], x[i], y[i], k, b);
				suitable_x[t++] = SolveX(k, b, now_y);
			}
		}
		else
		{
			if (y[i] < now_y&& now_y <= y[i + 1] || y[i + 1] < now_y&& now_y <= y[i]) //判断扫描线过哪条直线的范围
			{
				Functionline(x[i], y[i], x[i + 1], y[i + 1], k, b);
				suitable_x[t++] = SolveX(k, b, now_y);//把交点的x储存在suitable_x[]中
			}
		}
	}
	n = t;
}
void EdgeFill(QImage *image, QPointF *point)
{
	CFill *cFill;
	cFill = new CFill;
	cFill->SetPoint(point, 9);
	cFill->CreateBucket();
	cFill->CreateEdge();
	cFill->Gouraud(image);
}
void RegionFill(QImage *image, QRgb value)
{
	queue<QPointF> q;
	GPolygon p;
	is_edge = p.is_edge;
	q.push(p.seed);
	while (!q.empty()) {
		QPointF tmp = q.front();
		q.pop();
		if (visited.count(get_pixel_index(tmp)) == 0) {
			visited[get_pixel_index(tmp)] = 1;
			if (is_edge.count(get_pixel_index(tmp)) == 0) {
				image->setPixel(tmp.x(), tmp.y(), value);
				q.push(QPointF(tmp.x() + 1, tmp.y()));
				q.push(QPointF(tmp.x() - 1, tmp.y()));
				q.push(QPointF(tmp.x(), tmp.y() - 1));
				q.push(QPointF(tmp.x(), tmp.y() + 1));
			}
			else {
				image->setPixel(tmp.x(), tmp.y(), value);
			}
		}
	}
}
// 假设 Mid 是绘制线段的函数，DrawTriangle 是绘制三角形的函数
void DrawTriangle(QImage* image, QPointF* point, QRgb value, int mlength)
{
	for (int i = 0; i < mlength; i++)
	{
		if (i == mlength - 1)
		{
			Mid(image, point[i].x(), point[i].y(), point[0].x(), point[0].y(), value);
		}
		else
		{
			Mid(image, point[i].x(), point[i].y(), point[i + 1].x(), point[i + 1].y(), value);
		}
	}
}

void Trans(QImage* image, QPointF* point, QRgb value, int mlength)
{
	GMatrix ThreeThreeMatrix(3, 3), ap(1, 3);//定义了两个 GMatrix 对象，创建了一个 3x3 的矩阵对象 和1*3矩阵对象
	GMatrix moveap(1, 3);
	ThreeThreeMatrix.SetTranslationValue(50, 100);//沿 x 轴正方向平移 50 单位，沿 y 轴正方向平移 100 单位

	// 平移点
	for (int i = 0; i < mlength; i++)
	{
		ap.SetoneThree(point[i].x(), point[i].y());
		moveap = ap * ThreeThreeMatrix;
		point[i].setX(moveap.GetX());
		point[i].setY(moveap.GetY());
	}

	// 绘制平移后的三角形
	DrawTriangle(image, point, value, mlength);
}
void Rot(QImage* image, QPointF* point, QRgb value, int mlength)
{
	// 创建一个 3x3 的变换矩阵，用于存储旋转矩阵
	GMatrix ThreeThreeMatrix(3, 3);

	// 创建一个 1x3 的矩阵，用于存储点的齐次坐标
	GMatrix ap(1, 3);

	// 创建一个 1x3 的矩阵，用于存储变换后的点的齐次坐标
	GMatrix moveap(1, 3);

	// 设置旋转矩阵，固定为 90 度
	ThreeThreeMatrix.SetRotateThree();

	// 遍历所有点，对每个点进行旋转变换
	for (int i = 0; i < mlength; i++)
	{
		// 设置当前点的齐次坐标
		ap.SetoneThree(point[i].x(), point[i].y());

		// 计算旋转后的点的齐次坐标
		moveap = ap * ThreeThreeMatrix;

		// 更新点的坐标为旋转后的坐标
		point[i].setX(moveap.GetX());
		point[i].setY(moveap.GetY());
	}

	// 遍历所有点，绘制旋转后的图形
	for (int i = 0; i < mlength; i++)
	{
		// 如果是最后一个点，连接到第一个点，形成闭合图形
		if (i == mlength - 1)
		{
			Mid(image, point[i].x(), point[i].y(), point[0].x(), point[0].y(), value);
		}
		else
		{
			// 连接当前点和下一个点，绘制线段
			Mid(image, point[i].x(), point[i].y(), point[i + 1].x(), point[i + 1].y(), value);
		}
	}
}
void Scale(QImage *image, QPointF *point, QRgb value, int mlength)
{
	GMatrix ThreeThreeMatrix(3, 3), ap(1, 3);
	GMatrix moveap(1, 3);
	ThreeThreeMatrix.SetScaleThree();
	for (int i = 0; i < mlength; i++)
	{
		ap.SetoneThree(point[i].x(), point[i].y());
		moveap = ap * ThreeThreeMatrix;
		point[i].setX(moveap.GetX());
		point[i].setY(moveap.GetY());
	}
	for (int i = 0; i < mlength; i++)
	{
		if (i == mlength - 1)
		{
			Mid(image, point[i].x(), point[i].y(), point[0].x(), point[0].y(), value);
		}
		else
		{
			Mid(image, point[i].x(), point[i].y(), point[i + 1].x(), point[i + 1].y(), value);
		}
	}
}
void CohenSutherlandClip(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value)
{
	int code1 = Encode(x1, y1, rect);
	int code2 = Encode(x2, y2, rect);
	QPointF p1, p2;
	p1.setX(x1);
	p1.setY(y1);
	p2.setX(x2);
	p2.setY(y2);
	while (code1 != 0 || code2 != 0)
	{
		//在直线之外，直接舍去，但是跨过三个区域的情况舍弃不了，需要在后面分割一次再分别舍去
		if ((code1 & code2) != 0)
			return;
		//处理大于上界的点
		if ((code1 & 8) != 0)
		{
			p1.setX(p1.x() - ((p1.y() - rect->ymax) * (p1.x() - p2.y()) / (p1.y() - p2.y())));
			p1.setY(rect->ymax);
			code1 = Encode(p1.x(), p1.y(), rect);
		}
		else if ((code2 & 8) != 0)
		{
			p2.setX(p2.x() - ((p2.y() - rect->ymax) * (p2.x() - p1.y()) / (p2.y() - p1.y())));
			p2.setY(rect->ymax);
			code2 = Encode(p2.x(), p2.y(), rect);
		}
		//处理小于下界的点
		else if ((code1 & 4) != 0)
		{
			p1.setX(p1.x() - ((p1.y() - rect->ymin) * (p1.x() - p2.x()) / (p1.y() - p2.y())));
			p1.setY(rect->ymin);
			code1 = Encode(p1.x(), p1.y(), rect);
		}
		else if ((code2 & 4) != 0)
		{
			p2.setX(p2.x() - ((p2.y() - rect->ymin) * (p2.x() - p1.x()) / (p2.y() - p1.y())));
			p2.setY(rect->ymin);
			code2 = Encode(p2.x(), p2.y(), rect);
		}
		//处理大于右界的点
		else if ((code1 & 2) != 0)
		{
			p1.setY(p1.y() - ((p1.x() - rect->xmax) * (p1.y() - p2.y()) / (p1.x() - p2.x())));
			p1.setX(rect->xmax);
			code1 = Encode(p1.x(), p1.y(), rect);
		}
		else if ((code2 & 2) != 0)
		{
			p2.setY(p2.y() - ((p2.x() - rect->xmax) * (p2.y() - p1.y()) / (p2.x() - p1.x())));
			p2.setX(rect->xmax);
			code2 = Encode(p2.x(), p2.y(), rect);
		}
		//处理小于左边界的点
		else if ((code1 & 1) != 0)
		{
			p1.setY(p1.y() - ((p1.x() - rect->xmin) * (p1.y() - p2.y()) / (p1.x() - p2.x())));
			p1.setX(rect->xmin);
			code1 = Encode(p1.x(), p1.y(), rect);
		}
		else if ((code2 & 1) != 0)
		{
			p2.setY(p2.y() - ((p2.x() - rect->xmin) * (p2.y() - p1.y()) / (p2.x() - p1.x())));
			p2.setX(rect->xmin);
			code2 = Encode(p2.x(), p2.y(), rect);
		}
	}
	Mid(image, p1.x(), p1.y(), p2.x(), p2.y(), value);
	Mid(image, rect->xmin, rect->ymin, rect->xmin, rect->ymax, value);
	Mid(image, rect->xmax, rect->ymin, rect->xmax, rect->ymax, value);
	Mid(image, rect->xmin, rect->ymin, rect->xmax, rect->ymin, value);
	Mid(image, rect->xmin, rect->ymax, rect->xmax, rect->ymax, value);
}
void Draw(QImage *image, Rectangle *rect, int x1, int y1, int x2, int y2, QRgb value)
{
	MidPointClip(rect, x1, y1, x2, y2);
	for (int i = 0; i < vector2.size(); ++i)
	{
		Mid(image, vector1[i].x(), vector1[i].y(), vector2[i].x(), vector2[i].y(), value);
	}
	Mid(image, rect->xmin, rect->ymin, rect->xmin, rect->ymax, value);
	Mid(image, rect->xmax, rect->ymin, rect->xmax, rect->ymax, value);
	Mid(image, rect->xmin, rect->ymin, rect->xmax, rect->ymin, value);
	Mid(image, rect->xmin, rect->ymax, rect->xmax, rect->ymax, value);
}
void MidPointClip(Rectangle *rect, int x1, int y1, int x2, int y2)
{
	int code1 = Encode(x1, y1, rect);
	int code2 = Encode(x2, y2, rect);
	QPointF p1, p2;
	QPointF pm1, pm2;
	p1.setX(x1);
	p1.setY(y1);
	p2.setX(x2);
	p2.setY(y2);
	if ((code1 & code2) != 0)
		return;
	if (code1 == 0 && code2 == 0)
	{
		vector1.push_back(p1);
		vector2.push_back(p2);
	}
	else
	{
		if (code1 == 0)
		{
			pm1.setX(x1);
			pm1.setY(y1);
			pm2.setX(findIntersection(p1, p2, rect).x());
			pm2.setY(findIntersection(p1, p2, rect).y());
			vector1.push_back(pm1);
			vector2.push_back(pm2);
		}
		else if (code2 == 0)
		{
			pm1.setX(findIntersection(p1, p2, rect).x());
			pm1.setY(findIntersection(p1, p2, rect).y());
			pm2.setX(x2);
			pm2.setY(y2);
			vector1.push_back(pm1);
			vector2.push_back(pm2);
		}
		else
		{
			QPointF tp;
			tp.setX((p1.x() + p2.x()) / 2);
			tp.setY((p1.y() + p2.y()) / 2);
			pm1.setX(x1);
			pm1.setY(y1);
			pm2.setX(x2);
			pm2.setY(y2);
			MidPointClip(rect, p1.x(), p1.y(), tp.x(), tp.y());
			MidPointClip(rect, tp.x(), tp.y(), p2.x(), p2.y());
		}
	}
}
QPointF findIntersection(QPointF p1, QPointF p2, Rectangle *rect)
{
	QPointF pmid;
	pmid.setX((p1.x() + p2.x()) / 2);
	pmid.setY((p1.y() + p2.y()) / 2);
	if (Distance(pmid, p1) < 1.5)
		return pmid;

	int code1 = Encode(p1.x(), p1.y(), rect);
	int code2 = Encode(p2.x(), p2.y(), rect);
	int codemid = Encode(pmid.x(), pmid.y(), rect);
	if (code1 == 0)
		if (codemid == 0)
			return findIntersection(pmid, p2, rect);
		else
			return findIntersection(p1, pmid, rect);
	if (code2 == 0)
		if (codemid == 0)
			return findIntersection(pmid, p1, rect);
		else
			return findIntersection(p2, pmid, rect);
	return pmid;
}
int LBLineClipTest(float p, float q, float& umax, float& umin)
{
	float r = 0.0;
	if (p < 0.0) {
		r = q / p;
		if (r > umin) {
			return 0;
		}
		else if (r > umax) {
			umax = r;
		}
	}
	else if (p > 0.0) {
		r = q / p;
		if (r < umax) {
			return 0;
		}
		else if (r < umin) {
			umin = r;
		}
	}
	else if (q < 0.0) {
		return 0;
	}
	return 1;
}
void LBLineClip(QImage *image, Rectangle *rect, float x1, float y1, float x2, float y2, QRgb value)
{
	float umax, umin, deltax, deltay, xx2, yy2, xx1, yy1;
	float xwl, xwr, ywb, ywt;
	xwl = float(rect->xmin);
	xwr = float(rect->xmax);
	ywb = float(rect->ymin);
	ywt = float(rect->ymax);
	deltax = x2 - x1;
	deltay = y2 - y1;
	umax = 0.0;
	umin = 1.0;
	if (LBLineClipTest(-deltax, x1 - xwl, umax, umin))
	{
		if (LBLineClipTest(deltax, xwr - x1, umax, umin))
		{
			if (LBLineClipTest(-deltay, y1 - ywb, umax, umin))
			{
				if (LBLineClipTest(deltay, ywt - y1, umax, umin))
				{
					xx1 = int(x1 + umax * deltax + 0.5);
					yy1 = int(y1 + umax * deltay + 0.5);
					xx2 = int(x1 + umin * deltax + 0.5);
					yy2 = int(y1 + umin * deltay + 0.5);
				}
				Mid(image, xx1, yy1, xx2, yy2, value);
			}
		}
	}
	Mid(image, rect->xmin, rect->ymin, rect->xmin, rect->ymax, value);
	Mid(image, rect->xmax, rect->ymin, rect->xmax, rect->ymax, value);
	Mid(image, rect->xmin, rect->ymin, rect->xmax, rect->ymin, value);
	Mid(image, rect->xmin, rect->ymax, rect->xmax, rect->ymax, value);
}
void drawbz2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value, double delta_t)
{
	double  f1, f2, f3;
	for (float i = 0; i <= 1; i += delta_t)
	{
		f1 = (1 - i) * (1 - i);
		f2 = 2 * (1 - i) * i;
		f3 = i * i;
		float x = f1 * c1.x() + f2 * c2.x() + f3 * c3.x();
		float y = f1 * c1.y() + f2 * c2.y() + f3 * c3.y();
		image->setPixel(x, y, value);
	}
}
void drawbz3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value,double delta_t)
{
	double  f1, f2, f3, f4;
	for (float i = 0; i <= 1; i += delta_t)
	{
		f1 = (1 - i) * (1 - i) * (1 - i);
		f2 = 3 * (1 - i) * (1 - i) * i;
		f3 = 3 * (1 - i) * i * i;
		f4 = i * i * i;
		float x = f1 * c1.x() + f2 * c2.x() + f3 * c3.x() + f4 * c4.x();
		float y = f1 * c1.y() + f2 * c2.y() + f3 * c3.y() + f4 * c4.y();
		image->setPixel(x, y, value);
	}
}
void drawBSpline2(QImage *image, QPointF c1, QPointF c2, QPointF c3, QRgb value, double delta_t)
{
	for (float i = 0; i <= 1; i += delta_t)
	{
		float x, y;
		float F0, F1, F2;
		F0 = 0.5 * (i * i - 2 * i + 1);
		F1 = 0.5 * (-2 * i * i + 2 * i + 1);
		F2 = 0.5 * i * i;
		x = F0 * c1.x() + F1 * c2.x() + F2 * c3.x();
		y = F0 * c1.y() + F1 * c3.y() + F2 * c3.y();
		image->setPixel(x, y, value);
	}
}
void drawBSpline3(QImage *image, QPointF c1, QPointF c2, QPointF c3, QPointF c4, QRgb value, double delta_t)
{
	for (float i = 0; i <= 1; i += delta_t)
	{
		float x, y;
		float F0, F1, F2, F3;
		F0 = (-1 * i * i * i + 3 * i * i - 3 * i + 1)/6.0;
		F1 = (3 * i * i * i - 6 * i * i  + 4) / 6.0;
		F2 = (-3 * i * i * i + 3 * i * i + 3 * i + 1) / 6.0;
		F3 = ( i * i * i ) / 6.0;
		x = F0 * c1.x() + F1 * c2.x() + F2 * c3.x() + F3 * c4.x();
		y = F0 * c1.y() + F1 * c3.y() + F2 * c3.y() + F3 * c4.y();
		image->setPixel(x, y, value);
	}
}
