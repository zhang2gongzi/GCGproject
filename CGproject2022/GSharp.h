#ifndef _GSHARP_H
#define _GSHARP_H
const int W = 400;
#include<vector>
#include<algorithm>
#include<map>
#include <QPoint>
using namespace std;
class CAET
{
public:
	CAET() {}
	virtual ~CAET() {}
public:
	double  x;//当前扫描线与有效边交点的x坐标
	int     yMax;//边的最大y值
	double  k;//斜率的倒数(x的增量)
	CAET   *pNext;
};
class CBucket
{
public:
	CBucket() {}
	virtual ~CBucket() {}
public:
	int     ScanLine;     //扫描线
	CAET    *pET;         //桶上的边表指针
	CBucket *pNext;
};

class GEdge 
{
public:
	GEdge::GEdge()
	{

	}
private:
	QPointF gbegin;
	QPointF gend;
	GEdge(QPointF px, QPointF py)
	{
		gbegin.setX(px.x());
		gbegin.setY(px.y());
	}
};
class GPolygon 
{
public:
	std::vector<GEdge> edge_v;
	std::map<int, bool> is_edge;
	QPointF seed; 
	GPolygon() 
	{
		polygen_init();
		seed = QPointF(140, 150);
	}
	void insert_edge(QPointF px, QPointF py)
	{
		
		DDL_init(px.x(), px.y(), py.x(), py.y());
	}
	void DDL_init_x(int x1, int y1, int x2, int y2) 
	{
		int index;
		double k = (y2 - y1) *1.0 / (x2 - x1);
		double now_y = y1;
		for (int x = x1; x <= x2; x++) 
		{
			int y = int(now_y + 0.5);
			index = y * W + x;
			is_edge[index] = 1;
			now_y += k;
		}

	}
	void DDL_init_y(int x1, int y1, int x2, int y2) 
	{
		int index;
		double k = (x2 - x1) *1.0 / (y2 - y1);
		double now_x = x1;
		for (int y = y1; y <= y2; y++) {
			int x = int(now_x + 0.5);
			index = y * W + x;
			is_edge[index] = 1;
			now_x += k;
		}
	}
	void DDL_init(int x1, int y1, int x2, int y2) 
	{
		double k = (y2 - y1) *1.0 / (x2 - x1);
		if (fabs(k) <= 1) {
			if (x1 < x2) {
				DDL_init_x(x1, y1, x2, y2);
			}
			else {
				DDL_init_x(x2, y2, x1, y1);
			}
		}
		else {
			if (y1 < y2) {
				DDL_init_y(x1, y1, x2, y2);
			}
			else {
				DDL_init_y(x2, y2, x1, y1);
			}
		}
	}
	void polygen_init() 
	{
		insert_edge(QPointF(120, 120), QPointF(150, 110));
		insert_edge(QPointF(150, 110), QPointF(210, 130));
		insert_edge(QPointF(210, 30), QPointF(210, 180));
		insert_edge(QPointF(210, 180), QPointF(150, 150));
		insert_edge(QPointF(150, 150), QPointF(120, 170));
		insert_edge(QPointF(120, 170), QPointF(120, 120));
	}
};
struct Rectangle
{
	int xmin, xmax;
	int ymin, ymax;
};
#endif // !_GSHARP_H